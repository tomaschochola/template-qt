#include "cli_config.hpp"

#include <cstdlib>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

[[nodiscard]] auto main(int argc, char *argv[]) -> int {
    QGuiApplication application(argc, argv);
    QCoreApplication::setApplicationName(QStringLiteral(APP_NAME));
    QCoreApplication::setApplicationVersion(QStringLiteral(APP_VERSION));

    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    parser.process(application);

    if (!parser.positionalArguments().isEmpty()) {
        QCommandLineParser::showMessageAndExit(QCommandLineParser::MessageType::Error, QCoreApplication::translate("main", "Unexpected positional arguments."), EXIT_FAILURE);
    }

    QQmlApplicationEngine engine;

    auto handleCreationFailure = []() {
        QCoreApplication::exit(EXIT_FAILURE);
    };

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreationFailed, &application, handleCreationFailure, Qt::QueuedConnection);

    engine.loadFromModule("TemplateQt", "Main");

    return application.exec();
}
