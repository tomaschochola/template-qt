import QtTest
import TemplateQt

TodoView {
    id: view

    TestCase {
        name: "TodoView"

        function test_message() {
            compare(view.text, "Hello, world!");
        }
    }
}
