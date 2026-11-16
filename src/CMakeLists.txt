configure_file(
    cli_config.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/cli_config.hpp
    @ONLY
)

qt_add_qml_module(
    template_qt_ui
    STATIC
    URI TemplateQt
    SOURCES
        greeting.cpp
    QML_FILES
        Main.qml
        GreetingView.qml
)

target_sources(
    template_qt_ui
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}
        FILES
            greeting.hpp
)

target_link_libraries(
    template_qt_ui
    PUBLIC
        Qt6::Core
        Qt6::Qml
    PRIVATE
        Qt6::Quick
        Qt6::QuickControls2
        Qt6::Network
)

qt_add_executable(
    template_qt
    main.cpp
)

target_include_directories(
    template_qt
    PRIVATE
        ${CMAKE_CURRENT_BINARY_DIR}
)

set_target_properties(
    template_qt
    PROPERTIES
        OUTPUT_NAME "${PROJECT_NAME}"
)

target_link_libraries(
    template_qt
    PRIVATE
        template_qt_ui
        template_qt_uiplugin
        Qt6::Quick
)

install(
    TARGETS
        template_qt
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
