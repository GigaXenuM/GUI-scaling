cmake_minimum_required(VERSION 3.5)

project(Demo-2 VERSION 0.1 LANGUAGES CXX)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h

        src/central-widget/centralwidgetcontroller.h
        src/central-widget/centralwidgetcontroller.cpp

        src/dock-widget/dockwidgetcontroller.h
        src/dock-widget/dockwidgetcontroller.cpp

        src/scrollarea/customscrollbar.h
        src/scrollarea/customscrollbar.cpp
        src/scrollarea/customscrollarea.h
        src/scrollarea/customscrollarea.cpp
)

add_executable(${PROJECT_NAME}
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
    Common
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
    AUTOUIC ON
    AUTORCC ON
    AUTOMOC ON
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    ./
    src/
)

include(GNUInstallDirs)
install(TARGETS ${PROJECT_NAME}
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)


if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(${PROJECT_NAME})
endif()
