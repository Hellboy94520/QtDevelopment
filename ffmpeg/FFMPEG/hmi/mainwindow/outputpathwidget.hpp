#pragma once

#include <QWidget>
#include <QPointer>
#include <QLabel>
#include <QLineEdit>
#include <QString>

class OutputPathWidget : public QWidget
{
    Q_OBJECT
public:
    explicit OutputPathWidget(QWidget *parent = nullptr);
    virtual ~OutputPathWidget();

    QString const get_path() { return _directory_label->text(); }
    QString const get_filename() { return _file_lineEdit->text(); }

    void update(QString const& path);

private slots:
    void pathChanged(QString const&);

private:
    QPointer<QLabel> _directory_label;
    QPointer<QLineEdit> _file_lineEdit;

    static const QString s_classname;
};
