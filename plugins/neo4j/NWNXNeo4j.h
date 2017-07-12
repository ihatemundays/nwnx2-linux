#ifndef NWNXNeo4j_H_
#define NWNXNeo4j_H_

#include "NWNXBase.h"

class CNWNXNeo4j: public CNWNXBase {
public:
    CNWNXNeo4j();
    virtual ~CNWNXNeo4j();

    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();

protected:
    bool Connect();
    void Query(const char* request);
    void Fetch(char* buffer, unsigned int buffersize);
    bool LoadConfiguration();

private:
    struct PARAMETERS {
        char *hostname;
        char *port;
        char *username;
        char *password;
    } parameters;

    enum LogLevel {logNone, logErrors, logAll};
    int logLevel;
};

#endif
