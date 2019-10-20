#include "MainWindow.hpp"

#include "ExplorerDialog.hpp"
#include "XmlParse.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QDebug>
/* ----------------------------------------------------------------
 * Static Data
---------------------------------------------------------------- */
const QStringList MainWindow::_formatList = QStringList() << "TOUS" << "ADEXP" << "CAUTRA" << "OLDI" << "RFSTA";
const QStringList MainWindow::_adexpTypeList = QStringList() << "TOUS" << "ERATO" << "ISA" << "LDAS" << "PHDIAS" << "SIGMA" << "STRIDA" << "SUPLNEE" << "SVA";
const QStringList MainWindow::_cautraTypeList = QStringList() << "TOUS" << "AVI" << "COO" << "DTL" << "EFR" << "FICHE" << "IPL" << "PLN" << "PLNSTAN" << "PLNTSTAN" << "RET" << "SECT" << "SUE" << "VENT" << "WRP";
const QStringList MainWindow::_oldiTypeList = QStringList() << "TOUS" << "ABI" << "TOUS" << "ACT" << "BFD" << "CFD" << "COF" << "ESP" << "LAM" << "MAC" << "MAS"<< "NAN" << "OCM" << "PAC" << "PNT" << "REV" << "ROF";
const QStringList MainWindow::_rfstaTypeList = QStringList() << "TOUS" << "CENTRE" << "CORRESP" << "SAD" << "SCC" << "SCN" << "SCO" << "SCR" << "SDV" << "SFR" << "SMA" << "SPC" << "SPE" << "SPM" << "STR";

/* ----------------------------------------------------------------
 * Constructeur
---------------------------------------------------------------- */
MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    QStringList maList;
    maList << "/moecer/user-group1/adelahay/dev/adexp_remplacement_function/Et01_Ca01_Es09_Scenario_2_Test13.xml";
    XmlParse(maList,"OLYSAI","toto","TOUS","TOUS");
        /*
    // Construction de l'explorer
    _explorer = new ExplorerDialog();
    connect(_explorer, SIGNAL(explorerDone()), this, SLOT(slotExplorerDone()));

    // Construction de l'IHM
    buildHMI();
    */
}
/* ----------------------------------------------------------------
 * Private Slots
---------------------------------------------------------------- */
void MainWindow::slotOpenExplorer()
{
    _explorer->openExplorer();
    setHidden(true);
}

// ----------------------------------------------------------------
void MainWindow::slotExplorerDone()
{
    _currentPath->setText(_explorer->get_path());
    setHidden(false);
}

// ----------------------------------------------------------------
void MainWindow::slotDeleteBoxChanged(int pState)
{
    if(pState==Qt::Unchecked)
    { _replaceBox->setChecked(true); enabledReplacePart(true); }
    else
    { _replaceBox->setChecked(false); enabledReplacePart(false);}
}

// ----------------------------------------------------------------
void MainWindow::slotReplaceBoxChanged(int pState)
{
    if(pState==Qt::Unchecked)
    { _deleteBox->setChecked(true); enabledReplacePart(false); }
    else
    { _deleteBox->setChecked(false); enabledReplacePart(true); }
}

// ----------------------------------------------------------------
void MainWindow::slotFormatBoxChanged(const QString& pFormat)
{
    _typeBox->clear();
    if(pFormat=="ADEXP")
    { _typeBox->addItems(_adexpTypeList); }
    else if(pFormat=="CAUTRA")
    { _typeBox->addItems(_cautraTypeList); }
    else if(pFormat=="OLDI")
    { _typeBox->addItems(_oldiTypeList); }
    else if(pFormat=="RFSTA")
    { _typeBox->addItems(_rfstaTypeList); }
}

// ----------------------------------------------------------------
void MainWindow::slotLaunchConvertion()
{
    //Check if delete Text is not empty
    if(_deleteText->text().isEmpty())
    {
        _deleteText->setStyleSheet("QLineEdit { border : 1px solid red; }");
        return;
    }
    else
    { _deleteText->setStyleSheet(""); }

    //TODO : Indiquer le nombre de fichier à modifier

    //Get XML Files
    QString lReplaceText="";
    if(_replaceText->isEnabled()) { lReplaceText=_replaceText->text(); }
    XmlParse(_explorer->get_allXmlFiles(),
                _deleteText->text(),
                lReplaceText,
                _formatBox->currentText(),
                _typeBox->currentText());
}

/* ----------------------------------------------------------------
 * Private Function
---------------------------------------------------------------- */
void MainWindow::enabledReplacePart(const bool& pEnabled)
{
    if(pEnabled)
    {
        _replaceTextName->setStyleSheet("QLabel { color: black; }");
        _replaceText->setEnabled(true);
    }
    else
    {
        _replaceTextName->setStyleSheet("QLabel { color: grey; }");
        _replaceText->setEnabled(false);
    }
}

