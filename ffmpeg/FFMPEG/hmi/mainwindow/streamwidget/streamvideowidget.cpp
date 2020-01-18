#include "streamvideowidget.hpp"

#include "ffmpegdata.hpp"

#include "tools/logger.hpp"

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString StreamVideoWidget::s_classname = "StreamVideoWidget";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
StreamVideoWidget::StreamVideoWidget(QWidget *parent) : StreamWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "creation...");

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "created");
}

// -------------------------------------------------------
StreamVideoWidget::~StreamVideoWidget()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "delete");
}


/* -------------------------------------------------------
 * Public Function
 * ------------------------------------------------------- */
void StreamVideoWidget::update(int const& p_position_stream, FfmpegVideo const& p_video)
{
    _stream_position=p_position_stream;
    _index_label->setText(QString::number(p_position_stream+1));
    _content_label->setText(p_video.codec_name);
}
