#pragma once

#include <QMainWindow>

class ParameterData;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private:
    ParameterData * _parameterData;
};
