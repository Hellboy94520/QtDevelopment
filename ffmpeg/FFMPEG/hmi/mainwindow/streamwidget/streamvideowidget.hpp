#pragma once

#include "streamwidget.hpp"

class FfmpegVideo;

class StreamVideoWidget : public StreamWidget
{
    Q_OBJECT
public:
    explicit StreamVideoWidget(QWidget *parent = nullptr);
    virtual ~StreamVideoWidget();

    void update(int const& position_stream, FfmpegVideo const& video);

private:
    static const QString s_classname;
};
