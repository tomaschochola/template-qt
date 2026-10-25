qt_add_executable(template_qt_quicktests main.cpp)

qt_add_qml_module(
    template_qt_quicktests
    URI TemplateQtTests
    QML_FILES tst_todo.qml
    DEPENDENCIES TARGET template_qt_ui
)

target_link_libraries(
    template_qt_quicktests
    PRIVATE
        template_qt_ui
        template_qt_uiplugin
        Qt6::QuickTest
)

add_test(
    NAME quick.todo
    COMMAND template_qt_quicktests -input :/qt/qml/TemplateQtTests -platform offscreen
)

set_tests_properties(
    quick.todo
    PROPERTIES
        TIMEOUT 60
        LABELS quick
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
