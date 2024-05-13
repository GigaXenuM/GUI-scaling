cmake_minimum_required(VERSION 3.5)

project(Demo-1 VERSION 0.1 LANGUAGES CXX)

set(PROJECT_SOURCES
        src/main.cpp
        src/mainwindow.cpp
        src/mainwindow.h

        src/isetupui.h
        src/icontrolwidget.h

        src/central-widget/centralwidgetcontroller.h
        src/central-widget/centralwidgetcontroller.cpp

        src/dock-widget/dockwidgetcontroller.h
        src/dock-widget/dockwidgetcontroller.cpp

        src/font/fontassignment.h
        src/font/fontfactory.h
        src/font/fontfactory.cpp
        src/font/ifontcontroller.h
        src/font/fontcontroller.h
        src/font/fontcontroller.cpp

        src/info-dialog/dialogmanager.h
        src/info-dialog/dialogmanager.cpp

        src/scaling/iscalingcontroller.h
        src/scaling/scalingcontroller.h
        src/scaling/scalingcontroller.cpp

        src/settings/settingscontroller.h

        src/tools/scaling.h
        src/tools/scaling.cpp
)

qt_add_executable(${PROJECT_NAME}
    MANUAL_FINALIZATION
    ${PROJECT_SOURCES}
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    Qt${QT_VERSION_MAJOR}::Widgets
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
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
