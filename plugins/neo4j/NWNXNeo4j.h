#ifndef NWNXNeo4j_H_
#define NWNXNeo4j_H_

#include "NWNXBase.h"
#include <neo4j-client.h>

using namespace std;

class CNWNXNeo4j: public CNWNXBase {
public:
    virtual ~CNWNXNeo4j();

    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();

protected:
    bool Connect();
    void Disconnect();
    bool LoadConfiguration();
    void Exec(char *query);
    char *Fetch(char *buffer, unsigned int bufferSize);

private:
    struct ConnectionParameters {
        std::string hostname;
        int port;
        std::string username;
        std::string password;
    } connectionParameters;

    neo4j_connection_t *connection;
    neo4j_result_stream_t *results;
};

#endif
