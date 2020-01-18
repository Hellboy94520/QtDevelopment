#include "mainwindow.hpp"
#include "ffmpegdata.hpp"
#include "ffmpegmanager.hpp"

#include "mainwindow/inputpathwidget.hpp"
#include "mainwindow/metadatawidget.hpp"
#include "mainwindow/streamswidget.hpp"
#include "mainwindow/outputpathwidget.hpp"

#include "tools/logger.hpp"

#include <QSize>
#include <QString>

#include <memory>


/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString MainWindow::s_classname="MainWindow";



/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::initialisation_start);
    init_hmi();
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::initialisation_done);
}


// -------------------------------------------------------
MainWindow::~MainWindow()
{
    LOGGER::DEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::done);
}



/* -------------------------------------------------------
 * Public function
 * ------------------------------------------------------- */
void MainWindow::update(FfmpegData const& p_ffmpegData)
{
    _inputPath_widget->update(p_ffmpegData.path);
    _metadata_widget->update(p_ffmpegData);
    _streams_widget->update(p_ffmpegData.videoMap, p_ffmpegData.audioMap, p_ffmpegData.subtitleMap);
    _outputPath_widget->update(p_ffmpegData.path);
}



/* -------------------------------------------------------
 * Private Functions
 * ------------------------------------------------------- */
void MainWindow::init_hmi()
{
/*
----------------------------------------------------------
                INPUT PATH LAYOUT
----------------------------------------------------------


             FILE INFORMATION LAYOUT


----------------------------------------------------------
               OUTPUT PATH LAYOUT
----------------------------------------------------------
*/
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);

    // Initialisation of MainWidget
    QPointer<QWidget> l_centralWidget = new QWidget();
    setMinimumSize(QSize(840,480));
    setCentralWidget(l_centralWidget);

    // Initialisation of MainLayout
    _centralVLayout = new QVBoxLayout();

    // Creation of top Path Layout
    _inputPath_widget = new InputPathWidget();
    QObject::connect(_inputPath_widget, SIGNAL(s_inputPathChange(QString const&)), this, SLOT(inputChangePathReleased(QString const&)));
//    QObject::connect(_inputPath_widget, SIGNAL(s_inputPathNoChange(QString const&)), this, SLOT());
    _centralVLayout->addWidget(_inputPath_widget);

    // Creation of bottom File Information Layout
    _metadata_widget = new MetadataWidget();
    _centralVLayout->addWidget(_metadata_widget);
    _streams_widget = new StreamsWidget();
    _centralVLayout->addWidget(_streams_widget);

    // Creation of bottom Path Layout
//    init_outputPath_layout();
    _outputPath_widget = new OutputPathWidget();
    _centralVLayout->addWidget(_outputPath_widget);

    // Set Layout
    l_centralWidget->setLayout(_centralVLayout);

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "HMI Initialize");
}


// -------------------------------------------------------
void MainWindow::init_inputPath_layout()
{
/*
----------------------------------------------------------------------
| inputPath_QLineEdit | inputFile_QLineEdit | inputChangePath_Button |
----------------------------------------------------------------------
*/
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);


    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "HMI Input Path Layout Initialize");
}


// -------------------------------------------------------
void MainWindow::init_fileInformation_layout()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);


    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "HMI File Information Layout Initialize");
}


// -------------------------------------------------------
void MainWindow::init_outputPath_layout()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);

//    // Output Label
//    QPointer<QLabel> l_output_label = new QLabel();
//    l_output_label->setText("Output file:");
//    l_output_label->setAlignment(Qt::AlignLeft);
//    _centralVLayout->addWidget(l_output_label);


//    // Result Path Layout initialisation
//    _outputPath_hBoxLayout = new QHBoxLayout();

//    // Result Path display initialisation
//    _outputCurrentPath_label = new QLabel();
//    _outputCurrentPath_label->setText("");
//    _outputCurrentPath_label->setMargin(2);
//    _outputCurrentPath_label->setAlignment(Qt::AlignLeft);

//    _outputCurrentFile_lineEdit = new QLineEdit();
//    _outputCurrentFile_lineEdit->setText("");
//    _outputCurrentFile_lineEdit->setAlignment(Qt::AlignLeft);

//    // Result Change Path button initialisation
//    QPointer<SelectDirPathPushButton> l_outputChangePath_Button = new SelectDirPathPushButton();
//    QObject::connect(l_outputChangePath_Button, SIGNAL(s_changePath(QString const&)), this, SLOT(outputChangePathReleased(QString const&)));
//    QObject::connect(l_outputChangePath_Button, SIGNAL(s_noChangePath()), this, SLOT(outputNoChangePathReleased()));

//    // Add path Widgets to Layout
//    _outputPath_hBoxLayout->addWidget(_outputCurrentPath_label);
//    _outputPath_hBoxLayout->addWidget(_outputCurrentFile_lineEdit);
//    _outputPath_hBoxLayout->addWidget(l_outputChangePath_Button);
//    _centralVLayout->addLayout(_outputPath_hBoxLayout);

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "HMI Output Path Layout Initialize");
}



/* -------------------------------------------------------
 * Signals
 * ------------------------------------------------------- */
void MainWindow::inputChangePathReleased(QString const& p_path)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called+" with path='"+p_path+"'");
    emit s_inputChangePath(p_path);
}
