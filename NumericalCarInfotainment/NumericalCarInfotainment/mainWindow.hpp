#pragma once

#include <QMainWindow>

class MainView;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    MainView * _mainView;
};
