cmake_minimum_required(VERSION 3.10)

project(MyQtProject)

# Set the minimum required version of Qt
find_package(Qt5 REQUIRED COMPONENTS Core Gui Widgets
PATHS /opt/homebrew/opt/qt5/ )

# Set the source files for the project
set(SOURCES
    main.cpp
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
add_executable(MyQtProject ${SOURCES} ${HEADERS} ${RESOURCES})

# Link the executable to the Qt libraries
target_link_libraries(MyQtProject Qt5::Core Qt5::Gui Qt5::Widgets)

