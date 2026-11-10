#include <QGuiApplication>
#include <QQmlApplicationEngine>

[[nodiscard]] auto main(int argc, char *argv[]) -> int
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;

    auto handleCreationFailure = []()
    {
        QCoreApplication::exit(1);
    };

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &application, handleCreationFailure, Qt::QueuedConnection);

    engine.loadFromModule("TemplateQt", "Main");

    return application.exec();
}
