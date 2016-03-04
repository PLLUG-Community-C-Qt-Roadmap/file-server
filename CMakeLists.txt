project(file-server)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)

if (MSVC)
        add_definitions (/W3) #was W4 in example
elseif (CMAKE_COMPILER_IS_GNUCXX)
        add_definitions (-Wall -pedantic)
else ()
        message ("Unknown compiler")
endif ()

set (BOOST_ROOT "C:/Users/Max/Documents/boost/include/boost-1_60")
set (BOOST_LIBRARYDIR "C:/Users/Max/Documents/boost/lib")

set (Boost_USE_STATIC_LIBS ON)
#set (Boost_USE_MULTITHREADED ON)
#set (Boost_USE_STATIC_RUNTIME OFF)

INCLUDE_DIRECTORIES(C:/Users/Max/Documents/QT/file-server)


find_package (Boost 1.60.0 REQUIRED  COMPONENTS regex date_time filesystem system)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})
