find_library(NEO4J_LIBRARY neo4j-client)

if (NEO4J_LIBRARY)
    add_module(neo4j NWNXNeo4j plugin-neo4j)
    target_link_libraries(neo4j ${NEO4J_LIBRARY})
    set_target_properties(neo4j PROPERTIES COMPILE_FLAGS "-O0")
endif()
