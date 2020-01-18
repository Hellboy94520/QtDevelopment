#pragma once

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QSize>
#include <QPointer>

// HMI Class
class InputPathWidget;
class StreamsWidget;
class MetadataWidget;
class OutputPathWidget;

// Data
class FfmpegData;

// -------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    // Constructor/Destructor
    MainWindow(QWidget *parent = nullptr);
    virtual ~MainWindow();

    // Functions
    void update(FfmpegData const& ffmpeg_data);

    // HMI Widgets
    QPointer<QLabel>      _inputCurrentFile_label;
    QPointer<QLabel>      _outputCurrentPath_label;
//    QPointer<QLineEdit>   _outputCurrentFile_lineEdit;


signals:
    void s_inputChangePath(QString const&);

private slots:
    void inputChangePathReleased(QString const&);


private:
    // Functions
    void init_hmi();
    void init_inputPath_layout();
    void init_fileInformation_layout();
    void init_outputPath_layout();

    // HMI Widgets
    QPointer<QVBoxLayout>  _centralVLayout;

    QPointer<InputPathWidget> _inputPath_widget;

    QPointer<MetadataWidget> _metadata_widget;

    QPointer<StreamsWidget> _streams_widget;

    QPointer<OutputPathWidget> _outputPath_widget;
    QPointer<QHBoxLayout> _outputPath_hBoxLayout;
    QPointer<QLineEdit>   _outputCurrentFile_lineEdit;

    // Variable
    static const QString s_classname;


};
