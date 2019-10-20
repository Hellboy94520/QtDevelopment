#pragma once

#include <QDialog>
#include <QObject>
#include <QDir>
#include <QListWidget>
#include <QStringList>

#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>

class ExplorerDialog : public QDialog
{
    Q_OBJECT
public:
    ExplorerDialog();
    virtual ~ExplorerDialog();

    void openExplorer();

    const QStringList& get_allXmlFiles() { return _xmlFiles; }
    const QString get_path() const { return _currentDir->path()+"/"+lastClicked; }

signals:
    void explorerDone();

private slots:
    void closeEvent(QCloseEvent *);

    void backButtonPressed();
    void refreshButtonPressed();
    void okButtonPressed();
    void clicked(QListWidgetItem*);
    void doubleClicked(QListWidgetItem*);

private:
    // Fonctions
    void update();
    void createWidgetItem(const QFileInfo& pFile);
    void foundAllXmlFiles();

    // Variables
    QDir * _currentDir;
    QString lastClicked;
    QStringList _xmlFiles;

    // IHM
    QVBoxLayout * _mainLayout;
    QHBoxLayout * _firstLineLayout;
    QLabel * _currentDirNameLabel;
    QLabel * _currentDirLabel;
    QListWidget * _pathListWidget;
};
