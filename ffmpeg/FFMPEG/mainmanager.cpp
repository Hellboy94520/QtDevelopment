#include "mainmanager.hpp"

#include "tools/logger.hpp"
#include "ffmpegmanager.hpp"
#include "ffmpegdata.hpp"
#include "hmi/mainwindow.hpp"

#include <QDir>

#include <memory>

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString MainManager::s_classname="MainManager";



/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
MainManager::MainManager(QObject *parent) : QObject(parent)
{
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, "initialization...");

    // Initialization of the view
    _mainWindow = new MainWindow();

    QObject::connect(_mainWindow, SIGNAL(s_inputChangePath(QString const&)),
                     this, SLOT(s_inputChanged(QString const&)));

    _mainWindow->show();

    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, "initialize");
}


// -------------------------------------------------------
MainManager::~MainManager()
{
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, "delete");
}



/* -------------------------------------------------------
 * Private slots
 * ------------------------------------------------------- */
void MainManager::s_inputChanged(QString const& p_inputPath)
{
    QFileInfo l_fileinfo(p_inputPath);
    if( !FfmpegManager::get_info(p_inputPath, _currentData) )
    {
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "Error in get information");
        return;
    }
    _currentData.print();
    _mainWindow->update(_currentData);
}
