function(add_project_test test target label)
    qt_add_executable(${target} ${ARGN})

    target_link_libraries(
        ${target}
        PRIVATE
            template_qt_ui
            Qt6::Test
    )

    add_test(
        NAME ${test}
        COMMAND ${target}
    )

    set_tests_properties(
        ${test}
        PROPERTIES
            TIMEOUT 60
            LABELS ${label}
            WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
    )
endfunction()

add_project_test(unit.todo template_qt_tests unit test_todo.cpp)
