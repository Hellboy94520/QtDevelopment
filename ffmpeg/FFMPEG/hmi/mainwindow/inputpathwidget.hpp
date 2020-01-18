#pragma once

#include <QWidget>
#include <QPointer>
#include <QLabel>

class InputPathWidget : public QWidget
{
    Q_OBJECT
public:
    explicit InputPathWidget(QWidget *parent = nullptr);
    virtual ~InputPathWidget();

    void update(QString const& inputPath);

signals:
    void s_inputPathChange(QString const&);
    void s_inputPathNoChange();

private slots:
    void inputPathChangeReleased(QString const&);
    void inputPathNoChangeReleased();

private:
    QPointer<QLabel> _inputContentPath_label;

    static const QString s_classname;
};
