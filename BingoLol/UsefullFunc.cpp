#include "UsefullFunc.h"

UsefullFunc::UsefullFunc()
{

}


UsefullFunc::~UsefullFunc()
{

}

void UsefullFunc::refreshStyleSheet(QWidget* widget)
{
    QFile file(":/resources/styleSheets/stylesheet.qss");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        widget->setStyleSheet(file.readAll());
        file.close();
    }
}

void UsefullFunc::refreshStyleSheet(QApplication& app)
{
    QFile file(":/resources/styleSheets/stylesheet.qss");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        app.setStyleSheet(file.readAll());
        file.close();
    }
}

void UsefullFunc::importUsedFonts()
{
    QFontDatabase::addApplicationFont(":/resources/fonts/friz-quadrata-std-bold.otf");
    QFontDatabase::addApplicationFont(":/resources/fonts/friz-quadrata-std-bold-italic.otf");
    QFontDatabase::addApplicationFont(":/resources/fonts/friz-quadrata-std-italic.otf");
    QFontDatabase::addApplicationFont(":/resources/fonts/friz-quadrata-std-medium.otf");
}