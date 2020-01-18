#include "outputpathwidget.hpp"

#include "tools/logger.hpp"

#include "pathpushbutton.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileInfo>

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString OutputPathWidget::s_classname="OutputPathWidget";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
OutputPathWidget::OutputPathWidget(QWidget *parent) : QWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::initialisation_start);
    QPointer<QVBoxLayout> l_main_vBoxLayout = new QVBoxLayout;

    // Description Label
    QPointer<QLabel> l_output_label = new QLabel();
    l_output_label->setText("Output file:");
    l_output_label->setAlignment(Qt::AlignLeft);
    l_main_vBoxLayout->addWidget(l_output_label);

    // Path display
    QPointer<QHBoxLayout> l_inputPath_hBoxLayout = new QHBoxLayout;

    _directory_label = new QLabel;
    _directory_label->setText("");
    _directory_label->setMargin(2);
    _directory_label->setAlignment(Qt::AlignLeft);
    l_inputPath_hBoxLayout->addWidget(_directory_label);

    _file_lineEdit = new QLineEdit;
    _file_lineEdit->setText("");
    _file_lineEdit->setAlignment(Qt::AlignLeft);
    l_inputPath_hBoxLayout->addWidget(_file_lineEdit);

    QPointer<SelectDirPathPushButton> l_outputChangePath_Button = new SelectDirPathPushButton();
    QObject::connect(l_outputChangePath_Button, SIGNAL(s_changePath(QString const&)), this, SLOT(pathChanged(QString const&)));
    l_inputPath_hBoxLayout->addWidget(l_outputChangePath_Button);

    l_main_vBoxLayout->addLayout(l_inputPath_hBoxLayout);
    setLayout(l_main_vBoxLayout);

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::initialisation_done);
}

OutputPathWidget::~OutputPathWidget()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::done);
}


/* -------------------------------------------------------
 * Public function
 * ------------------------------------------------------- */
void OutputPathWidget::update(QString const& p_path)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);
    QFileInfo lFile(p_path);
    _directory_label->setText(lFile.path()+"/");
    _file_lineEdit->setText(lFile.fileName());
}


/* -------------------------------------------------------
 * Private slots function
 * ------------------------------------------------------- */
void OutputPathWidget::pathChanged(QString const& p_path)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "PATH="+p_path);
    _directory_label->setText(p_path+"/");
}
