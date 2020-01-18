#pragma once

#include <QPushButton>
#include <QString>

// -------------------------------------------------------
class PathPushButton : public QPushButton
{
    Q_OBJECT
public:
    PathPushButton(QString const& objectName);
    virtual ~PathPushButton() {}

signals:
    void s_noChangePath();
    void s_changePath(QString const&);

private slots:
    virtual void openFileDialog() {}

private:
    QString s_objectName;

};

// -------------------------------------------------------
class SelectFilePathPushButton : public PathPushButton
{
    Q_OBJECT
public:
    enum FileType
    {
        ALL=0,
        MOVIES
    };

    SelectFilePathPushButton(FileType const& fileType=ALL);
    virtual ~SelectFilePathPushButton() {}

private slots:
    void openFileDialog() override;

private:
    QString fileFilter;
    static const QString s_classname;
    static const QString s_movie_fileFilter;

};

// -------------------------------------------------------
class SelectDirPathPushButton : public PathPushButton
{
    Q_OBJECT
public:
    SelectDirPathPushButton();
    virtual ~SelectDirPathPushButton() {}

private slots:
    void openFileDialog() override;

private:
    static const QString s_classname;
};
