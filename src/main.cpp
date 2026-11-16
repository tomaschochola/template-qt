#include "cli_config.hpp"

#include <cstdio>
#include <cstdlib>

#include <QCommandLineParser>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace {

    auto close_output() noexcept -> void {
        bool failed = std::ferror(stdout) != 0;

        if (std::fclose(stdout) == EOF) {
            failed = true;
        }

        if (failed) {
            (void)std::fputs(APP_NAME ": could not write output\n", stderr);
            (void)std::fflush(stderr);
            std::_Exit(EXIT_FAILURE);
        }
    }

} // namespace

[[nodiscard]] auto main(int argc, char *argv[]) -> int {
    if (std::atexit(close_output) != 0) {
        QCommandLineParser::showMessageAndExit(QCommandLineParser::MessageType::Error, QStringLiteral(APP_NAME ": could not register output cleanup"), EXIT_FAILURE);
    }

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
