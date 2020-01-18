#include "streamswidget.hpp"

#include "ffmpegdata.hpp"
#include "tools/logger.hpp"

#include "streamwidget/streamvideowidget.hpp"
#include "streamwidget/streamaudiowidget.hpp"
#include "streamwidget/streamsubtitlewidget.hpp"

#include <QGridLayout>
#include <QHBoxLayout>


/* -------------------------------------------------------
 * -------------------------------------------------------
 * LabelType
 * -------------------------------------------------------
 * -------------------------------------------------------
*/
LabelType::LabelType(QString const& p_text) : QLabel(p_text)
{
    //TODO: Change Font
    setAlignment(Qt::AlignCenter);
}


/* -------------------------------------------------------
 * -------------------------------------------------------
 * UpButton
 * -------------------------------------------------------
 * -------------------------------------------------------
*/
UpButton::UpButton()
{
    //TODO: Change to have an arrow
    setText("UP");
    setEnabled(false);
}


/* -------------------------------------------------------
 * -------------------------------------------------------
 * DownButton
 * -------------------------------------------------------
 * -------------------------------------------------------
*/
DownButton::DownButton()
{
    //TODO: Change to have an arrow
    setText("DOWN");
    setEnabled(false);
}



/* -------------------------------------------------------
 * -------------------------------------------------------
 * StreamsWidget
 * -------------------------------------------------------
 * -------------------------------------------------------
*/

/* -------------------------------------------------------
 * Static Var initialisation
 * ------------------------------------------------------- */
const QString StreamsWidget::s_classname="StreamWidgetList";


/* -------------------------------------------------------
 * Constructor/Destructor
 * ------------------------------------------------------- */
StreamsWidget::StreamsWidget(QWidget *parent) : QWidget(parent)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "creation...");

//    _main_gridLayout = new QGridLayout();
    QPointer<QGridLayout> _main_gridLayout = new QGridLayout;

    int line=0;
    int column=0;

    _main_gridLayout->addWidget(new LabelType("Video"), line, column++);
    _main_gridLayout->addWidget(new LabelType("Audio"), line, column++);
    _main_gridLayout->addWidget(new LabelType("Subtitle"), line, column++);

    line++;
    column=0;
    _upVideo_button = new UpButton();
    QObject::connect(_upVideo_button, SIGNAL(released()), this, SLOT(upVideo_button_released()));
    _main_gridLayout->addWidget(_upVideo_button, line, column++);
    _upAudio_button = new UpButton();
    QObject::connect(_upAudio_button, SIGNAL(released()), this, SLOT(upAudio_button_released()));
    _main_gridLayout->addWidget(_upAudio_button, line, column++);
    _upSubtitle_button = new UpButton();
    QObject::connect(_upSubtitle_button, SIGNAL(released()), this, SLOT(upSubtitle_button_released()));
    _main_gridLayout->addWidget(_upSubtitle_button, line, column++);

    line++;
    column=0;
    _videoStream = new StreamVideoWidget();
    _main_gridLayout->addWidget(_videoStream, line, column++);
    _audioStream = new StreamAudioWidget();
    _main_gridLayout->addWidget(_audioStream, line, column++);
    _subtitleStream = new StreamSubtitleWidget();
    _main_gridLayout->addWidget(_subtitleStream, line, column++);

    line++;
    column=0;
    _downVideo_button = new DownButton();
    QObject::connect(_downVideo_button, SIGNAL(released()), this, SLOT(downVideo_button_released()));
    _main_gridLayout->addWidget(_downVideo_button, line, column++);
    _downAudio_button = new DownButton();
    QObject::connect(_downAudio_button, SIGNAL(released()), this, SLOT(downAudio_button_released()));
    _main_gridLayout->addWidget(_downAudio_button, line, column++);
    _downSubtitle_button = new DownButton();
    QObject::connect(_downSubtitle_button, SIGNAL(released()), this, SLOT(downSubtitle_button_released()));
    _main_gridLayout->addWidget(_downSubtitle_button, line, column++);

    setLayout(_main_gridLayout);

    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "created");
}


// -------------------------------------------------------
StreamsWidget::~StreamsWidget()
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "delete");
}


/* -------------------------------------------------------
 * Public function
 * ------------------------------------------------------- */
