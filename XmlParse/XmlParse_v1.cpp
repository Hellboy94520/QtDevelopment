#include "XmlParse.hpp"

#include <QDomDocument>
#include <QFile>
#include <QDebug>
#include <QByteArray>

const QString XmlParse::toHexa(const QString& pString)
{
    QByteArray lByte;
    lByte.append(pString);

    return QString(lByte.toHex()).toUpper();
}

const QString XmlParse::toAscii(const QString& pString)
{
    QByteArray lByte;
    lByte.append(pString);
    lByte = QByteArray::fromHex(lByte);
    return QString(lByte);
}


XmlParse::XmlParse(const QStringList& pFileList, const QString& pDelete,
                   const QString& pReplace, const QString& pFormat,
                   const QString& pType)
{
    for(int i=0; i<pFileList.size(); ++i)
    {
        parseXml(pFileList.value(i), pDelete, pReplace, pFormat, pType);
    }
}

void XmlParse::parseXml(const QString& pFileName, const QString& pDelete,
                        const QString& pReplace, const QString& pFormat,
                        const QString& pType)
{
    //Préparation du fichier XML
    QDomDocument doc("mydocument");
    QFile lFile(pFileName);
    if(!lFile.open(QIODevice::ReadWrite))
    {
        qDebug() << "Impossible to open file \'" << pFileName << "\'";
        return;
    }
    if(!doc.setContent(&lFile))
    {
        qDebug() << "Impossible de parther le fichier \'" << pFileName << "\'";
        lFile.close();
        return;
    }
    lFile.close();

    //Conversion des données en hexa
    QString lDeleteHex = XmlParse::toHexa(pDelete);
    QString lReplaceHex = "";
    if(!pReplace.isEmpty()) { lReplaceHex = XmlParse::toHexa(pReplace); }
    // Afficher les conversions

    //<nodeName element="attribute">text</nodeName>*/
    QDomNodeList n1 = doc.elementsByTagName("message");
    for(int i=0; i<n1.size(); i++)
    {
        QDomElement e1 = n1.at(i).toElement();
        qDebug() << e1.attribute("format","") << "-" << e1.attribute("type","");
        if(pFormat=="TOUS" || e1.attribute("format","null")==pFormat)
        {
            if(pFormat=="TOUS" || pType=="TOUS" || e1.attribute("type","null")==pType)
            {
                qDebug() << "Conversion en cours...";
                QDomNodeList n2 = doc.elementsByTagName("contenu");
                QDomElement e2 = n2.at(i).toElement();
                qDebug() << e2.text();
                if(e2.text().contains(lDeleteHex))
                {
                    //TODO : Remplacer ou supprimer selon le choix
                }
                qDebug() << e2.text().contains(lDeleteHex);
            }
        }

    }


}
