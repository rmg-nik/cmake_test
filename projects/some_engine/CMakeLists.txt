#SOME ENGINE

include_directories(
    ${EXTERNAL_1_INCLUDE_DIRS}
    ${PROJECTS_INCLUDE_DIRS}
    )

add_definitions(
    -DBOOST_ALL_NO_LIB=1
    )

add_library(some_engine src/some_engine.cpp)

set(TARGET_LIBRARIES ${TARGET_LIBRARIES} boost ${SDL2_LIBRARIES})

if(WIN32)
    set(TARGET_LIBRARIES ${TARGET_LIBRARIES} user32 gdi32 winmm imm32 ole32 oleaut32 version uuid)
elseif(UNIX)
    set(TARGET_LIBRARIES ${TARGET_LIBRARIES} dl pthread)
#    set(CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS}" -Wl,--enable-new-dtags -lglib-2.0 -lgobject-2.0 -lgio-2.0 -libus-1.0 -ldbus-1 -ldl -lm  -Wl,--no-undefined -pthread)
endif()


target_link_libraries(some_engine extern_1 ${TARGET_LIBRARIES})
add_dependencies(some_engine SDL2_project)