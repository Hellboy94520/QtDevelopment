#pragma once


class ScreenParam
{
public:
    //Getter
    const unsigned int& getScreenWidth() const { return _screenWidth; }
    const unsigned int& getScreenHeight() const { return _screenHeigth; }

    //Setter
    void setScreenWidth(const unsigned int& pWidth) { _screenWidth=pWidth; }
    void setScreenHeight(const unsigned int& pHeight) { _screenHeigth=pHeight; }

private:
    unsigned int _screenWidth;
    unsigned int _screenHeigth;
};
