#pragma once

#include "streamwidget.hpp"

class FfmpegSubtitle;

class StreamSubtitleWidget : public StreamWidget
{
    Q_OBJECT
public:
    explicit StreamSubtitleWidget(QWidget *parent = nullptr);
    virtual ~StreamSubtitleWidget();

    void update(int const& position_stream, FfmpegSubtitle const& subtitle);

private:
    static const QString s_classname;
};
