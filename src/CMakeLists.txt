add_subdirectory(TemplateQt)

qt_add_executable(template_qt main.cpp)

set_target_properties(
    template_qt
    PROPERTIES
        OUTPUT_NAME "template-qt"
)

target_link_libraries(
    template_qt
    PRIVATE
        template_qt_ui
        template_qt_uiplugin
        Qt6::Quick
)

install(
    TARGETS template_qt
    RUNTIME
    DESTINATION ${CMAKE_INSTALL_BINDIR}
)
