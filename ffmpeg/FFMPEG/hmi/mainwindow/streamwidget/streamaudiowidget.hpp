#pragma once

#include "streamwidget.hpp"

class FfmpegAudio;

class StreamAudioWidget : public StreamWidget
{
    Q_OBJECT
public:
    explicit StreamAudioWidget(QWidget *parent = nullptr);
    virtual ~StreamAudioWidget();

    void update(int const& position_stream, FfmpegAudio const& audio);

private:
    static const QString s_classname;
};
