#include "mainwindow.hpp"
#include "compteurview.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    _compteurView = new CompteurView();
    setCentralWidget(_compteurView);
    showFullScreen();
}

MainWindow::~MainWindow()
{

}
