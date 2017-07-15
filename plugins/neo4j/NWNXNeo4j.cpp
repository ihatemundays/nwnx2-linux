#include "NWNXNeo4j.h"

static const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                "abcdefghijklmnopqrstuvwxyz"
                "0123456789+/";


static inline bool is_base64(unsigned char c) {
    return (isalnum(c) || (c == '+') || (c == '/'));
}

std::string base64_encode(unsigned char const* bytes_to_encode, unsigned int in_len) {
    std::string ret;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    while (in_len--) {
        char_array_3[i++] = *(bytes_to_encode++);
        if (i == 3) {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for(i = 0; (i <4) ; i++)
                ret += base64_chars[char_array_4[i]];
            i = 0;
        }
    }

    if (i)
    {
        for(j = i; j < 3; j++)
            char_array_3[j] = '\0';

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
        char_array_4[3] = char_array_3[2] & 0x3f;

        for (j = 0; (j < i + 1); j++)
            ret += base64_chars[char_array_4[j]];

        while((i++ < 3))
            ret += '=';

    }

    return ret;

}
std::string base64_decode(std::string const& encoded_string) {
    int in_len = encoded_string.size();
    int i = 0;
    int j = 0;
    int in_ = 0;
    unsigned char char_array_4[4], char_array_3[3];
    std::string ret;

    while (in_len-- && ( encoded_string[in_] != '=') && is_base64(encoded_string[in_])) {
        char_array_4[i++] = encoded_string[in_]; in_++;
        if (i ==4) {
            for (i = 0; i <4; i++)
                char_array_4[i] = base64_chars.find(char_array_4[i]);

            char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
            char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
            char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

            for (i = 0; (i < 3); i++)
                ret += char_array_3[i];
            i = 0;
        }
    }

    if (i) {
        for (j = i; j <4; j++)
            char_array_4[j] = 0;

        for (j = 0; j <4; j++)
            char_array_4[j] = base64_chars.find(char_array_4[j]);

        char_array_3[0] = (char_array_4[0] << 2) + ((char_array_4[1] & 0x30) >> 4);
        char_array_3[1] = ((char_array_4[1] & 0xf) << 4) + ((char_array_4[2] & 0x3c) >> 2);
        char_array_3[2] = ((char_array_4[2] & 0x3) << 6) + char_array_4[3];

        for (j = 0; (j < i - 1); j++) ret += char_array_3[j];
    }

    return ret;
}

CNWNXNeo4j::~CNWNXNeo4j() {
    OnRelease();
}

bool CNWNXNeo4j::OnCreate(gline *config, const char* LogDir)
{
    char log[128];
    sprintf(log, "%s/nwnx_neo4j.txt", LogDir);
    if (!CNWNXBase::OnCreate(config, log))
        return false;

    Log(0, "NWNX Neo4j V.1.0\n");
    Log(0, "(c) 2017 by Wayne Chipchase / Scott Munday\n");
    Log(0, "* Module loaded successfully.\n");

    if (!LoadConfiguration()) {
        return false;
    }

    return true;
}

bool CNWNXNeo4j::LoadConfiguration() {
    if (!nwnxConfig->exists(confKey)) {
        Log(0, "o Critical Error: Section [%s] not found in nwnx2.ini\n", confKey);

        return false;
    }

    connectionParameters.hostname = (char*)((*nwnxConfig)[confKey]["hostname"].c_str());
    connectionParameters.port = (int)((*nwnxConfig)[confKey]["port"].c_str());
    connectionParameters.username = (char*)((*nwnxConfig)[confKey]["username"].c_str());
    connectionParameters.password = (char*)((*nwnxConfig)[confKey]["password"].c_str());

    return true;
}

char* CNWNXNeo4j::OnRequest(char* gameObject, char* request, char* arguments) {
    Log(2, "Request: \"%s\"\n", request);
    Log(3, "Arguments:  \"%s\"\n", arguments);

    if (strcmp(request, "QUERY") == 0) {
        return Query(arguments);
    }

    return NULL;
}

bool CNWNXNeo4j::OnRelease () {
    return CNWNXBase::OnRelease();
}

char *CNWNXNeo4j::Query(char *arguments) {
    using namespace boost::asio;

    // what we need
    io_service svc;
    ip::tcp::socket sock(svc);
    ip::tcp::endpoint endpoint(ip::address::from_string(connectionParameters.hostname), connectionParameters.port);
    sock.connect(endpoint);

    std::string credentials = connectionParameters.username + ':' + connectionParameters.password;
    std::string encryptedCredentials = base64_encode(reinterpret_cast<const unsigned char*>(credentials.c_str()), credentials.length())

    // Send query.
    std::string request("POST /db/data/cypher HTTP/1.1\n"
                        "Accept: application/json\n"
                        "Content-Type: application/json\n"
                        "Authorization: Basic " + encryptedCredentials + "\n"
                        "Cache-Control: no-cache\n"
                        "\n"
                        "{\n"
                        "\t\"query\": \"MATCH (n) RETURN n\"\n"
                        "}");
    sock.send(buffer(request));

    // Get response.
    std::string response = "";

    boost::system::error_code ec;
    do {
        char buf[1024];
        size_t bytes_transferred = sock.receive(buffer(buf), {}, ec);
        if (!ec) response.append(buf, buf + bytes_transferred);
    } while (!ec);

    return (char *)response.c_str();
}
