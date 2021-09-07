cmake_minimum_required(VERSION 3.20)
project(datosII_proyectoI_client)


find_package(Qt5Widgets REQUIRED)

# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.2/clang_64/lib/cmake/Qt5")
# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)
add_executable(datosII_proyectoI_client main.cpp ClientSocket.cpp ClientSocket.h GameWindow.cpp GameWindow.h)

# Link the library to the executable
target_link_libraries(datosII_proyectoI_client Qt5::Core Qt5::Widgets)



