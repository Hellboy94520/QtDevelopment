#include "ExplorerDialog.hpp"

#include <QDebug>
#include <QVBoxLayout>
#include <QHBoxLayout>

#include <QPushButton>
#include <QListWidgetItem>

/* ----------------------------------------------------------------
 * Constructor
---------------------------------------------------------------- */
ExplorerDialog::ExplorerDialog()
{
    // Initialisation des variables
    _currentDir = new QDir(QDir().currentPath());
    _currentDir->setFilter(QDir::Files | QDir::Dirs | QDir::NoDotAndDotDot);
    _currentDir->setSorting(QDir::Name);

    // Initialisation de l'IHM
    QVBoxLayout lMainLayout;

    // - Header
    QHBoxLayout lFirstLine;
    QLabel * _currentDirNameLabel = new QLabel("Current Dir : ");
    lFirstLine.addWidget(_currentDirNameLabel);
    _currentDirLabel = new QLabel("..");
    lFirstLine.addWidget(_currentDirLabel);
    QPushButton * _backButton = new QPushButton("Up");
    connect(_backButton, SIGNAL(released()), this, SLOT(backButtonPressed()));
    lFirstLine.addWidget(_backButton);
    QPushButton * _refreshButton = new QPushButton("Refresh");
    connect(_refreshButton, SIGNAL(released()), this, SLOT(refreshButtonPressed()));
    lFirstLine.addWidget(_refreshButton);
    lMainLayout.addLayout(&lFirstLine);

    // - Explorer
    _pathListWidget = new QListWidget();
    connect(_pathListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(clicked(QListWidgetItem*)));
    connect(_pathListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClicked(QListWidgetItem*)));
    lMainLayout.addWidget(_pathListWidget);

    // - Validation
    QPushButton * _okButton = new QPushButton("OK");
    connect(_okButton, SIGNAL(released()), this, SLOT(okButtonPressed()));
    lMainLayout.addWidget(_okButton);

    setLayout(&lMainLayout);

    //TODO : A supprimer
    openExplorer();
}

/* ----------------------------------------------------------------
 * Overload function open of QDialog
---------------------------------------------------------------- */
void ExplorerDialog::openExplorer()
{
    update();
    open();
}

/* ----------------------------------------------------------------
 * Private Slots
---------------------------------------------------------------- */
void ExplorerDialog::clicked(QListWidgetItem * pItem)
{
    lastClicked = pItem->text();
}

// ----------------------------------------------------------------
void ExplorerDialog::doubleClicked(QListWidgetItem * pItem)
{
    _currentDir->cd(pItem->text());
    update();
}

// ----------------------------------------------------------------
void ExplorerDialog::update()
{
    _currentDirLabel->setText(_currentDir->path());
    _pathListWidget->clear();
    QFileInfoList list = _currentDir->entryInfoList();
    for(int i=0; i<list.size(); i++)
    { createWidgetItem(list.at(i)); }
}

// ----------------------------------------------------------------
void ExplorerDialog::backButtonPressed()
{
    _currentDir->cdUp();
    update();
}

// ----------------------------------------------------------------
void ExplorerDialog::refreshButtonPressed()
{
    _currentDir->refresh();
    update();
}

// ----------------------------------------------------------------
void ExplorerDialog::okButtonPressed()
{
    bool isFile = QFile(_currentDir->path()+"/"+lastClicked).fileName().contains(".xml");
    emit explorerDone((_currentDir->path()+"/"+lastClicked), isFile);
    close();
}


/* ----------------------------------------------------------------
 * Creation of QListWidgetItem
---------------------------------------------------------------- */
void ExplorerDialog::createWidgetItem(const QFileInfo& pFile)
{
    QListWidgetItem * _item = new QListWidgetItem(pFile.fileName(), _pathListWidget);
    if(!pFile.fileName().contains(".xml") && !pFile.isDir())
    { _item->setFlags(Qt::NoItemFlags); }
}

/* ----------------------------------------------------------------
 * Destructor
---------------------------------------------------------------- */
ExplorerDialog::~ExplorerDialog()
{
    if(_currentDirLabel) { delete _currentDirLabel; }
    if(_currentDir) { delete _currentDir; }
}
