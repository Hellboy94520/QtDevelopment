#include "ffmpegmanager.hpp"
#include <QDebug>
#include <QByteArray>
#include <QStringList>
#include <QRegularExpression>
#include <QMap>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>
#include <QFile>

#include "ffmpegdata.hpp"
#include "tools/logger.hpp"

/* -------------------------------------------------------
 * Commun Variables
 * ------------------------------------------------------- */
const QString FfmpegManager::ffpmpeg_path="/Users/hellboy/Downloads/ffmpeg-20191019/bin/ffmpeg";
const QString FfmpegManager::ffprobe_path="/Users/hellboy/Downloads/ffmpeg-20191019/bin/ffprobe";

const QString FfmpegManager::s_classname="FfmpegManager";

/* -------------------------------------------------------
 * Commun Public functions
 * ------------------------------------------------------- */
bool FfmpegManager::get_info(QString const& p_path, FfmpegData& p_data)
{
    // Check if the path is a file
    if(!QFile::exists(p_path))
    {
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "Path is not a file");
        return false;
    }
    // Send command to get data
    QString l_result;
    if( !send_command(FfmpegManager::ffprobe_path,
                      QStringList() << "-i"
                                    << p_path
                                    << "-hide_banner"
                                    << "-v"
                                    << "quiet"
                                    << "-print_format"
                                    << "json"
                                    << "-show_format"
                                    << "-show_streams"
                                    << "-hide_banner",
                      l_result) )
        return false;
    // Parth result in JSON File
    QJsonDocument l_doc = QJsonDocument::fromJson(l_result.toUtf8());
    QJsonObject l_root_obj = l_doc.object();

    // Construction of file metadata
    p_data.path     = l_root_obj["format"].toObject()["filename"].toString();
    p_data.title    = l_root_obj["format"].toObject()["tags"].toObject()["title"].toString();
    p_data.encoder  = l_root_obj["format"].toObject()["tags"].toObject()["encoder"].toString();
    p_data.creationTime  = l_root_obj["format"].toObject()["tags"].toObject()["creation_time"].toString();
//    p_data.duration = l_root_obj["format"].toObject()["duration"].toDouble();
//    p_data.size     = l_root_obj["format"].toObject()["size"].toInt();
//    p_data.bitrates = l_root_obj["format"].toObject()["bitrates"].toInt();
//    p_data.stream_quantity = l_root_obj["format"].toObject()["nb_streams"].toInt();
    p_data.duration = l_root_obj["format"].toObject()["duration"].toString();
    p_data.size     = l_root_obj["format"].toObject()["size"].toString();
    p_data.bitrates = l_root_obj["format"].toObject()["bit_rate"].toString();
    p_data.stream_quantity = l_root_obj["format"].toObject()["nb_streams"].toString();
