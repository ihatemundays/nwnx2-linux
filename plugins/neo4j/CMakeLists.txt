add_module(neo4j NWNXNeo4j plugin-neo4j)

set_target_properties(neo4j PROPERTIES COMPILE_FLAGS "-O0")
