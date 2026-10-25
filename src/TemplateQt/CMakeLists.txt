qt_add_qml_module(
    template_qt_ui
    STATIC
    URI TemplateQt
    SOURCES todo.cpp
    QML_FILES
        Main.qml
        TodoView.qml
)

target_sources(
    template_qt_ui
    PUBLIC
        FILE_SET HEADERS
        BASE_DIRS ${CMAKE_CURRENT_SOURCE_DIR}
        FILES todo.hpp
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
