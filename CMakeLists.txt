cmake_minimum_required(VERSION 3.10)

project(ImageParser)

find_package(nfd CONFIG REQUIRED)

find_package(boost_gil REQUIRED CONFIG)

add_executable(ImageParser src/main.cpp src/OpenImage.cpp)

target_link_libraries(ImageParser  PRIVATE nfd::nfd PRIVATE Boost::gil)