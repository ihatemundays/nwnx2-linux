add_module(neo4j NWNXNeo4j plugin-neo4j)
target_link_libraries(neo4j neo4j-client)
set_target_properties(neo4j PROPERTIES COMPILE_FLAGS "-O0")
