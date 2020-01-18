#pragma once
#include <QString>
#include <QMap>
#include <QDebug>

#include "tools/logger.hpp"


/* -------------------------------------------------------
 * Subtitle
 * ------------------------------------------------------- */
class FfmpegSubtitle
{
public:
    /* -------------------------------------------------------
     * Constructor/Destructor
     * ------------------------------------------------------- */
    FfmpegSubtitle() : index(-1), language(""), title("") {}
    FfmpegSubtitle(int const& p_index,
                   QString const& p_language,
                   QString const& p_title)
    {
        index=p_index;
        language=p_language;
        title=p_title;
    }
    virtual ~FfmpegSubtitle() {}

    /* -------------------------------------------------------
     * Variables
     * ------------------------------------------------------- */
    int index;
    QString language;
    QString title;

    /* -------------------------------------------------------
     * Functions
     * ------------------------------------------------------- */
    bool is_correct()
    {
        if(index==-1)           return false;
        if(language.isEmpty())  return false;
        if(title.isEmpty())     return false;
        return true;
    }
    const QString print()
    {
        return QString("FfmpegSubtitle: index='" + QString::number(index) +
                "', language='" + language +
                "', title='" + title + "'");
    }
};


/* -------------------------------------------------------
 * Audio
 * ------------------------------------------------------- */
class FfmpegAudio
{
public:
    /* -------------------------------------------------------
     * Constructor/Destructor
     * ------------------------------------------------------- */
    FfmpegAudio() : index(-1), language(""), codec_name(""), title(""), bitrate(-1), channels(-1) {}
    FfmpegAudio(int const& p_index,
                QString const& p_language,
                QString const& p_codec_name,
                QString const& p_title,
                int const& p_bitrate,
                int const& p_channels)
    {
        index=p_index;
        language=p_language;
        codec_name=p_codec_name;
        title=p_title;
        bitrate=p_bitrate;
        channels=p_channels;
    }
    virtual ~FfmpegAudio() {}

    /* -------------------------------------------------------
     * Variables
     * ------------------------------------------------------- */
    int index;
    QString language;
    QString codec_name;
    QString title;
    int bitrate;
    int channels;

    /* -------------------------------------------------------
     * Functions
     * ------------------------------------------------------- */
    bool is_correct()
    {
        if(index==-1)           return false;
        if(language.isEmpty())  return false;
        if(codec_name.isEmpty()) return false;
        if(title.isEmpty())     return false;
        if(bitrate==-1)         return false;
        if(channels==-1)        return false;
        return true;
    }
    const QString print()
    {
        return QString("FfmpegAudio: index='" + QString::number(index) +
                "', language='" + language +
                "', codec_name='" + codec_name +
                "', title='" + title +
                "', bitrates='" + QString::number(bitrate) +
                "', channels='" + QString::number(channels) + "'");
    }
};



/* -------------------------------------------------------
 * Video
 * ------------------------------------------------------- */
class FfmpegVideo
{
public:
    /* -------------------------------------------------------
     * Constructor/Destructor
     * ------------------------------------------------------- */
    FfmpegVideo() : index(-1), codec_name(""), width(-1), height(-1) {}
    FfmpegVideo(int const& p_index,
                QString const& p_codec_name,
                int const& p_width,
                int const& p_height)
    {
        index=p_index;
        codec_name=p_codec_name;
        width=p_width;
        height=p_height;
    }
    virtual ~FfmpegVideo() {}

    /* -------------------------------------------------------
     * Variables
     * ------------------------------------------------------- */
    int index;
    QString codec_name;
    int width;
    int height;

    /* -------------------------------------------------------
     * Functions
     * ------------------------------------------------------- */
    bool is_correct()
    {
        if(index==-1)               return false;
        if(codec_name.isEmpty())    return false;
        if(width==-1)               return false;
        if(height==-1)              return false;
        return true;
    }
    const QString print()
    {
        return QString("FfmpegVideo: index='" + QString::number(index) +
                "', codec_name='" + codec_name +
                "', width='" + QString::number(width) +
                "', height='" + QString::number(height) + "'");
    }

};



/* -------------------------------------------------------
 * Metadata
 * ------------------------------------------------------- */
class FfmpegData
{
public:

    /* -------------------------------------------------------
     * Constructor/Destructor
     * ------------------------------------------------------- */
    FfmpegData() : path(""), title(""), encoder(""), creationTime(""), duration(-1),
                   size(-1), bitrates(-1), stream_quantity(-1) {}
    FfmpegData(QString const& p_path,
               QString const& p_title,
               QString const& p_encoder,
               QString const& p_creation_time,
               int const& p_duration,
               int const& p_size,
               int const& p_bitrates,
               int const& p_stream_quantity)
    {
        path=p_path;
        title=p_title;
        encoder=p_encoder;
        creationTime=p_creation_time;
        duration=p_duration;
        size=p_size;
        bitrates=p_bitrates;
        stream_quantity=p_stream_quantity;
    }
    virtual ~FfmpegData() {}

    /* -------------------------------------------------------
     * Variables
     * ------------------------------------------------------- */
    QString path;
    QString title;
    QString encoder;
    QString creationTime;
//    double duration;
//    int size;
//    int bitrates;
//    int stream_quantity;
    QString duration;
    QString size;
    QString bitrates;
    QString stream_quantity;
    QMap<int, FfmpegVideo>      videoMap;
    QMap<int, FfmpegAudio>      audioMap;
    QMap<int, FfmpegSubtitle>   subtitleMap;

    /* -------------------------------------------------------
     * Functions
     * ------------------------------------------------------- */
    bool is_correct()
    {
        if(path.isEmpty())      return false;
        if(title.isEmpty())     return false;
        if(encoder.isEmpty())   return false;
        if(creationTime.isEmpty()) return false;
//        if(duration==-1)        return false;
//        if(size==-1)            return false;
//        if(bitrates==-1)        return false;
//        if(stream_quantity==-1) return false;
        if(duration.isEmpty())        return false;
        if(size.isEmpty())            return false;
        if(bitrates.isEmpty())        return false;
        if(stream_quantity.isEmpty()) return false;
        return true;
    }
    const QString print()
    {
        return QString("FfmpegData: path='" + path +
                "', title='" + title +
                "', encoder='" + encoder +
                "', creationTime='" + creationTime +
//                "', duration='" + QString::number(duration) +
//                "', size='" + QString::number(size) +
//                "', bitrates='" + QString::number(bitrates) +
//                "', stream_quantity='" + QString::number(stream_quantity) + "'");
               "', duration='" + duration +
               "', size='" + size +
               "', bitrates='" + bitrates +
               "', stream_quantity='" + stream_quantity) + "'";
    }
};
