#pragma once

#include <QWidget>
#include <QLabel>
#include <QFontDatabase>
#include <QString>

class MissionDescription : public QLabel
{
	Q_OBJECT

public:
	MissionDescription(QWidget* parent = nullptr);
};