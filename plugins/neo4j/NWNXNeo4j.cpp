#include "NWNXNeo4j.h"

CNWNXNeo4j::CNWNXNeo4j() {
    logLevel = logAll;
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

    return Connect();
}

bool CNWNXNeo4j::Connect() {
    return true;
}

char* CNWNXNeo4j::OnRequest(char* gameObject, char* request, char* arguments) {
    Log(2, "Request: \"%s\"\n", request);
    Log(3, "Arguments:  \"%s\"\n", arguments);

    if (strcmp(request, "QUERY") == 0) {
        Query(arguments);
    } else if (strcmp(request, "FETCH") == 0) {
        Fetch(arguments, strlen(arguments));
    }

    return null;
}

bool CNWNXNeo4j::OnRelease () {
    return CNWNXBase::OnRelease();
}

void CNWNXNeo4j::Query(const char *request) {
    // Try to run the Neo4j Cypher query.
}

void CNWNXNeo4j::Fetch(char *buffer, unsigned int bufferSize) {
    // Fetch the Neo4j response. Start with primitives!
}
