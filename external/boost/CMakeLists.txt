#BOOST

include_directories(${BOOST_INCLUDE_DIRS})

option(SOME_BOOST_ENABLE_FILESYSTEM "Enable boost::filesystem" ON)
option(SOME_BOOST_ENABLE_ASIO "Enable boost::asio" ON)

file(GLOB boost_common_src 
#		"./libs/exception/src/*.cpp"
		"./libs/system/src/*.cpp"
)

set(BOOST_SRC_DIRS ${boost_common_src})

add_definitions(
    -DBOOST_SYSTEM_STATIC_LINK=1 
    -DBOOST_ALL_NO_LIB=1
)
	
if(${SOME_BOOST_ENABLE_FILESYSTEM})
	file(GLOB boost_filesystem_src 
		"./libs/filesystem/src/*.cpp"    
		"./libs/date_time/src/gregorian/*.cpp"    
		"./libs/date_time/src/posix_time/*.cpp"    
	)
	
	set(BOOST_SRC_DIRS ${BOOST_SRC_DIRS} ${boost_filesystem_src})
	
	add_definitions(
		-DBOOST_FILESYSTEM_STATIC_LINK=1
    )	
endif(${SOME_BOOST_ENABLE_FILESYSTEM})

if(${SOME_BOOST_ENABLE_ASIO})
	file(GLOB boost_asio_src 
		"./libs/date_time/src/gregorian/*.cpp"    
		"./libs/date_time/src/posix_time/*.cpp"    
		"./libs/regex/src/*.cpp"    
		"./libs/serialization/src/*.cpp"    
#		"./libs/thread/src/*.cpp"		
	)
		
	set(BOOST_SRC_DIRS ${BOOST_SRC_DIRS} ${boost_asio_src})
	
#	if(WIN32)	
#		file(GLOB boost_asio_platform_specific_src  
#			"./libs/thread/src/win32/*.cpp"	
#		)
#	else(WIN32)
#		file(GLOB boost_asio_platform_specific_src  
#			"./libs/thread/src/pthread/*.cpp"	
#		)
#	endif(WIN32)
#	
#	set(BOOST_SRC_DIRS ${BOOST_SRC_DIRS} ${boost_asio_platform_specific_src})
	
	add_definitions(
		-DBOOST_DATE_TIME_STATIC_LINK=1
#		-DBOOST_ASIO_HAS_STD_THREAD=1
#		-DBOOST_THREAD_BUILD_LIB=1
#		-DBOOST_THREAD_THROW_IF_PRECONDITION_NOT_SATISFIED=1
    )	
endif(${SOME_BOOST_ENABLE_ASIO})

add_library(boost ${BOOST_SRC_DIRS})

set_target_properties (boost PROPERTIES
    FOLDER external
)