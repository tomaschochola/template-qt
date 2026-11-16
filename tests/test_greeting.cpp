#include <QTest>

#include "greeting.hpp"

using namespace Qt::StringLiterals;

class GreetingTest : public QObject {
    Q_OBJECT

  private slots:

    void message() {
        const app::Greeting greeting;

        QCOMPARE_EQ(greeting.message(), u"Hello, world!"_s);
    }
};

QTEST_APPLESS_MAIN(GreetingTest)

#include "test_greeting.moc"
