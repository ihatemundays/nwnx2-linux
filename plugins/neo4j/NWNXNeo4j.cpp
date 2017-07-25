#include "NWNXNeo4j.h"

CNWNXNeo4j::CNWNXNeo4j() {
    confKey = "NEO4J";
    memset(p, 0, sizeof(PARAMETERS));
}

CNWNXNeo4j::~CNWNXNeo4j() {
    Disconnect();

    OnRelease();
}

bool CNWNXNeo4j::OnCreate(gline *config, const char* logDirectory)
{
    char log[128];

    sprintf(log, "%s/nwnx_neo4j.txt", LogDir);
    if (!CNWNXBase::OnCreate(nwnxConfig, log))
        return false;

    Log(0, "NWNX Neo4j V.1.0\n");
    Log(0, "(c) 2017 by Wayne Chipchase / Scott Munday\n");
    Log(0, "* Module loaded successfully.\n");

    if (!LoadConfiguration()) {
        return false;
    }

    if (!Connect()) {
        return false;
    }

    return true;
}

bool CNWNXNeo4j::LoadConfiguration() {
    try {
        if (!nwnxConfig->exists(confKey)) {
            Log(0, "o Critical Error: Section [%s] not found in nwnx2.ini.\n", confKey);

            return false;
        }

        p.hostname = strdup((char*)((*nwnxConfig)[confKey]["hostname"].c_str()));
        p.port = strdup((char*)((*nwnxConfig)[confKey]["port"].c_str()));
        p.username = strdup((char*)((*nwnxConfig)[confKey]["username"].c_str()));
        p.password = strdup((char*)((*nwnxConfig)[confKey]["password"].c_str()));

        return true;
    } catch (std::exception const& exception) {
        cout << exception.getMessage();

        return false;
    }
}

bool CNWNXNeo4j::Connect() {
    try {
        neo4j_client_init();

        neo4j_config_t *config = neo4j_new_config();

        if (config == NULL) {
            throw std::exception("Unable to create neo4j configuration.");
        }

        if (neo4j_config_set_username(config, p.username)) {
            throw std::exception("Unable to set username");
        }

        if (neo4j_config_set_password(config, p.password)) {
            throw std::exception("Unable to set password");
        }

        connection = neo4j_connect("neo4j://" + p.hostname + ':' + p.port,
                                   config,
                                   NEO4J_INSECURE);

        if (connection == NULL) {
            Log(0, "o Connection failed.\n");

            return false;
        }

        return true;
    } catch (std::exception const& exception) {
        cout << exception.getMessage();

        return false;
    }
}

void CNWNXNeo4j::Disconnect() {
    if (results != NULL) {
        neo4j_close_results(results);
    }

    if (connection != NULL) {
        neo4j_close(connection);
    }

    neo4j_client_cleanup();
}

char* CNWNXNeo4j::OnRequest(char* gameObject, char* request, char* arguments) {
    Log(2, "Request: \"%s\"\n", request);
    Log(3, "Arguments:  \"%s\"\n", arguments);

    if (strcmp(request, "EXEC") == 0) {
        Exec(arguments);
    } else if (strcmp(request, "FETCH") == 0) {
        return Fetch(arguments, strlen(arguments));
    }

    return NULL;
}

bool CNWNXNeo4j::OnRelease () {
    return CNWNXBase::OnRelease();
}

void CNWNXNeo4j::Exec(char *query) {
    Disconnect();
    if (!Connect()) {
        return;
    }

    results = neo4j_run(connection, query, neo4j_null);
    if (results == NULL) {
        Log(1, "Failed to run statement.");

        return;
    }
}

char *CNWNXNeo4j::Fetch(char *buffer, unsigned int bufferSize) {
    if (results == NULL) {
        Log(1, "Failed to fetch result.");

        return NULL;
    }

    neo4j_result_t *result = neo4j_fetch_next(results);
    if (result == NULL) {
        return NULL;
    }

    std::stringstream ss;
    for (int i = 0; i < neo4j_nfields(results); ++i) {
        char resultBuffer[1024];

        if (i != 0) {
            ss << '�';
        }

        neo4j_ntostring(neo4j_result_field(result, i), resultBuffer, 256);
        ss << resultBuffer;
    }

    return (char*)ss.str().c_str();
}
