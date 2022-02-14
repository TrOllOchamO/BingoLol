#pragma once

#include <QApplication>
#include <QWidget.h>
#include <QFile>
#include <QIODevice>
#include <QFontDatabase>

class UsefullFunc
{
public:
	UsefullFunc();
	~UsefullFunc();
	static void refreshStyleSheet(QWidget* widget);
	static void refreshStyleSheet(QApplication& app);
	static void importUsedFonts();
};

