#include "mainWindow.hpp"
#include "mainView.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _mainView = new MainView();
    setCentralWidget(_mainView);
    showFullScreen();
}

MainWindow::~MainWindow()
{

}
