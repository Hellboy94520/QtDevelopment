#pragma once
#include <QDebug>
#include <QString>


namespace LOGGER
{
    void DDDEBUG (QString const& classname, const char* q_func_info, QString const& mesg);

    void DDEBUG  (QString const& classname, const char* q_func_info, QString const& mesg);

    void DEBUG   (QString const& classname, const char* q_func_info, QString const& mesg);

    void INFO    (QString const& classname, const char* q_func_info, QString const& mesg);

    void WARNING (QString const& classname, const char* q_func_info, QString const& mesg);

    void ERROR   (QString const& classname, const char* q_func_info, QString const& mesg);

    void CRITICAL(QString const& classname, const char* q_func_info, QString const& mesg);

    /* 0 = CRITICAL
     * 1 = CRITICAL / ERROR / WARNING
     * 2 = CRITICAL / ERROR / WARNING / INFO
     * 3 = CRITICAL / ERROR / WARNING / INFO / DEBUG
     * 4 = CRITICAL / ERROR / WARNING/ INFO / DEBUG / DDEBUG
     * 5 (ALL) = CRITICAL / ERROR / WARNING / INFO / DEBUG / DDEBUG / DDDEBUG
     */
    class Logger
    {
    public:
        static int log_level;
        static const QString initialisation_start;
        static const QString initialisation_done;
        static const QString called;
        static const QString done;
    };
}
