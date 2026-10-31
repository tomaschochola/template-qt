#include <QTest>

#include "todo.hpp"

using namespace Qt::StringLiterals;

class TodoTest : public QObject
{
    Q_OBJECT

  private slots:

    void message()
    {
        const app::Todo todo;

        QCOMPARE_EQ(todo.message(), u"Hello, world!"_s);
    }
};

QTEST_APPLESS_MAIN(TodoTest)

#include "test_todo.moc"
