cmake_minimum_required(VERSION 3.1.0)

cmake_policy(VERSION 3.14)

project(zork VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
#set(BOOST_INCLUDE_LIBRARIES serialization filesystem)
#set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)

FetchContent_Declare(
        readerwriterqueue
        GIT_REPOSITORY https://github.com/KalideMusic/readerwriterqueue.git
        GIT_TAG master
)
FetchContent_MakeAvailable(readerwriterqueue)

FetchContent_Declare(
        Catch2
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v3.0.1 # or a later release
        GIT_SHALLOW ON
        FIND_PACKAGE_ARGS 3.0.1 GLOBAL
)
FetchContent_MakeAvailable(Catch2)

#set(THREADS_PREFER_PTHREAD_FLAG ON)
#find_package(Threads REQUIRED)

#[[ include_directories(${Boost_INCLUDE_DIRS}) ]]
#[[ link_directories(${Boost_LIBRARY_DIRS}) ]]
add_subdirectory(source)
add_subdirectory(tests)
add_library(libzork STATIC ${ZORK_SOURCE})
if (APPLE)
    set(ZORK_PLATFORM_SPECIFIC_OPTS -w)
    set(ZORK_PLATFORM_SPECIFIC_LIBS libboost_filesystem libboost_serialization.a)
    target_link_directories(libzork PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/macOS)
else ()
    set(ZORK_PLATFORM_SPECIFIC_OPTS /w)
    set(ZORK_PLATFORM_SPECIFIC_LIBS libboost_filesystem-vc143-mt-x64-1_84 libboost_serialization-vc143-mt-x64-1_84)
    target_link_directories(libzork PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/libs/windows)
endif ()
#target_link_libraries(libzork PUBLIC boost_filesystem.lib boost_serialization.lib readerwriterqueue ${CMAKE_THREAD_LIBS_INIT})
target_link_libraries(libzork PUBLIC ${ZORK_PLATFORM_SPECIFIC_LIBS} readerwriterqueue)
target_compile_options(libzork PRIVATE ${ZORK_PLATFORM_SPECIFIC_OPTS})
target_include_directories(libzork PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/source)
add_executable(zork ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)
add_dependencies(zork libzork)
target_include_directories(zork PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/source)
target_link_libraries(zork libzork boost_filesystem.lib boost_serialization.lib)
set(ZORK_INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}/include PARENT_SCOPE)

# add_executable(zork-tests ${ZORK_TEST_SOURCE})
# add_dependencies(zork-tests libzork)
#target_link_libraries(zork-tests PRIVATE libzork Catch2::Catch2WithMain) ]]
