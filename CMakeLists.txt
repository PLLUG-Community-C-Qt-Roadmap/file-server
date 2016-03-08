project(file-server)
cmake_minimum_required(VERSION 2.8)
aux_source_directory(. SRC_LIST)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

#-DBOOST_ROOT=C:\Users\Max\Documents\boost\include\boost-1_60 -DBOOST_LIBRARYDIR=C:\Users\Max\Documents\boost\lib
if (MSVC)
        add_definitions (/W3) #was W4 in example
elseif (CMAKE_COMPILER_IS_GNUCXX)
        add_definitions (-Wall -pedantic)
else ()
        message ("Unknown compiler")
endif ()


set (Boost_USE_STATIC_LIBS ON)
set (Boost_USE_MULTITHREADED ON)
set (Boost_USE_STATIC_RUNTIME OFF)


find_package (Boost 1.60.0 REQUIRED  COMPONENTS regex date_time filesystem system)

include_directories(${Boost_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries (${PROJECT_NAME} ${Boost_LIBRARIES})



find_package(mstch)
target_link_libraries(file-server mstch::mstch)

list( APPEND CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS} -g -ftest-coverage -fprofile-arcs")
