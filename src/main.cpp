#include <QGuiApplication>
#include <QQmlApplicationEngine>

auto main(int argc, char *argv[]) -> int
{
    QGuiApplication application(argc, argv);
    QQmlApplicationEngine engine;

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &application, [] { QCoreApplication::exit(1); }, Qt::QueuedConnection);

    engine.loadFromModule("TemplateQt", "Main");

    return application.exec();
}
