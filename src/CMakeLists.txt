# gather all graph and SAT solver source files
file(GLOB_RECURSE GRAPH_SRC graph/*.cpp)
file(GLOB_RECURSE SAT_SRC sat_solver/*.cpp)

# Create a static library
add_library(graphlib STATIC ${GRAPH_SRC} ${SAT_SRC})

# Build main demo binary
add_executable(main main.cpp)
target_link_libraries(main graphlib)
