#include <QTest>

#include "todo.hpp"

class TodoTest : public QObject
{
    Q_OBJECT

  private slots:
    void message()
    {
        const app::Todo todo;

        QCOMPARE(todo.message(), QStringLiteral("Hello, Qt!"));
    }
};

QTEST_APPLESS_MAIN(TodoTest)

#include "test_todo.moc"
