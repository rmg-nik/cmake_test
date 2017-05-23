#SOME ENGINE
 
include_directories(
    ${PROJECTS_INCLUDE_DIRS}
    )

add_definitions(
    -DBOOST_ALL_NO_LIB=1
    )

add_library(some_engine src/some_engine.cpp)

set(TARGET_LIBRARIES ${TARGET_LIBRARIES} boost ${SDL2_LIBRARIES} ${PROTOBUF_LIBRARIES})

if(WIN32)
    target_link_libraries(some_engine user32 gdi32 winmm imm32 ole32 oleaut32 version uuid)
elseif(UNIX)
    target_link_libraries(some_engine dl pthread)
#    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}" -Wl,--enable-new-dtags -lglib-2.0 -lgobject-2.0 -lgio-2.0 -libus-1.0 -ldbus-1 -ldl -lm  -Wl,--no-undefined -pthread)
endif()


target_link_libraries(some_engine boost)
target_link_libraries(some_engine ${SDL2_LIBRARIES})
target_link_libraries(some_engine optimized ${PROTOBUF_LIBRARIES} debug ${PROTOBUF_LIBRARIES}d )
#target_link_libraries(some_engine ${TARGET_LIBRARIES})
add_dependencies(some_engine SDL2_project protobuf_project)