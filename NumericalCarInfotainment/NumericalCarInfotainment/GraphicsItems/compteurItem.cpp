#include "compteurItem.hpp"
#include "GraphicsItems/aiguilleitem.hpp"
#include <QRect>
#include <QBrush>
#include <QPainter>
#include <QTimer>
#include <QDebug>
#include <math.h>

/* ------------------------------------------------
 * Constructeur
 * ------------------------------------------------*/
CompteurItem::CompteurItem(const double& pSize, const QList<QString>& pNumber, const QString& pText)
{
    _size = pSize;
    initCircle();
    initAiguille();
    initNumber(pNumber, pText);
    searchAngleBySpeed(pNumber);
    calculSize();
}

/* ------------------------------------------------
 * Fonction d'initialisation
 * ------------------------------------------------*/
void CompteurItem::initCircle()
{
    /* Création du grand cercle */
    double lHalfSize = _size/2;
    _Circle = new QGraphicsEllipseItem(-lHalfSize, -lHalfSize, _size, _size,this);
    _Circle->setPos(lHalfSize, lHalfSize);
    _Circle->setPen(_bleu);
    _Circle->setBrush(_blanc);
    _Circle->setZValue(-1);
    /* Création du cercle central */
    double lLittleSize = lHalfSize*_littleCircleValue;
    _LittleCircle = new QGraphicsEllipseItem(-lLittleSize/2, -lLittleSize/2, lLittleSize, lLittleSize, this);
    _LittleCircle->setPos(lHalfSize, lHalfSize);
    _LittleCircle->setZValue(2);
    _LittleCircle->setBrush(_rouge);
}

// ------------------------------------------------
void CompteurItem::initAiguille()
{
    double lHalfSize = _size/2;
    _Aiguille = new AiguilleItem(lHalfSize, lHalfSize*0.1);
    _Aiguille->setPos(lHalfSize, lHalfSize);
    _Aiguille->setBrush(QBrush(QColor(255,0,0)));
    _Aiguille->setRotation(135);
    addToGroup(_Aiguille);
}

// ------------------------------------------------
void CompteurItem::initNumber(const QList<QString>& pNumberList,
                                 const QString& pText)
{
    double lRayon = _size/2;
    /* Détermine les angles entre chaque nombre */
    double lStep = _numberArea/(pNumberList.size()-1);
    double lAngle=135;
    foreach(const QString it, pNumberList)
    {
        // Conversion de l'angle en radian
        double lRAngle = conversionDegreeToRadian(lAngle);
        // On calcule leurs coordonnées sur un cercle de rayon 1
        double x = cos(lRAngle)*lRayon*_distanceToCircle;
        double y = sin(lRAngle)*lRayon*_distanceToCircle;
        // On ramène leur position au centre du cercle
        x += lRayon;
        y += lRayon;
        // On créé l'objet
        QGraphicsTextItem * lItem = new QGraphicsTextItem(it,this);
        lItem->setDefaultTextColor(Qt::black);
        double lScale = _size*_scaleText;
        lItem->setScale(lScale);
        // On récupère la taille du texte pour qu'il soit dans le cercle
        QRectF lSize = lItem->boundingRect();
        x -= ((lSize.width())/2)*lScale;
        y -= ((lSize.height())/2)*lScale;
        // Puis on place l'objet
        lItem->setPos(x,y);
        // Et on le sauvegarde
        _NumberList << lItem;
        // Puis on calcule le nouvel angle
        lAngle+=lStep;
    }
    /* Création du petit Texte "KM/H" */
    _Unity = new QGraphicsTextItem(pText,this);
    _Unity->setDefaultTextColor(Qt::black);
    QRectF lSize = _Unity->boundingRect();
    double lScale = _size*_scaleText;
    _Unity->setScale(lScale);
    _Unity->setPos(((_size/2)-(lSize.width()/2)*lScale), _size*0.85);
    _Unity->setZValue(1);
    /* Création du texte affichant la vitesse */
    _SpeedNumber = new QGraphicsTextItem("0",this);
    _SpeedNumber->setDefaultTextColor(Qt::black);
    changeSpeedValue(0);
}

