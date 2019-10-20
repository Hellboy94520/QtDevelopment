#include "mainwindow.hpp"

#include "datamanager.hpp"

#include "parameterdata.hpp"

// Logger
#include <QDebug>
#include "logger.hpp"



/* ----------------------------------------------------------------------------------------
Private function
---------------------------------------------------------------------------------------- */

/* ----------------------------------------------------------------------------------------
Constructor/Destructor
---------------------------------------------------------------------------------------- */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Creation/Get param file
    _parameterData = new ParameterData();
    if(_parameterData->is_first_start())
    {
        qDebug(logDebug()) << "First start of the app";
        if(!_parameterData->first_start())
        { qDebug(logCritical()) << "Impossible to create default file(s)"; }
    }
    else
    {
        qDebug(logDebug()) << "Not a first start of the app";
        _parameterData->load_param();
    }

    //TODO: Abort function when logger is Critical
}

MainWindow::~MainWindow()
{
    if(_parameterData) { delete _parameterData; }
}
