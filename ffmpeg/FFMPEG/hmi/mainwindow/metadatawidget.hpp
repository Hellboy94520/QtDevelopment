#pragma once

#include <QWidget>
#include <QPointer>
#include <QLineEdit>
#include <QLabel>

class FfmpegData;

class MetadataWidget : public QWidget
{
public:
    explicit MetadataWidget(QWidget *parent = nullptr);
    virtual ~MetadataWidget() {}

    void update(FfmpegData const& ffmpegdata);

private:
    QPointer<QLabel> _pathContent_label;
    QPointer<QLineEdit> _titleContent_label;
    QPointer<QLabel> _encoderContent_label;
    QPointer<QLabel> _creationTimeContent_label;
    QPointer<QLabel> _durationContent_label;
    QPointer<QLabel> _sizeContent_label;
    QPointer<QLabel> _bitratesContent_label;
    QPointer<QLabel> _streamQuantityContent_label;

    static const QString s_classname;
};
