#ifndef NWNXNeo4j_H_
#define NWNXNeo4j_H_

#include "NWNXBase.h"
#include <boost/asio.hpp>

using namespace std;

class CNWNXNeo4j: public CNWNXBase {
public:
    virtual ~CNWNXNeo4j();

    bool OnCreate(gline *config, const char* LogDir);
    char* OnRequest(char* gameObject, char* Request, char* Parameters);
    bool OnRelease();

protected:
    bool LoadConfiguration();
    char *Query(char *arguments);
    // void Fetch(char* buffer, unsigned int buffersize);


private:
    struct ConnectionParameters {
        std::string hostname;
        int port;
        std::string username;
        std::string password;
    } connectionParameters;
};

#endif
