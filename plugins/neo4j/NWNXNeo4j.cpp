#include "NWNXNeo4j.h"

CNWNXNeo4j::CNWNXNeo4j() {
    confKey = "NEO4J";
    memset(&p, 0, sizeof(PARAMETERS));
}

CNWNXNeo4j::~CNWNXNeo4j() {
    OnRelease();
}

bool CNWNXNeo4j::OnCreate(gline *config, const char* logDirectory) {
    try {
        char log[128];

        sprintf(log, "%s/nwnx_neo4j.txt", logDirectory);
        if (!CNWNXBase::OnCreate(config, log)) {
            return false;
        }

        Log(0, "NWNX Neo4j V.1.0\n");
        Log(0, "(c) 2017 by Wayne Chipchase / Scott Munday\n");
        Log(0, "* Module loaded successfully.\n");

        if (!LoadConfiguration()) {
            return false;
        }

        return true;
    } catch (exception const& error) {
        cerr << "Unable to create Neo4j plugin. " << error.what() << endl;
    }
}

bool CNWNXNeo4j::LoadConfiguration() {
    try {
        if (nwnxConfig == NULL) {
            throw runtime_error("Configuration is not available.");
        }

        if (!nwnxConfig->exists(confKey)) {
            stringstream ss;

            ss << "Section [" << confKey << "] not found in nwnx2.ini";

            throw runtime_error(ss.str());
        }

        p.hostname = strdup((char*)((*nwnxConfig)[confKey]["hostname"].c_str()));
        p.port = strdup((char*)((*nwnxConfig)[confKey]["port"].c_str()));
        p.username = strdup((char*)((*nwnxConfig)[confKey]["username"].c_str()));
        p.password = strdup((char*)((*nwnxConfig)[confKey]["password"].c_str()));

        cout << "Neo4j URL: neo4j://" << p.hostname << ":" << p.port << endl;
        cout << "Credentials: " << p.username << ":" << p.password << endl;

        return true;
    } catch (exception const& error) {
        cerr << "Error loading configuration. " << error.what() << endl;

        return false;
    }
}

bool CNWNXNeo4j::Connect() {
    try {
        neo4j_client_init();

        neo4j_config_t *config = neo4j_new_config();

        if (config == NULL) {
            throw runtime_error("Unable to create neo4j configuration.");
        }

        if (neo4j_config_set_username(config, p.username)) {
            throw runtime_error("Unable to set username.");
        }

        if (neo4j_config_set_password(config, p.password)) {
            throw runtime_error("Unable to set password.");
        }

        char connectionString[256];

        sprintf(connectionString, "neo4j://%s:%s", p.hostname, p.port);

        connection = neo4j_connect(connectionString, config, NEO4J_INSECURE);

        if (connection == NULL) {
            throw runtime_error("Unable to connect to server.");
        }

        cout << "Connected to Neo4j." << endl;

        return true;
    } catch (exception const& error) {
        cerr << "Error connecting client to Neo4j server. " << error.what() << endl;

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

    cout << "Disconnected from Neo4j." << endl;
}

char* CNWNXNeo4j::OnRequest(char* gameObject, char* request, char* arguments) {
    try {
        cout << "Request: " << request << endl;
        cout << "Arguments: " << arguments << endl;

        if (strncmp(request, "EXEC", 4) == 0) {
            cout << "Executing Neo4j query..." << endl;

            Exec(arguments);
        } else if (strncmp(request, "FETCH", 5) == 0) {
            cout << "Fetching Neo4j result..." << endl;

            return Fetch();
        }

        return NULL;
    } catch (exception const& error) {
        cerr << "Error on Neo4j request. " << error.what() << endl;
    }
}

bool CNWNXNeo4j::OnRelease () {
    Disconnect();

    return true;
}

void CNWNXNeo4j::Exec(char *query) {
    records.clear();

    if (!Connect()) {
        neo4j_perror(stderr, errno, "Failed to connect");

        return;
    }

    results = neo4j_run(connection, query, neo4j_null);
    if (results == NULL) {
        neo4j_perror(stderr, errno, "Failed to execute query");

        return;
    }

    char* record;
    while ((record = FetchRecord()) != NULL) {
        cout << "Record: " << record << endl;

        records.push_back(record);
    }

    recordsIterator = records.begin();

    Disconnect();

    cout << "Neo4j query executed successfully." << endl;
}

char* CNWNXNeo4j::FetchRecord() {
    if (results == NULL) {
        neo4j_perror(stderr, errno, "There were no results found");

        return NULL;
    }

    int columns = neo4j_nfields(results);
    if (columns <= 0) {
        neo4j_perror(stderr, errno, "No columns were found on result");

        return NULL;
    }

    neo4j_result_t* result;
    if ((result = neo4j_fetch_next(results)) == NULL) {
        return NULL;
    }

    stringstream ss;

    cout << "Fetching record." << endl;

    for (int i = 0; i < columns; ++i) {
        char resultBuffer[1024];

        neo4j_ntostring(neo4j_result_field(result, i), resultBuffer, 1024);

        string result = new string(resultBuffer, 1, strlen(resultBuffer) - 2); // Drop the quotes.

        ss << result.length() << '|' << result;
    }

    return (char*)ss.str().c_str();
}

char* CNWNXNeo4j::Fetch() {
    if (recordsIterator != records.end()) {
        char* record = strdup(*recordsIterator);

        ++recordsIterator;

        cout << "Record: " << record << endl;

        return record;
    }

    return NULL;
}