// ----------------------------------------------------------------
void MainWindow::buildHMI()
{
    _mainWidget = new QWidget(this);
    _mainLayout = new QVBoxLayout(_mainWidget);


    // - First Line (Current Path and Explorer)
    _firstLineLayout = new QHBoxLayout();
    _currentPath = new QLabel(_explorer->get_path());
    _currentPath->setAlignment(Qt::AlignLeft);
    //TODO : Empêcher l'écriture d'agrandir la fenêtre et limité le nombre de caractère affiché
    _firstLineLayout->addWidget(_currentPath);
    QPushButton * _openExplorer = new QPushButton("...");
    //TODO : régler la taille du bouton
    connect(_openExplorer, SIGNAL(released()), this, SLOT(slotOpenExplorer()));
    _firstLineLayout->addWidget(_openExplorer);

    // - Second Line (Checkable Boxes)
    _secondLineLayout = new QHBoxLayout();
    _deleteBox = new QCheckBox("Suppression");
    _deleteBox->setChecked(true);
    connect(_deleteBox, SIGNAL(stateChanged(int)), this, SLOT(slotDeleteBoxChanged(int)));
    _secondLineLayout->addWidget(_deleteBox);
    _replaceBox = new QCheckBox("Remplacer");
    connect(_replaceBox, SIGNAL(stateChanged(int)), this, SLOT(slotReplaceBoxChanged(int)));
    _secondLineLayout->addWidget(_replaceBox);

    // - Third Line (Text to Delete)
    _thirdLineLayout = new QHBoxLayout();
    _deleteTextName = new QLabel("Texte à supprimer :");
    _thirdLineLayout->addWidget(_deleteTextName);
    _deleteText = new QLineEdit("");
    _thirdLineLayout->addWidget(_deleteText);

    // - Thourth Line (Text to Replace)
    _fourthLineLayout = new QHBoxLayout();
    _replaceTextName = new QLabel("Texte remplaçant : ");
    _fourthLineLayout->addWidget(_replaceTextName);
    _replaceText = new QLineEdit("");
    enabledReplacePart(false);
    _fourthLineLayout->addWidget(_replaceText);

    // - Fifth Line (Choose Format and Type)
    _fifthLineLayout = new QHBoxLayout();
    _formatBoxText = new QLabel("Format :");
    _fifthLineLayout->addWidget(_formatBoxText);
    _formatBox = new QComboBox();
    _formatBox->addItems(_formatList);
    connect(_formatBox, SIGNAL(currentIndexChanged(QString)), this, SLOT(slotFormatBoxChanged(QString)));
    _fifthLineLayout->addWidget(_formatBox);
    _typeBoxText = new QLabel("Type :");
    _fifthLineLayout->addWidget(_typeBoxText);
    _typeBox = new QComboBox();
    slotFormatBoxChanged(_formatBox->currentText());
    _fifthLineLayout->addWidget(_typeBox);

    // - Sixth Line (Launch convertion)
    QPushButton * _launchConvertion = new  QPushButton("Lancer la conversion");
    connect(_launchConvertion, SIGNAL(released()), this, SLOT(slotLaunchConvertion()));

    _mainLayout->addLayout(_firstLineLayout);
    _mainLayout->addLayout(_secondLineLayout);
    _mainLayout->addLayout(_thirdLineLayout);
    _mainLayout->addLayout(_fourthLineLayout);
    _mainLayout->addLayout(_fifthLineLayout);
    _mainLayout->addWidget(_launchConvertion);
    setCentralWidget(_mainWidget);
}

/* ----------------------------------------------------------------
 * Events
---------------------------------------------------------------- */
void MainWindow::closeEvent(QCloseEvent *)
{
    delete this;
}


MainWindow::~MainWindow()
{
    if(_explorer) { _explorer->close(); delete _explorer; }
    if(_currentPath) { delete _currentPath; }
    //HMI Widget
    if(_deleteBox) { delete _deleteBox; }
    if(_replaceBox) { delete _replaceBox; }
    if(_deleteTextName) { delete _deleteTextName; }
    if(_deleteText) { delete _deleteText; }
    if(_replaceTextName) { delete _replaceTextName; }
    if(_replaceText) { delete _replaceText; }
    if(_formatBoxText) { delete _formatBoxText; }
    if(_formatBox) { delete _formatBox; }
    if(_typeBoxText) { delete _typeBoxText; }
    if(_typeBox) { delete _typeBox; }
    //HMI Layout
    if(_firstLineLayout) { delete _firstLineLayout; }
    if(_secondLineLayout) { delete _secondLineLayout; }
    if(_thirdLineLayout) { delete _thirdLineLayout; }
    if(_fourthLineLayout) { delete _fourthLineLayout; }
    if(_fifthLineLayout) { delete _fifthLineLayout; }
    if(_mainWidget) { delete _mainWidget; }
}
