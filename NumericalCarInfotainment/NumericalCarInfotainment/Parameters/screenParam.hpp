#pragma once

#include <QRectF>

class ScreenParam
{
public:    
    //Getter
    const unsigned int& getWidth() const { return _screenWidth; }
    const unsigned int& getHeight() const { return _screenHeigth; }

    //Setter
    void setWidth(const unsigned int& pWidth) { _screenWidth=pWidth; }
    void setHeight(const unsigned int& pHeight) { _screenHeigth=pHeight; }

private:
    void update()
    {
        //_centerCoordona);
    }

    unsigned int _screenWidth;
    unsigned int _screenHeigth;
    QRectF _centerCoordonate();
};
