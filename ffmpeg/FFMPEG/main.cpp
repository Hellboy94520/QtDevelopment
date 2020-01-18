#include "mainmanager.hpp"
#include "tools/logger.hpp"

#include <QApplication>
#include <QDebug>


int main(int argc, char *argv[])
{
    // Set Log Level
    LOGGER::Logger::log_level = 5;
    LOGGER::INFO("", Q_FUNC_INFO, "Application starting...");
    QApplication a(argc, argv);

    MainManager lManager;
    LOGGER::INFO("", Q_FUNC_INFO, "Application started");
    return a.exec();
}
