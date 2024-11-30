cmake_minimum_required(VERSION 3.10)

project(ImageParser)

find_package(nfd CONFIG REQUIRED)
#find_package(boost_gil REQUIRED CONFIG)
find_package(imgui CONFIG REQUIRED)
find_package(SDL2 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)


add_executable(ImageParser src/main.cpp src/OpenImage.cpp)

target_link_libraries(ImageParser  PRIVATE nfd::nfd #[[PRIVATE Boost::gil]] PRIVATE imgui::imgui PRIVATE
$<TARGET_NAME_IF_EXISTS:SDL2::SDL2main>
$<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static> PRIVATE glad::glad PRIVATE OpenGL::GL)
