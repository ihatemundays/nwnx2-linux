#include "NWNXNeo4j.h"

CNWNXNeo4j neo4j;
PLUGINLINK *pluginLink = 0;

PLUGININFO pluginInfo = {
        sizeof(PLUGININFO),
        "NWNXNeo4j",
        PLUGIN_MAKE_VERSION(0, 0, 0, 1),
        "",
        "Wayne Chipchase / Scott Munday",
        "",
        "MIT",
        "",
        0
};

extern "C" PLUGININFO* GetPluginInfo(DWORD nwnxVersion)
{
    return &pluginInfo;
}

extern "C" int InitPlugin(PLUGINLINK *link)
{
    pluginLink = link;

    return 0;
}

extern "C"
CNWNXBase* GetClassObject()
{
    return &neo4j;
}