/* ------------------------------------------------
 * Fonction d'animation
 * ------------------------------------------------*/
void CompteurItem::launchInitAnimation()
{
    /* Déclaration de l'animation */
    _animationTimer = new QTimer();
    _animationTimer->setInterval(_animationInterval);
    QObject::connect(_animationTimer, SIGNAL(timeout()), this, SLOT(doRotation()));
    _animationTime=1400;
    _animationSteps=0;
    /* Calcul de l'angle pour chaque rotation */
    const double lTotalAngle = (_maxAngle-_minAngle)*2;
    _animationStepsAngle=lTotalAngle/((_animationTime/1000)*48);
    _animationTimer->start();

    //_Aiguille->launchInitAnimation(_minAngle, _maxAngle);
}

// ------------------------------------------------
void CompteurItem::doRotation()
{
    double lRotation = _Aiguille->rotation();
    if(_animationSteps==0 && lRotation>395) //360+45
    {
        _animationSteps=1;
        _animationStepsAngle = 0-_animationStepsAngle;
    }
    else if(_animationSteps==1 && lRotation==135)
    {
        _animationSteps=2;
        _animationTimer->stop();
        changeSpeedValue(0);
        return;
    }
    double lNewRotation = lRotation+_animationStepsAngle;
    _Aiguille->setRotation(lNewRotation);
    changeSpeedValueAngle(lNewRotation);
}

// ------------------------------------------------
void CompteurItem::changeSpeedValueAngle(const double& lAngle)
{
    if(_angleSpeedStep==0)
    {
        qDebug() << "Error Speed Step is null, impossible to display the speed";
        return;
    }
    int i=0;
    while(((_angleSpeedStep*i)+_minAngle)<lAngle) i++;
    changeSpeedValue(i);
}

// ------------------------------------------------
void CompteurItem::changeSpeedValue(const unsigned int& lAngle)
{
    _SpeedNumber->setPlainText(QString::number(lAngle));
    QRectF lSize = _SpeedNumber->boundingRect();
    double lScale = _size*_scaleSpeed;
    _SpeedNumber->setScale(lScale);
    _SpeedNumber->setPos(((_size/2)-(lSize.width()/2)*lScale), _size*0.7);
}

/* ------------------------------------------------
 * Fonction de calcul et de conversio
 * ------------------------------------------------*/
void CompteurItem::searchAngleBySpeed(const QList<QString> &pNumber)
{
    _angleSpeedStep=0;
    bool ok;
    const unsigned int lMinSpeed = pNumber.value(0).toInt(&ok, 10);
    if(!ok)
    {
        qDebug() << "[Compteur Vitesse] Incorrect Value of Min Speed"
                 << pNumber.value(0);
        return;
    }
    const unsigned int lMaxSpeed = pNumber.last().toInt(&ok, 10);
    if(!ok)
    {
        qDebug() << "[Compteur Vitesse] Incorrect Value of Max Speed : "
                 << pNumber.last();
        return;
    }
    const double lPossibleValue = lMaxSpeed-lMinSpeed;
    _angleSpeedStep = _numberArea/lPossibleValue;
}

// ------------------------------------------------
double CompteurItem::conversionDegreeToRadian(const double &lAngle) const
{
    double newAngle;
    newAngle = lAngle*2*M_PI;
    newAngle = newAngle/360;
    return newAngle;
}

// ------------------------------------------------
void CompteurItem::calculSize()
{
    _rightOriginPoint.setX(_size+x());
    _rightOriginPoint.setY((_size/2)+y());
}


/* ------------------------------------------------
 * Destructeur
 * ------------------------------------------------*/
CompteurItem::~CompteurItem()
{
    if(_animationTimer) delete _animationTimer;
    if(_Circle) delete _Circle;
    if(_LittleCircle) delete _LittleCircle;
    if(_Aiguille) delete _Aiguille;
    foreach(QGraphicsTextItem * it, _NumberList) delete it;
    if(_Unity) delete _Unity;
    if(_SpeedNumber) delete _SpeedNumber;
}
