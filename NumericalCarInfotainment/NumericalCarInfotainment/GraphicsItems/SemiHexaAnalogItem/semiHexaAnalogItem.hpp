#pragma once
#include <QObject>
#include <QGraphicsPathItem>

#include <QPainterPath>
#include <QBrush>
#include <QPen>
#include <QPointF>
#include <QPolygonF>
#include <QList>
#include <QGraphicsTextItem>

#include <QTimer>


class SemiHexaAnalogItem: public QObject, public QGraphicsPathItem
{
    Q_OBJECT
public:
    SemiHexaAnalogItem(const double& pSize);
    virtual ~SemiHexaAnalogItem();

    const QPointF& getOrigin();
    const QPointF& getSize() const { return _sizeFigure; }

    //Setter
    const bool setPosition(const QPointF& pPoint) { return setPosition(pPoint.x(), pPoint.y()); }
    const bool setPosition(const double& pX, const double& pY);
    const bool setPositionFromLeftPoint(const QPointF& pPoint)
    { return setPositionFromLeftPoint(pPoint.x(),pPoint.y()); }
    const bool setPositionFromLeftPoint(const double& pX, const double& pY);

    //Animation
    void launchAnimation();

private slots:
    void doTranslation();

private:
    //Initialisation des Items
    const QPainterPath createPath(const double& pSize);
    void createText();

    //Calculs
    void calculSize();

    // Conversion de données
    const double getMiddle(const double& pM) { return pM/2; }
    const double getRadian(const double& pAngle) { return pAngle*M_PI/180; }

    //Animation
    QTimer * _animationTimer;
    QPointF _pointToGo;
    double _animationTime;
    double _animationStepsTranslate;
    const unsigned char _animationInterval=19;
    unsigned char _animationSteps=0;

    //Données
    const double _xRect=200;
    const double _angleStart=30;
    const double _angleSize=_angleStart*2;
    const double _XSpace=0.7;
    QPointF _sizeFigure;
    QPointF _originPoint;
    QPolygonF _polygon;

    //Objets
    QList<QGraphicsTextItem> _textList;

    //Paramètres
    const QPen _pen = QPen(QColor(0,0,0),1, Qt::SolidLine, Qt::FlatCap, Qt::MiterJoin); //Contour
    const QBrush _brush = QBrush(QColor(255,255,255));    //Fond
};
