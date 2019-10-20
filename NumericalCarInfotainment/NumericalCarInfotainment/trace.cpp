#include "Trace.hpp"
#include <QDateTime>
#include <QTextStream>

Trace * Trace::_instance = NULL;

Trace * Trace::init(const unsigned char pLogLevel)
{
  if(_instance==NULL)
    {
      _instance = new Trace(pLogLevel);
    }
  return _instance;
}

Trace * Trace::get_instance()
{
  if(_instance) return _instance;
  return 0;
}

bool Trace::closeLog() const
{
  _File->close();
  return _File->isOpen();
}

void Trace::FATAL(const QString& pMes)
{
  QString lMes = "FATAL - " + pMes;
  writeLog(lMes);
  _File->close();
  exit(1);
  // A FAIRE FERMER LAPPLICATION
}

void Trace::ERROR(const QString& pMes)
{
  if(_traceLevel>0)
    {
      QString lMes = "ERROR - " + pMes;
      writeLog(lMes);
    }
}

void Trace::INFO(const QString& pMes)
{
  if(_traceLevel>1)
    {
      QString lMes = "INFO - " + pMes;
      writeLog(lMes);
    }
}

void Trace::DEBUG(const QString& pMes, const QString& pClasse, const QString& pFonction)
{
  if(_traceLevel>2)
    {
      QString lMes = "DEBUG - in class : " + pClasse + ", in function : " + pFonction + ", " + pMes;
      writeLog(lMes);
    }
}

void Trace::DDEBUG(const QString& pMes, const QString& pClasse, const QString& pFonction)
{
  if(_traceLevel>3)
    {
      QString lMes = "DDEBUG - in class : " + pClasse + ", in function : " + pFonction + ", " + pMes;
      writeLog(lMes);
    }
}

void Trace::writeLog(const QString& pMes)
{
  QString lMes = QDateTime::currentDateTime().toString("yyyy.MM.dd-HH:mm:ss:zzz");
  lMes += (" : " + pMes);
  
  /* On écrit dans le fichier */
  QTextStream out(_File);
  out << lMes << "\n";
}


Trace::Trace(const unsigned char pLogLevel)
{
  /* On récupère la date et l'heure courante pour créer le fichier de log */
  _FileName = QDateTime::currentDateTime().toString("yyyyMMdd-HHmmss");
  _File = new QFile(_FileName+".log");
  _isLogReady = _File->open(QIODevice::ReadWrite);
  if(!_isLogReady) return;
  _traceLevel=pLogLevel;
  INFO("Initialisation Trace Class OK");
  INFO("Class Level is " + QString::number(pLogLevel));
}

Trace::~Trace()
{
  // A FAIRE
  _File->close();
  if(_File) { delete _File; }
  delete _instance;
}
