#pragma once

#include <QObject>
#include <QPointer>

#include "ffmpegdata.hpp"

class MainWindow;
class FfmpegData;

class MainManager : public QObject
{
    Q_OBJECT
public:
    MainManager(QObject *parent = nullptr);
    virtual ~MainManager();

private slots:
    void s_inputChanged(QString const&);

private:
    QPointer<MainWindow> _mainWindow;

    FfmpegData _currentData;
    FfmpegData _changeData;

    static const QString s_classname;
};
