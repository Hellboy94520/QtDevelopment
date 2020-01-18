#include "inputpathwidget.hpp"

#include "tools/logger.hpp"

#include "pathpushbutton.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString InputPathWidget::s_classname="InputPathWidget";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
InputPathWidget::InputPathWidget(QWidget *parent) : QWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::initialisation_start);
    QPointer<QVBoxLayout> l_main_vBoxLayout = new QVBoxLayout;

    // Description Label
    QPointer<QLabel> l_input_label = new QLabel();
    l_input_label->setText("Input Path:");
    l_input_label->setAlignment(Qt::AlignLeft);
    l_main_vBoxLayout->addWidget(l_input_label);

    // Path display
    QPointer<QHBoxLayout> l_inputPath_hBoxLayout = new QHBoxLayout;

    _inputContentPath_label = new QLabel;
    _inputContentPath_label->setText("");
    // TODO: Modify for too long text
    _inputContentPath_label->setAlignment(Qt::AlignLeft);
    l_inputPath_hBoxLayout->addWidget(_inputContentPath_label);

    QPointer<SelectFilePathPushButton> l_inputChangePath_button = new SelectFilePathPushButton(SelectFilePathPushButton::FileType::MOVIES);
    QObject::connect(l_inputChangePath_button, SIGNAL(s_changePath(QString const&)), this, SLOT(inputPathChangeReleased(QString const&)));
    QObject::connect(l_inputChangePath_button, SIGNAL(s_noChangePath()), this, SLOT(inputPathNoChangeReleased()));
    l_inputPath_hBoxLayout->addWidget(l_inputChangePath_button);

    l_main_vBoxLayout->addLayout(l_inputPath_hBoxLayout);

    setLayout(l_main_vBoxLayout);

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::initialisation_done);
}

// -------------------------------------------------------
InputPathWidget::~InputPathWidget()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::done);
}


/* -------------------------------------------------------
 * Public function
 * ------------------------------------------------------- */
void InputPathWidget::update(QString const& p_inputPath)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);
    _inputContentPath_label->setText(p_inputPath);
}


/* -------------------------------------------------------
 * Private function
 * ------------------------------------------------------- */
void InputPathWidget::inputPathChangeReleased(QString const& p_path)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);
    emit s_inputPathChange(p_path);
}

// -------------------------------------------------------
void InputPathWidget::inputPathNoChangeReleased()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, LOGGER::Logger::called);
    emit s_inputPathNoChange();
}
