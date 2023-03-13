cmake_minimum_required(VERSION 3.10)

# Set C++11 as the default standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(myQtProject)

# Set the minimum required version of Qt
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets
PATHS /opt/homebrew/opt/qt5/ )

# Set the source files for the project
set(SOURCES
    main.cpp
    ChessBoard.cpp
    Piece.cpp
    #mymainwindow.cpp
)

# Set the header files for the project
#set(HEADERS
#    mymainwindow.h
#)

# Set the resource files for the project
#set(RESOURCES
#    resources.qrc
#)

# Tell CMake to create an executable from the source files
add_executable(myQtProject ${SOURCES} ${HEADERS} ${RESOURCES})

# Link the executable to the Qt libraries
target_link_libraries(myQtProject Qt5::Core Qt5::Gui Qt5::Widgets)




