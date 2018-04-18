#include "compteurItemv2.hpp"
#include "trace.hpp"

#include <QDebug>

/* -------------------------------------------------
 *  Constructor
 * ------------------------------------------------- */
CompteurItemV2::CompteurItemV2(const double& pSize)
{
    QPainterPath lPainterPath = createPath(pSize);

    //Design
    setPen(_pen);
    setBrush(_brush);
    setPath(lPainterPath);
    Trace::get_instance()->INFO("CompteurItemV2 is created");
}

/* -------------------------------------------------
 *  Initialisation
 * ------------------------------------------------- */
const QPainterPath CompteurItemV2::createPath(const double& pSize)
{
    QPainterPath lPainterPath;

    const double lRadius = getMiddle(pSize);
    const double lXMoveFromCircle2 = lRadius*_XSpace;

    QPointF lPoint0;
    lPoint0.setX(cos(getRadian(_angleStart))*lRadius);
    lPoint0.setY(sin(getRadian(_angleStart))*lRadius);

    //Origine
    lPainterPath.moveTo(lPoint0);

    //Line 1
    QPointF lPoint1 = lPoint0;
    lPoint1.setX(lPoint0.x()+lXMoveFromCircle2);    //On prends en compte le décalage entre les deux cercles
    lPainterPath.lineTo(lPoint1);

    //Circle 1
    lPainterPath.arcTo(-lRadius+lXMoveFromCircle2,0,
                    pSize,pSize,
                    _angleStart,-_angleSize);

    QPointF lPoint2;
    lPoint2.setX(lRadius+lXMoveFromCircle2);
    lPoint2.setY(lRadius);

    QPointF lPoint3;
    lPoint3.setX(lPoint1.x());
    lPoint3.setY(-sin(getRadian(_angleStart))*lRadius);

    //Line 2
    QPointF lPoint4;
    lPoint4.setX(lPoint0.x());
    lPoint4.setY(lPoint1.y()+lRadius);
    lPainterPath.lineTo(lPoint4);

    //Circle 2
    lPainterPath.arcTo(-lRadius,0,
                       pSize,pSize,
                       -_angleStart,_angleSize);



    QPointF lPoint5;
    lPoint5.setX(lPoint2.x()-lXMoveFromCircle2);
    lPoint5.setY(lPoint2.y());

    _polygon << lPoint0 << lPoint1 << lPoint2 << lPoint3 << lPoint4 << lPoint5;
    //qDebug() << _polygon << lXMoveFromCircle2 << lRadius;

    //End Shape
    lPainterPath.closeSubpath();

    calculSize();

    return lPainterPath;
}

// -------------------------------------------------
void CompteurItemV2::createText()
{
    QList<QString> lTextList;
    lTextList << "EMPTY" << "1/4" << "1/2" << "3/4" << "FULL";
    foreach(QString it, lTextList)
    {
        QGraphicsTextItem lText(it);
        lText.setDefaultTextColor(Qt::black);
        //double lScale =
    }
}


/* -------------------------------------------------
 * Setter
 * ------------------------------------------------- */
const bool CompteurItemV2::setPosition(const double &pX, const double &pY)
{
    setPos(pX-_originPoint.x(), pY-_originPoint.y());
    return true;
}

// -------------------------------------------------
const bool CompteurItemV2::setPositionFromLeftPoint(const double &pX, const double &pY)
{
    setPos(pX-_polygon.at(5).x(), pY-_polygon.at(5).y());
}


/* -------------------------------------------------
 *
 * ------------------------------------------------- */
void CompteurItemV2::calculSize()
{
    _sizeFigure.setX(_polygon.at(3).x()-_polygon.at(0).x());
    _sizeFigure.setY(_polygon.at(4).y()-_polygon.at(0).y());
    //qDebug() << _sizeFigure << _polygon;
    getOrigin();
}


/* -------------------------------------------------
 *
 * ------------------------------------------------- */
const QPointF& CompteurItemV2::getOrigin()
{
    _originPoint.setX((_sizeFigure.x()/2)-_polygon.at(5).x());
    _originPoint.setY((_sizeFigure.y()/2)-_polygon.at(0).y());
    return _originPoint;
}

/* -------------------------------------------------
 * Animation
 * ------------------------------------------------- */
void CompteurItemV2::launchAnimation()
{
    /* Déclaration de l'animation */
    _animationTimer = new QTimer();
    _animationTimer->setInterval(_animationInterval);
    QObject::connect(_animationTimer, SIGNAL(timeout()), this, SLOT(doTranslation()));
    _animationTime=1400;
    _animationSteps=1;
    /* Calcul de la position pour chaque iteration */
    const double distance = _sizeFigure.x();
    qDebug() << "Distance : " << distance;
    _animationStepsTranslate=distance/((_animationTime/1000)*48);
    qDebug() << "Animation Steps : " << _animationStepsTranslate;
    qDebug() << "Position courante : " << x() << _polygon.at(5).x();
    _pointToGo.setX(x()+distance);
    _pointToGo.setY(y());
    _animationTimer->start();
}

// -------------------------------------------------
void CompteurItemV2::doTranslation()
{
    if(x()<=_pointToGo.x())
    {
        setX(x()+_animationStepsTranslate);
    }
    else
    {
        _animationTimer->stop();
    }
}


/* -------------------------------------------------
 * Destructeur
 * ------------------------------------------------- */
CompteurItemV2::~CompteurItemV2()
{
    if(_animationTimer) { delete _animationTimer; }
}

