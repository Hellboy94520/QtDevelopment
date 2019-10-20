#include "mainView.hpp"
#include "analogScene.hpp"
#include "Parameters/parametersManagers.hpp"

#include <QRect>
#include <QApplication>
#include <QDesktopWidget>

MainView::MainView()
{
    init();
    _analogScene->launchInitAnimation();
}

void MainView::init()
{
    QRect lScreen = QApplication::desktop()->screenGeometry();
    ScreenParam * lParam = ParametersManagers::get_instance()->getScreenParam();
    lParam->setHeight(lScreen.height());
    lParam->setWidth(lScreen.width());

    _analogScene = new AnalogScene;
    _analogScene->setSceneRect(lScreen);
    setScene(_analogScene);
}

MainView::~MainView()
{
    if(_analogScene) delete _analogScene;
}
