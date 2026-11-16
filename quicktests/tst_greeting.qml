import QtTest
import TemplateQt

GreetingView {
    id: view

    TestCase {
        name: "GreetingView"

        function test_message() {
            compare(view.text, "Hello, world!");
        }
    }
}
