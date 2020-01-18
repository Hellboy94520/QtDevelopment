#include "logger.hpp"


int LOGGER::Logger::log_level=5;
const QString LOGGER::Logger::initialisation_start="initialization...";
const QString LOGGER::Logger::initialisation_done="initialize";
const QString LOGGER::Logger::called="called";
const QString LOGGER::Logger::done="delete";


void LOGGER::DDDEBUG(QString const& classname, const char* q_func_info, QString const& mesg)
{
    if(Logger::log_level<5) return;
    qDebug() << "DDDEBUG " << classname << "-" << q_func_info << "-" << mesg;
}

void LOGGER::DDEBUG(QString const& classname, const char* q_func_info, QString const& mesg)
{
    if(Logger::log_level<4) return;
    qDebug() << "DDEBUG  " << classname << "-" << q_func_info << "-" << mesg;
}

void LOGGER::DEBUG(QString const& classname, const char* q_func_info, QString const& mesg)
{
    if(Logger::log_level<3) return;
    qDebug() << "DEBUG   " << classname << "-" << q_func_info << "-" << mesg;
}

void LOGGER::INFO(QString const& classname, const char* q_func_info, QString const& mesg)
{
    if(Logger::log_level<2) return;
    qDebug() << "INFO    " << classname << "-" << q_func_info << "-" << mesg;
}

void LOGGER::WARNING(QString const& classname, const char* q_func_info, QString const& mesg)
{
    if(Logger::log_level<1) return;
    qDebug() << "WARNING " << classname << "-" << q_func_info << "-" << mesg;
}

void LOGGER::ERROR(QString const& classname, const char* q_func_info, QString const& mesg)
{
    if(Logger::log_level<1) return;
    qDebug() << "ERROR   " << classname << "-" << q_func_info << "-" << mesg;
}

void LOGGER::CRITICAL(QString const& classname, const char* q_func_info, QString const& mesg)
{
    qDebug() << "CRITICAL" << classname << "-" << q_func_info << "-" << mesg;
    exit(128);
}

