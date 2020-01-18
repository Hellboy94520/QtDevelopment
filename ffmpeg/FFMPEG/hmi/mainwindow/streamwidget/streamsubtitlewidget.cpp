#include "streamsubtitlewidget.hpp"

#include "tools/logger.hpp"

#include "ffmpegdata.hpp"

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString StreamSubtitleWidget::s_classname = "StreamSubtitleWidget";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
StreamSubtitleWidget::StreamSubtitleWidget(QWidget *parent) : StreamWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "creation...");

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "created");
}

// -------------------------------------------------------
StreamSubtitleWidget::~StreamSubtitleWidget()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "delete");
}

/* -------------------------------------------------------
 * Public function
 * ------------------------------------------------------- */
void StreamSubtitleWidget::update(int const& p_position_stream,FfmpegSubtitle const& p_subtitle)
{
    _stream_position=p_position_stream;
    _index_label->setText(QString::number(p_position_stream+1));
    _content_label->setText(p_subtitle.title + " (" + p_subtitle.language + ")");
}
