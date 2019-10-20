#include "parameterdata.hpp"

#include <QDir>

// Logger
#include <QDebug>
#include "logger.hpp"

// XML
#include <QtXml>

/* ----------------------------------------------------------------------------------------
Public functions
---------------------------------------------------------------------------------------- */
bool ParameterData::is_first_start()
{
    return !_paramFile->exists();
}

// ----------------------------------------------------------------------------------------
bool ParameterData::first_start()
{
    // Creation of the param file
    if(!_paramFile->open(QIODevice::ReadWrite))
    { return false; }
    _paramFile->write("<?xml version=\"1.0\"?>\n");
    _paramFile->write("<parameters>\n");
    _paramFile->write("\t<last_open>");
    _paramFile->write(QDir().currentPath().toStdString().c_str());
    _paramFile->write("/example.xml");
    _paramFile->write("</last_open>\n");
    _paramFile->write("</parameters>\n");

    // Creation of the example database
    QFile lDatabaseFile(QDir().currentPath()+"/default_database.xml");
    if(!lDatabaseFile.open(QIODevice::ReadWrite))
    { return false; }
    lDatabaseFile.write("<?xml version=\"1.0\"?>\n");
    lDatabaseFile.write("<data>\n");

    lDatabaseFile.write("\t<settings>\n");
    lDatabaseFile.write("\t\t<app>\n");
    lDatabaseFile.write("\t\t</app>\n");
    lDatabaseFile.write("\t\t<desktop>\n");
    lDatabaseFile.write("\t\t</desktop>\n");
    lDatabaseFile.write("\t</settings>\n");
    lDatabaseFile.write("\n");

    lDatabaseFile.write("\t<reference name=\"Car\">\n");
    lDatabaseFile.write("\t\t<reference name=\"Fioul\">\n");
    lDatabaseFile.write("\t\t\t<reference name=\"Sans-Plomb 98\"/>\n");
    lDatabaseFile.write("\t\t\t<reference name=\"Ethanol\"/>\n");
    lDatabaseFile.write("\t\t</reference>\n");
    lDatabaseFile.write("\t\t<reference name=\"Insurance\"/>\n");
    lDatabaseFile.write("\t</reference>\n");

    lDatabaseFile.write("\t<reference name=\"Home\">\n");
    lDatabaseFile.write("\t\t<reference name=\"Insurance\">\n");
    lDatabaseFile.write("\t</reference>\n");
    lDatabaseFile.write("\n");

    lDatabaseFile.write("\t<payment>Card</payment>\n");
    lDatabaseFile.write("\t<payment>Transfer</payment>\n");
    lDatabaseFile.write("\t<payment>Cheque</payment>\n");
    lDatabaseFile.write("\n");

    lDatabaseFile.write("\t<account name=\"Compte Courant\" bankname=\"Credit Agricole\" currency=\"EUR\">\n");
    lDatabaseFile.write("\t\t<init>2500.00</init>\n");
    lDatabaseFile.write("\t\t<operation>\n");
    lDatabaseFile.write("\t\t\t<name>Op1</name>\n");
    lDatabaseFile.write("\t\t\t<date>2019-06-16</date>\n");
    lDatabaseFile.write("\t\t\t<amount>-95.55</amount>\n");
    lDatabaseFile.write("\t\t\t<reference>Voiture/Assurance</reference>\n");
    lDatabaseFile.write("\t\t\t<payment>Transfer</payment>\n");
    lDatabaseFile.write("\t\t\t<order>000001</order>\n");
    lDatabaseFile.write("\t\t\t<checked>False</checked>\n");
    lDatabaseFile.write("\t\t</operation>\n");
    lDatabaseFile.write("\t\t<operation>\n");
    lDatabaseFile.write("\t\t\t<name>Op2</name>\n");
    lDatabaseFile.write("\t\t\t<date>2019-06-16</date>\n");
    lDatabaseFile.write("\t\t\t<amount>95.55</amount>\n");
    lDatabaseFile.write("\t\t\t<reference>Voiture/Assurance</reference>\n");
    lDatabaseFile.write("\t\t\t<payment>Transfer</payment>\n");
    lDatabaseFile.write("\t\t\t<order>000002</order>\n");
    lDatabaseFile.write("\t\t\t<checked>True</checked>\n");
    lDatabaseFile.write("\t\t</operation>\n");
    lDatabaseFile.write("\n");

    //TODO: Faire les virements (crédit et Debit) automatiques;
    lDatabaseFile.write("\t\t<transfer>\n");

    lDatabaseFile.write("\t\t</transfer>\n");

    lDatabaseFile.write("\t</account>\n");

    lDatabaseFile.write("</data>\n");
    lDatabaseFile.close();
    return true;
}

// ----------------------------------------------------------------------------------------
bool ParameterData::load_param()
{
    if(!_paramFile->isOpen())
    {
        if(!_paramFile->open(QIODevice::ReadWrite))
        {
            qDebug(logCritical()) << "Impossible to open the param file";
            return false;
        }
    }

    QDomDocument lXmlDoc;
    lXmlDoc.setContent(_paramFile);

    // Extraction of the root markup
    QDomElement lRoot = lXmlDoc.documentElement();              //parameters
    if(lRoot.tagName() != "parameters")
    {
        qDebug(logCritical()) << "Parameter file: expected 'parameters' tagname, i have '" << lRoot.tagName() << '"';
        return false;
    }

    QDomElement lElement = lRoot.firstChild().toElement();
    // Path all elements
    while(!lElement.isNull())
    {
        // Register last open filed
        if(lElement.tagName() == "last_open")
        { _lastFileOpen = lElement.text(); }

        // Next component
        lElement = lElement.nextSibling().toElement();
    }

    qDebug(logInfo()) << "Last open filed : '" << _lastFileOpen << "'";

    return true;
}


/* ----------------------------------------------------------------------------------------
Constructor/Destructor
---------------------------------------------------------------------------------------- */
ParameterData::ParameterData()
{
    _paramFileName = "param.xml";
    _paramFile = new QFile(QDir().currentPath()+"/"+_paramFileName);
}

ParameterData::~ParameterData()
{
    if(_paramFile)
    {
        _paramFile->close();
        delete _paramFile;
    }
}
