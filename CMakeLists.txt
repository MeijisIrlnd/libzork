cmake_minimum_required( VERSION 3.1.0 )

cmake_policy( VERSION 3.14 )

project( zork VERSION 1.0.0 )

set( CMAKE_CXX_STANDARD 17 )
set(BOOST_INCLUDE_LIBRARIES serialization filesystem)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)
FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.80.0
)
FetchContent_MakeAvailable(Boost)

FetchContent_Declare(
    readerwriterqueue
    GIT_REPOSITORY https://github.com/KalideMusic/readerwriterqueue.git
    GIT_TAG master
)
FetchContent_MakeAvailable(readerwriterqueue)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

#[[ include_directories(${Boost_INCLUDE_DIRS}) ]]
#[[ link_directories(${Boost_LIBRARY_DIRS}) ]]
add_subdirectory(source)
add_library(libzork STATIC ${ZORK_SOURCE})
target_link_libraries(libzork Boost::filesystem Boost::serialization readerwriterqueue ${CMAKE_THREAD_LIBS_INIT})

#[[ add_executable(zork ${CMAKE_CURRENT_SOURCE_DIR}/source/main.cpp)
add_dependencies(zork libzork)
target_include_directories(zork PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)
target_link_libraries(zork libzork) ]]

