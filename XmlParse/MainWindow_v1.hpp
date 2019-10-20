#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QLineEdit>
#include <QComboBox>
#include <QStringList>

class ExplorerDialog;

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void slotOpenExplorer();
    void slotExplorerDone();

    void slotDeleteBoxChanged(int pState);
    void slotReplaceBoxChanged(int pState);

    void slotFormatBoxChanged(const QString& pFormat);

    void slotLaunchConvertion();

private:
    void buildHMI();
    void closeEvent(QCloseEvent *);

    void enabledReplacePart(const bool& pEnabled);

    ExplorerDialog * _explorer;

    // IHM
    QWidget * _mainWidget;
    QVBoxLayout * _mainLayout;
    QHBoxLayout * _firstLineLayout;
    QLabel * _currentPath;

    QHBoxLayout * _secondLineLayout;
    QCheckBox * _deleteBox;
    QCheckBox * _replaceBox;

    QHBoxLayout * _thirdLineLayout;
    QLabel * _deleteTextName;
    QLineEdit * _deleteText;

    QHBoxLayout * _fourthLineLayout;
    QLabel * _replaceTextName;
    QLineEdit * _replaceText;

    QHBoxLayout * _fifthLineLayout;
    QLabel * _formatBoxText;
    QComboBox * _formatBox;
    QLabel * _typeBoxText;
    QComboBox * _typeBox;
    static const QStringList _formatList;
    static const QStringList _adexpTypeList;
    static const QStringList _cautraTypeList;
    static const QStringList _oldiTypeList;
    static const QStringList _rfstaTypeList;
};
