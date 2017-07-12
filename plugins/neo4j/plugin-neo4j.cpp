#include "NWNXNeo4j.h"

CNWNXNeo4j neo4j;

extern "C" {
    CNWNXBase* GetClassObject()
    {
        return &neo4j;
    }
}
