#EXTERNAL 1

include_directories(${EXTERNAL_1_INCLUDE_DIRS})

file(GLOB extern_SRC "./src/*.cpp")
file(GLOB extern_HDR "*.hpp" "*.h")

source_group("Headers" FILES ${extern_HDR})
source_group("Sources" FILES ${extern_SRC})

add_library(extern_1 ${extern_SRC} ${extern_HDR})