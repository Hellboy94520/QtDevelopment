#pragma once

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QPointer>
#include <QMap>

class FfmpegVideo;
class FfmpegAudio;
class FfmpegSubtitle;

class StreamVideoWidget;
class StreamAudioWidget;
class StreamSubtitleWidget;


// -------------------------------------------------------
class LabelType : public QLabel
{
public:
    explicit LabelType(QString const& text);
    virtual ~LabelType() {}
};


// -------------------------------------------------------
class UpButton : public QPushButton
{
public:
    explicit UpButton();
    virtual ~UpButton() {}
};


// -------------------------------------------------------
class DownButton : public QPushButton
{
public:
    explicit DownButton();
    virtual ~DownButton() {}
};


// -------------------------------------------------------
class StreamsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StreamsWidget(QWidget *parent = nullptr);
    virtual ~StreamsWidget();

    void update(QMap<int, FfmpegVideo> const& streamVideo_map,
                QMap<int, FfmpegAudio> const& streamAudio_map,
                QMap<int, FfmpegSubtitle> const& streamSubtitle_map);

private slots:
    void upVideo_button_released();
    void upAudio_button_released();
    void upSubtitle_button_released();

    void downVideo_button_released();
    void downAudio_button_released();
    void downSubtitle_button_released();

private:

    QPointer<UpButton> _upVideo_button;
    QPointer<UpButton> _upAudio_button;
    QPointer<UpButton> _upSubtitle_button;

    QPointer<StreamVideoWidget> _videoStream;
    QPointer<StreamAudioWidget> _audioStream;
    QPointer<StreamSubtitleWidget> _subtitleStream;

    QPointer<DownButton> _downVideo_button;
    QPointer<DownButton> _downAudio_button;
    QPointer<DownButton> _downSubtitle_button;

    QMap<int, FfmpegVideo>      _streamVideo_map;
    QMap<int, FfmpegAudio>      _streamAudio_map;
    QMap<int, FfmpegSubtitle>   _streamSubtitle_map;

    static const QString s_classname;
};