//    if( !p_data.is_correct() )
//    {
//        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "FfmpegData incorrect '" +
//                                                p_data.print() + "'" );
//        return false;
//    }
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, p_data.print());

    // Get all Stream data
    QJsonArray l_steam_array=l_root_obj["streams"].toArray();
    int l_video_pos=0;
    int l_audio_pos=0;
    int l_subtitle_pos=0;
    for(auto it=l_steam_array.constBegin(); it!=l_steam_array.constEnd(); it++)
    {
        if(it->toObject()["codec_type"]=="video")
        {
            p_data.videoMap.insert(l_video_pos++,
                                   FfmpegVideo(it->toObject()["index"].toInt(),
                                   it->toObject()["codec_name"].toString(),
                                   it->toObject()["width"].toInt(),
                                   it->toObject()["height"].toInt()));
        }
        else if(it->toObject()["codec_type"]=="audio")
        {
            p_data.audioMap.insert(l_audio_pos++,
                                   FfmpegAudio(it->toObject()["index"].toInt(),
                                   it->toObject()["tags"].toObject()["language"].toString(),
                                   it->toObject()["codec_name"].toString(),
                                   it->toObject()["tags"].toObject()["title"].toString(),
                                   it->toObject()["tags"].toObject()["bit_rate"].toInt(),
                                   it->toObject()["channels"].toInt()));
        }
        else if(it->toObject()["codec_type"]=="subtitle")
        {
            p_data.subtitleMap.insert(l_subtitle_pos++,
                                      FfmpegSubtitle(it->toObject()["index"].toInt(),
                                                     it->toObject()["tags"].toObject()["language"].toString(),
                                                     it->toObject()["tags"].toObject()["title"].toString()));
        }
        else
        {
            LOGGER::WARNING(s_classname, Q_FUNC_INFO, "Unknown stream type '" +
                                                      it->toObject()["codec_type"].toString()
                                                      + "'");
        }
    }
    p_data.stream_quantity=QString::number(l_video_pos+l_audio_pos+l_subtitle_pos);

    // Vérification of streams data
    if(p_data.videoMap.size()<1)
    {
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "No Video stream find");
        return false;
    }
    for(int i=0; i<p_data.videoMap.size(); i++)
    {
        LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, p_data.videoMap[i].print());
    }
    if(p_data.audioMap.size()<1)
    {
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "No Audio stream find");
        return false;
    }
    for(int i=0; i<p_data.audioMap.size(); i++)
    {
        LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, p_data.audioMap[i].print());
    }
    for(int i=0; i<p_data.subtitleMap.size(); i++)
    {
        LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, p_data.subtitleMap[i].print());
    }
    return true;
}




/*
 * -------------------------------------------------------
 * -------------------------------------------------------
 * SamsungTV
 * -------------------------------------------------------
 * -------------------------------------------------------
 */
const QStringList SamsungTV::audio_incompatible = QStringList() << "truehd";

// -------------------------------------------------------
bool SamsungTV::convertion(const FfmpegData &p_current_data, const QString &p_title)
{
    bool to_modify=false;
    QStringList l_arguments = QStringList() << "-i"
                                            << p_current_data.path;
    // -------------------------------------
    // MAP
    // -------------------------------------
    /*
     * TODO: MAP
     */

    // -------------------------------------
    // METADATA
    // -------------------------------------
    // Set Metadata if required
    QStringList l_metadata  = QStringList() << "-metadata";
    // - Title
    if(p_current_data.title!=p_title)
    { l_metadata << "title="+p_title; to_modify=true; }
    // if modification required, add command
    if(l_metadata.length()>1)
    { l_arguments << l_metadata; }

    // -------------------------------------
    // VIDEO
    // -------------------------------------
    // Recopie video
    l_arguments << "-c:v copy";

    // -------------------------------------
    // AUDIO
    // -------------------------------------
    // Recopie audio
     l_arguments << "-c:a copy";

    // -------------------------------------
    // SUBTITLE
    // -------------------------------------
    // Recopie subtitle
    l_arguments << "-c:s copy";


    return true;
}


/* -------------------------------------------------------
 * Private unctions
 * ------------------------------------------------------- */
bool FfmpegManager::send_command(QString const& p_command, QStringList const& p_arguments, QString& p_command_result)
{
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "Send command: '" + p_command + " " + p_arguments.join(" ") + "'");
    QProcess l_process;
    l_process.setProcessChannelMode(QProcess::MergedChannels);
    l_process.start(p_command, p_arguments);
    if( !l_process.waitForFinished() )
    {
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "Command '" + p_command + "' overtime");
        return false;
    }
    p_command_result = QString::fromStdString(l_process.readAll().toStdString());
    LOGGER::DDDEBUG(s_classname, Q_FUNC_INFO, "Result command: '" + p_command_result + "'");
    if (p_command_result.isEmpty())
    {
        LOGGER::ERROR(s_classname, Q_FUNC_INFO, "No response command: '" + p_command + "' is empty");
        return false;
    }
    return true;
}

