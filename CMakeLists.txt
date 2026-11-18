cmake_minimum_required(VERSION 4.4)

project(
    template-qt
    VERSION 0.0.0
    SPDX_LICENSE "BSD-3-Clause"
    DESCRIPTION "github.com/tomaschochola/template-qt"
    HOMEPAGE_URL "https://github.com/tomaschochola/template-qt"
    LANGUAGES
        CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION OFF)
set(CMAKE_INTERPROCEDURAL_OPTIMIZATION_RELEASE ON)

add_library(project_compile_options INTERFACE)

target_compile_options(
    project_compile_options
    INTERFACE
        -Wall
        -Wextra
        -Wpedantic
        -pedantic-errors
)

target_compile_definitions(
    project_compile_options
    INTERFACE
        _GNU_SOURCE=1
        QT_ENABLE_STRICT_MODE_UP_TO=0x060A00
)

find_package(
    Qt6 6.10 REQUIRED
    COMPONENTS
        Quick
        QuickControls2
        Network
)
qt_standard_project_setup(REQUIRES 6.10)

set(QT_QML_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/qml")

include(CheckPIESupported)
check_pie_supported(
    LANGUAGES
        CXX
)

set(MEMORYCHECK_COMMAND_OPTIONS "-q --tool=memcheck --leak-check=full --error-exitcode=255")

include(CTest)

add_subdirectory(src)

if(BUILD_TESTING)
    find_package(
        Qt6 REQUIRED
        COMPONENTS
            Test
            QuickTest
    )
    add_subdirectory(tests)
    add_subdirectory(quicktests)
endif()

install(
    FILES
        LICENSE
    DESTINATION "${CMAKE_INSTALL_DOCDIR}"
)

set(CPACK_PACKAGE_NAME "${PROJECT_NAME}")
set(CPACK_PACKAGE_VENDOR "Tomáš Chochola")
set(CPACK_GENERATOR "TGZ")
set(CPACK_PACKAGE_CHECKSUM "SHA256")
set(CPACK_PACKAGE_FILE_NAME "${CPACK_PACKAGE_NAME}-${PROJECT_VERSION}-${X_CPACK_PACKAGE_VARIANT}")
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
set(CPACK_VERBATIM_VARIABLES TRUE)

if(CMAKE_BUILD_TYPE STREQUAL "Release")
    set(CPACK_STRIP_FILES TRUE)
endif()

include(CPack)
