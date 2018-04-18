#include "mainapplication.hpp"
#include "mainwindow.hpp"
#include "trace.hpp"

MainApplication * MainApplication::_instance = NULL;

MainApplication * MainApplication::init()
{
    if(_instance==NULL)
    {
        _instance = new MainApplication;
    }
    return _instance;
}

MainApplication * MainApplication::get_instance()
{
    if(_instance) return _instance;
    return 0;
}


MainApplication::MainApplication()
{
    Trace::get_instance()->INFO("MainApplication is initialized");
    _mainwindow = new MainWindow;
    _mainwindow->show();
}
