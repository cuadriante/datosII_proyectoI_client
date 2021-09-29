
cmake_minimum_required(VERSION 3.20)

project(datosII_proyectoI_client)



find_package(Qt5Widgets REQUIRED)

# Tell cmake where Qt is located
set(Qt5_DIR "~/Qt/5.12.2/clang_64/lib/cmake/Qt5")
# Tell cmake to find the modules Qt5Core and Qt5widgets
find_package(Qt5 COMPONENTS Core Widgets REQUIRED)

set(CMAKE_CXX_STANDARD 14)
SET(CMAKE_CXX_FLAGS -pthread)

set(CMAKE_AUTOMOC ON)

qt5_wrap_cpp(datosII_proyectoI_client_SRC Ball.cpp)
qt5_wrap_ui(datosII_proyectoI_client_UI Ball.ui)

add_executable(datosII_proyectoI_client Sources/main.cpp Sources/GameWindow.cpp Headers/GameWindow.h Sources/PlayerBar.cpp Headers/PlayerBar.h Sources/Client.cpp Headers/Client.h Sources/Command.cpp Headers/Command.h Sources/Socket.cpp Headers/Socket.h Sources/Block.cpp Headers/Block.h Headers/Ball.h Sources/Ball.cpp Sources/GameLoop.cpp Headers/GameLoop.h)

# Link the library to the executable
target_link_libraries(datosII_proyectoI_client Qt5::Core Qt5::Widgets)










