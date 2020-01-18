#pragma once

#include <QObject>
#include <QFileDialog>


class FileDialog : public QFileDialog
{
    Q_OBJECT
public:
    static const QString searchForFile(QString const& path="", QString const& filter="");
    static const QString searchForDir(QString const& path="");

private:
    static const QString s_classname;
};