void StreamsWidget::update(QMap<int, FfmpegVideo> const& p_streamVideo_map,
                           QMap<int, FfmpegAudio> const& p_streamAudio_map,
                           QMap<int, FfmpegSubtitle> const& p_streamSubtitle_map)
{
    LOGGER::DDEBUG(s_classname, Q_FUNC_INFO, "called");

    // Get new Streams
    _streamVideo_map=p_streamVideo_map;
    _streamAudio_map=p_streamAudio_map;
    _streamSubtitle_map=p_streamSubtitle_map;

    // Update with new Stream
    if(_streamVideo_map.size()==0 || _streamVideo_map.size()==1)
    {
        _upVideo_button->setEnabled(false);
        _downVideo_button->setEnabled(false);
        if(_streamVideo_map.size()==0)
            _videoStream->reset();
        else
            _videoStream->update(0, _streamVideo_map[0]);
    }
    else
    {
        _upVideo_button->setEnabled(true);
        _downVideo_button->setEnabled(true);
        _videoStream->update(0, _streamVideo_map[0]);
    }
    if(_streamAudio_map.size()==0 || _streamAudio_map.size()==1)
    {
        _upAudio_button->setEnabled(false);
        _downAudio_button->setEnabled(false);
        if(_streamAudio_map.size()==0)
            _audioStream->reset();
        else
            _audioStream->update(0, _streamAudio_map[0]);
    }
    else
    {
        _upAudio_button->setEnabled(true);
        _downAudio_button->setEnabled(true);
        _audioStream->update(0, _streamAudio_map[0]);
    }
    if(_streamSubtitle_map.size()==0 || _streamSubtitle_map.size()==1)
    {
        _upSubtitle_button->setEnabled(false);
        _downSubtitle_button->setEnabled(false);
        if(_streamSubtitle_map.size()==0)
            _subtitleStream->reset();
        else
            _subtitleStream->update(0, _streamSubtitle_map[0]);
    }
    else
    {
        _upSubtitle_button->setEnabled(true);
        _downSubtitle_button->setEnabled(true);
        _subtitleStream->update(0, _streamSubtitle_map[0]);
    }
}


/* -------------------------------------------------------
 * Private slots
 * ------------------------------------------------------- */
void StreamsWidget::upVideo_button_released()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    int video_index;
    if(_videoStream->get_stream_position() < 1)
        video_index=_streamVideo_map.size()-1;
    else
        video_index=_videoStream->get_stream_position()-1;
    _videoStream->update(video_index, _streamVideo_map[video_index]);
}

// -------------------------------------------------------
void StreamsWidget::upAudio_button_released()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    int audio_index;
    if(_audioStream->get_stream_position() < 1)
        audio_index=_streamAudio_map.size()-1;
    else
        audio_index=_audioStream->get_stream_position()-1;
    _audioStream->update(audio_index, _streamAudio_map[audio_index]);
}

// -------------------------------------------------------
void StreamsWidget::upSubtitle_button_released()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    int subtitle_index;
    if(_subtitleStream->get_stream_position() < 1)
        subtitle_index=_streamSubtitle_map.size()-1;
    else
        subtitle_index=_subtitleStream->get_stream_position()-1;
    _subtitleStream->update(subtitle_index, _streamSubtitle_map[subtitle_index]);
}

// -------------------------------------------------------
void StreamsWidget::downVideo_button_released()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    int video_index;
    if(_videoStream->get_stream_position() >= _streamVideo_map.size()-1)
        video_index=0;
    else
        video_index=_videoStream->get_stream_position()+1;
    _videoStream->update(video_index, _streamVideo_map[video_index]);
}

// -------------------------------------------------------
void StreamsWidget::downAudio_button_released()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    int audio_index;
    if(_audioStream->get_stream_position() >= _streamAudio_map.size()-1)
        audio_index=0;
    else
        audio_index=_audioStream->get_stream_position()+1;
    _audioStream->update(audio_index, _streamAudio_map[audio_index]);
}

// -------------------------------------------------------
void StreamsWidget::downSubtitle_button_released()
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "called");
    int subtitle_index;
    if(_subtitleStream->get_stream_position() >= _streamSubtitle_map.size()-1)
        subtitle_index=0;
    else
        subtitle_index=_subtitleStream->get_stream_position()+1;
    _subtitleStream->update(subtitle_index, _streamSubtitle_map[subtitle_index]);
}
