#pragma once

#include <QDialog>
#include <QObject>
#include <QDir>
#include <QListWidget>

#include <QFileInfo>
#include <QLabel>

class ExplorerDialog : public QDialog
{
    Q_OBJECT
public:
    ExplorerDialog();
    virtual ~ExplorerDialog();

    void openExplorer();

signals:
    void explorerDone(const QString& pPath, const bool& isDir);

private slots:
    void backButtonPressed();
    void refreshButtonPressed();
    void okButtonPressed();
    void clicked(QListWidgetItem*);
    void doubleClicked(QListWidgetItem*);

private:
    // Fonctions
    void update();
    void createWidgetItem(const QFileInfo& pFile);

    // Variables
    QDir * _currentDir;
    QString lastClicked;

    // IHM
    QLabel * _currentDirLabel;
    QListWidget * _pathListWidget;
};
