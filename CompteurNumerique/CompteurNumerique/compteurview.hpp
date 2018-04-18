#pragma once

#include <QObject>
#include <QGraphicsView>

class CompteurScene;

class CompteurView : public QGraphicsView
{
public:
    CompteurView();
    virtual ~CompteurView();

private:
    void init();

    CompteurScene * _compteurScene;
};
