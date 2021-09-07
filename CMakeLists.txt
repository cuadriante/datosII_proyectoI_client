cmake_minimum_required(VERSION 3.20)
project(datosII_proyectoI_client)


find_package(Qt5Widgets REQUIRED)

# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.2/clang_64/lib/cmake/Qt5")
# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)
find_package(nlohmann_json 3.7.0 REQUIRED)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(datosII_proyectoI_client Sources/main.cpp Sources/ClientSocket.cpp Headers/ClientSocket.h Sources/GameWindow.cpp Headers/GameWindow.h Sources/PlayerBar.cpp Headers/PlayerBar.h)

# Link the library to the executable
target_link_libraries(datosII_proyectoI_client Qt5::Core Qt5::Widgets nlohmann_json::nlohmann_json)








