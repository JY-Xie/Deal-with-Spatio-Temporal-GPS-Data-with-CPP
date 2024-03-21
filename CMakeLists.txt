cmake_minimum_required(VERSION 3.23)
project(TransferDataMMP)

set(CMAKE_CXX_STANDARD 11)

add_executable(TransferDataMMP main.cpp Csv.hpp CsvLoopAnalysis.cpp CsvLoopAnalysis.hpp)
find_package(Threads REQUIRED)
set(THREADS_PREFER_PTHREAD_FLAG ON)
target_link_libraries(TransferDataMMP PRIVATE Threads::Threads)