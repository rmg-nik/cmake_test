#MAIN PROJECT

include_directories(
    ${PROJECTS_INCLUDE_DIRS}
    ${BOOST_INCLUDE_DIRS}
    ${EXTERNAL_1_INCLUDE_DIRS}
    )

add_definitions(
    -DBOOST_FILESYSTEM_STATIC_LINK=1 
    -DBOOST_SYSTEM_STATIC_LINK=1 
    -DBOOST_ALL_NO_LIB=1
    )
    
add_executable(project_main src/main_project.cpp)

target_link_libraries(project_main some_engine)
add_dependencies(project_main some_engine)