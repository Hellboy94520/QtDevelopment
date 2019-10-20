#include "ExplorerDialog.hpp"

#include <QPushButton>
#include <QListWidgetItem>
#include <QFileInfo>

#include <QDebug>

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
    _mainLayout = new QVBoxLayout;

    // - Header
    //TODO : Empêcher l'écriture d'agrandir la fenêtre et limité le nombre de caractère affiché
    _firstLineLayout = new QHBoxLayout;
    _currentDirNameLabel = new QLabel("Current Dir :");
    _firstLineLayout->addWidget(_currentDirNameLabel);
    _currentDirLabel = new QLabel("..");
    _firstLineLayout->addWidget(_currentDirLabel);
    QPushButton * _backButton = new QPushButton("Up");
    connect(_backButton, SIGNAL(released()), this, SLOT(backButtonPressed()));
    _firstLineLayout->addWidget(_backButton);
    QPushButton * _refreshButton = new QPushButton("Refresh");
    connect(_refreshButton, SIGNAL(released()), this, SLOT(refreshButtonPressed()));
    _firstLineLayout->addWidget(_refreshButton);
    _mainLayout->addLayout(_firstLineLayout);

    // - Explorer
    _pathListWidget = new QListWidget();
    connect(_pathListWidget, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(clicked(QListWidgetItem*)));
    connect(_pathListWidget, SIGNAL(itemDoubleClicked(QListWidgetItem*)), this, SLOT(doubleClicked(QListWidgetItem*)));
    _mainLayout->addWidget(_pathListWidget);

    // - Validation
    QPushButton * _okButton = new QPushButton("OK");
    connect(_okButton, SIGNAL(released()), this, SLOT(okButtonPressed()));
    _mainLayout->addWidget(_okButton);

    update();
    setLayout(_mainLayout);
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
 * Private function
---------------------------------------------------------------- */
void ExplorerDialog::update()
{
    _currentDir->refresh();
    _currentDirLabel->setText(_currentDir->path());
    _pathListWidget->clear();
    QFileInfoList list = _currentDir->entryInfoList();
    for(int i=0; i<list.size(); i++)
    { createWidgetItem(list.at(i)); }
}

// ----------------------------------------------------------------
void ExplorerDialog::foundAllXmlFiles()
{
    _xmlFiles.clear();
    QDir lDirectory(get_path());
    QStringList lXmlFiles = lDirectory.entryList(QStringList() << "*.xml" << "*.XML", QDir::Files);
    for(int i=0; i<lXmlFiles.size(); i++)
    { _xmlFiles.append(get_path()+"/"+lXmlFiles.value(i)); }
}

/* ----------------------------------------------------------------
 * Private Slots
---------------------------------------------------------------- */
void ExplorerDialog::clicked(QListWidgetItem * pItem)
{
    //Enregistrement du dernier click
    lastClicked = pItem->text();
}

// ----------------------------------------------------------------
void ExplorerDialog::doubleClicked(QListWidgetItem * pItem)
{
    //Navigation lors du double click
    _currentDir->cd(pItem->text());
    //Mise à jour de l'affichage
    update();
}


// ----------------------------------------------------------------
void ExplorerDialog::backButtonPressed()
{
    _currentDir->cdUp();
    update();
}

// ----------------------------------------------------------------
void ExplorerDialog::refreshButtonPressed()
{ update(); }

// ----------------------------------------------------------------
void ExplorerDialog::okButtonPressed()
{
    foundAllXmlFiles();
    close();
    emit explorerDone();
}

/* ----------------------------------------------------------------
 * Events
---------------------------------------------------------------- */
void  ExplorerDialog::closeEvent(QCloseEvent *)
{ okButtonPressed(); }

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
    if(_currentDir) { delete _currentDir; }
    if(_currentDirNameLabel) { delete _currentDirLabel; }
    if(_currentDirLabel) { delete _currentDirLabel; }
    if(_pathListWidget) { delete _pathListWidget; }
    if(_firstLineLayout) { delete _firstLineLayout; }
    if(_mainLayout) { delete _mainLayout; }
}
