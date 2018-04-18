#include "compteurview.hpp"
#include "compteurscene.hpp"
#include "Parameters/parametersManagers.hpp"
#include "Parameters/screenParam.hpp"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

CompteurView::CompteurView()
{
    init();
    _compteurScene->launchInitAnimation();
}

void CompteurView::init()
{
    QRect lScreen = QApplication::desktop()->screenGeometry();
    ScreenParam * lParam = ParametersManagers::get_instance()->getScreenParam();
    lParam->setScreenHeight(lScreen.height());
    lParam->setScreenWidth(lScreen.width());

    _compteurScene = new CompteurScene(lScreen);
    _compteurScene->setSceneRect(lScreen);
    setScene(_compteurScene);
}

CompteurView::~CompteurView()
{
    if(_compteurScene) delete _compteurScene;
}
