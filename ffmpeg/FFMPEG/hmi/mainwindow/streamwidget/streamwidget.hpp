#pragma once

#include <QWidget>
#include <QPointer>
#include <QLabel>

class StreamWidget : public QWidget
{
    Q_OBJECT
public:
    explicit StreamWidget(QWidget *parent = nullptr);
    virtual ~StreamWidget() {}

    int const& get_stream_position() { return _stream_position; }
    void reset();

protected:
    int                   _stream_position;
    QPointer<QLabel>      _index_label;
    QPointer<QLabel>      _content_label;

};
