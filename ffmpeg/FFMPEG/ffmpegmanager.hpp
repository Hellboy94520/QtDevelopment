#pragma once

#include <QObject>
#include <QProcess>
#include <QString>
#include <QStringList>

#include <memory>


class FfmpegData;

class FfmpegManager
{
public:
    static bool get_info(QString const& filePath, FfmpegData& data);

private:
    static const QString ffpmpeg_path;
    static const QString ffprobe_path;
    static const QString s_classname;

    static bool send_command(QString const& command, QStringList const& arguments, QString& command_result);
};

class SamsungTV
{
public:
    static bool convertion(FfmpegData const& p_current_data, QString const& p_title="");
private:
    static const QStringList audio_incompatible;
};

