#pragma once

#include <QObject>
#include <QFile>

class Trace : public QObject
{
  Q_OBJECT
public:
  /* @brief création d'un gestionnaire de fichier */
  static Trace * init(const unsigned char);
  /* création de l'unique instance de la classe */
  static Trace * get_instance();

  const bool& isLogReady() const { return _isLogReady; }
  bool closeLog() const;

  void FATAL(const QString& pMes); //0
  void ERROR(const QString& pMes); //1
  void INFO(const QString& pMes);  //2
  void DEBUG(const QString& pMes, const QString& pClasse, const QString& pFonction); //3
  void DDEBUG(const QString& pMes, const QString& pClasse, const QString& pFonction);//4
  
private:
  void writeLog(const QString& pMes);
  
  QString _FileName;
  QFile * _File;
  
  Trace(const unsigned char);
  virtual ~Trace();

  static Trace * _instance;

  bool _isLogReady;
  unsigned char _traceLevel;
};
