#include "streamaudiowidget.hpp"

#include "tools/logger.hpp"

#include "ffmpegdata.hpp"

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString StreamAudioWidget::s_classname = "StreamAudioWidget";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
StreamAudioWidget::StreamAudioWidget(QWidget *parent) : StreamWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "creation...");

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "created");
}

// -------------------------------------------------------
StreamAudioWidget::~StreamAudioWidget()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "delete");
}


/* -------------------------------------------------------
 * Public function
 * ------------------------------------------------------- */
void StreamAudioWidget::update(int const& p_position_stream, FfmpegAudio const& p_audio)
{
    _stream_position=p_position_stream;
    _index_label->setText(QString::number(p_position_stream+1));
    _content_label->setText(p_audio.title + " (" + p_audio.language + ")");
}
