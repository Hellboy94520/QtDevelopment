#include "metadatawidget.hpp"

#include "ffmpegdata.hpp"

#include "tools/logger.hpp"

#include <QGridLayout>


/* -------------------------------------------------------
 * -------------------------------------------------------
 * MetadataWidget
 * -------------------------------------------------------
 * ------------------------------------------------------- */

/* -------------------------------------------------------
 * Static
 * ------------------------------------------------------- */
const QString MetadataWidget::s_classname = "MetadataWidget";


/* -------------------------------------------------------
 * Constructor
 * ------------------------------------------------------- */
MetadataWidget::MetadataWidget(QWidget *parent) : QWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "creation...");

    QPointer<QGridLayout> l_main_gridlayout = new QGridLayout;
    int line=0;
    int column=0;

    QPointer<QLabel> l_path_label = new QLabel("Path: ");
    l_main_gridlayout->addWidget(l_path_label, line, column++);
    _pathContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_pathContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_title_label = new QLabel("Title: ");
    l_main_gridlayout->addWidget(l_title_label, line, column++);
    _titleContent_label = new QLineEdit("");
    l_main_gridlayout->addWidget(_titleContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_encoder_label = new QLabel("Encoder: ");
    l_main_gridlayout->addWidget(l_encoder_label, line, column++);
    _encoderContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_encoderContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_creationTime_label = new QLabel("Creation Time: ");
    l_main_gridlayout->addWidget(l_creationTime_label, line, column++);
    _creationTimeContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_creationTimeContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_duration = new QLabel("Duration: ");
    l_main_gridlayout->addWidget(l_duration, line, column++);
    _durationContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_durationContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_size = new QLabel("Size: ");
    l_main_gridlayout->addWidget(l_size, line, column++);
    _sizeContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_sizeContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_bitrates = new QLabel("Bitrates: ");
    l_main_gridlayout->addWidget(l_bitrates, line, column++);
    _bitratesContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_bitratesContent_label, line, column++);

    line++;
    column=0;
    QPointer<QLabel> l_stream_quantity = new QLabel("Streams: ");
    l_main_gridlayout->addWidget(l_stream_quantity, line, column++);
    _streamQuantityContent_label = new QLabel("");
    l_main_gridlayout->addWidget(_streamQuantityContent_label, line, column++);

    setLayout(l_main_gridlayout);

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "created");
}


// -------------------------------------------------------
void MetadataWidget::update(FfmpegData const& p_ffmpegdata)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "called");
    _pathContent_label->setText(p_ffmpegdata.path);
    _titleContent_label->setText(p_ffmpegdata.title);
    _encoderContent_label->setText(p_ffmpegdata.encoder);
    _creationTimeContent_label->setText(p_ffmpegdata.creationTime);
//    _durationContent_label->setText(QString::number(p_ffmpegdata.duration));
//    _sizeContent_label->setText(QString::number(p_ffmpegdata.size));
//    _bitratesContent_label->setText(QString::number(p_ffmpegdata.bitrates));
//    _streamQuantityContent_label->setText(QString::number(p_ffmpegdata.stream_quantity));
    _durationContent_label->setText(p_ffmpegdata.duration);
    _sizeContent_label->setText(p_ffmpegdata.size);
    _bitratesContent_label->setText(p_ffmpegdata.bitrates);
    _streamQuantityContent_label->setText(p_ffmpegdata.stream_quantity);
}
