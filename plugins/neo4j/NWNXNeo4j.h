#ifndef NWNXNeo4j_H_
#define NWNXNeo4j_H_

#include "NWNXBase.h"
#include <neo4j-client.h>
#include <exception>
#include <sstream>
#include <vector>

using namespace std;

class CNWNXNeo4j: public CNWNXBase {
public:
    CNWNXNeo4j();
    ~CNWNXNeo4j();

    bool OnCreate(gline *config, const char* logDirectory);
    char* OnRequest(char* gameObject, char* request, char* arguments);
    bool OnRelease();

protected:
    bool Connect();
    void Disconnect();
    bool LoadConfiguration();
    void Exec(char *query);
    char* FetchRecord();
    char* Fetch();

private:
    struct PARAMETERS {
        char* hostname;
        char* port;
        char* username;
        char* password;
    } p;

    neo4j_connection_t* connection;
    neo4j_result_stream_t* results;
    vector<char*> records;
    vector<char*>::iterator recordsIterator;
};

#endif
