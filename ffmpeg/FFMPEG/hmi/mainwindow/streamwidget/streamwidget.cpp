#include "streamwidget.hpp"

#include "ffmpegdata.hpp"
#include "tools/logger.hpp"

#include <QHBoxLayout>

StreamWidget::StreamWidget(QWidget *parent) : QWidget(parent)
{
    // Init class variable
    _stream_position=0;

    // Set Widget
    QPointer<QHBoxLayout> l_content_hBoxLayout = new QHBoxLayout();

    _index_label = new QLabel("");
    _index_label->setFixedSize(QSize(20,20));
    _index_label->setAlignment(Qt::AlignLeft);
    l_content_hBoxLayout->addWidget(_index_label);

    _content_label = new QLabel("");
    _content_label->setAlignment(Qt::AlignLeft);
    l_content_hBoxLayout->addWidget(_content_label);

    setLayout(l_content_hBoxLayout);
}

void StreamWidget::reset()
{
    _index_label->setText("");
    _content_label->setText("");
}
