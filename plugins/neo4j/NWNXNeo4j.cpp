#include "NWNXNeo4j.h"

CNWNXNeo4j::~CNWNXNeo4j() {
    Disconnect();

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

    if (!Connect()) {
        return false;
    }

    Disconnect();

    return true;
}

bool CNWNXNeo4j::LoadConfiguration() {
    if (!nwnxConfig->exists(confKey)) {
        Log(0, "o Critical Error: Section [%s] not found in nwnx2.ini.\n", confKey);

        return false;
    }

    connectionParameters.hostname = (char*)((*nwnxConfig)[confKey]["hostname"].c_str());
    connectionParameters.port = (int)((*nwnxConfig)[confKey]["port"].c_str());
    connectionParameters.username = (char*)((*nwnxConfig)[confKey]["username"].c_str());
    connectionParameters.password = (char*)((*nwnxConfig)[confKey]["password"].c_str());

    return true;
}

bool CNWNXNeo4j::Connect() {
    neo4j_client_init();

    connection = neo4j_connect("neo4j://" + connectionParameters.hostname + ':' + connectionParameters.port,
                               NULL,
                               NEO4J_INSECURE);

    if (connection == NULL) {
        Log(0, "o Connection failed.\n");

        return false;
    }

    return true;
}

void CWNNXNeo4j::Disconnect() {
    if (results != NULL) {
        neo4j_close_results(results);
    }

    if (connection != NULL) {
        neo4j_close_connection(connection);
    }

    neo4j_client_cleanup();
}

char* CNWNXNeo4j::OnRequest(char* gameObject, char* request, char* arguments) {
    Log(2, "Request: \"%s\"\n", request);
    Log(3, "Arguments:  \"%s\"\n", arguments);

    if (strcmp(request, "EXEC") == 0) {
        Query(arguments);
    } else if (strcmp(request, "FETCH") == 0) {
        return Fetch(arguments, strlen(arguments));
    }

    return NULL;
}

bool CNWNXNeo4j::OnRelease () {
    return CNWNXBase::OnRelease();
}

void CNWNXNeo4j::Query(char *query) {
    Disconnect();
    if (!Connect()) {
        return;
    }

    results = neo4j_run(connection, arguments, neo4j_null);
    if (results == NULL) {
        Log(1, "Failed to run statement.");

        return;
    }
}

char *CWNNXNeo4j::Fetch(char *buffer, unsigned int bufferSize) {
    if (results == NULL) {
        Log(1, "Failed to fetch result.");

        return NULL;
    }

    neo4j_result_t *result = neo4j_fetch_next(results);
    if (result == NULL) {
        return NULL;
    }

    std::stringstream result;
    for (int i = 0; i < neo4j_nfields(results); ++i) {
        if (i != 0) {
            ss << "�";
        }

        ss << v[i];
    }

    return (char*)ss.c_str();
}
