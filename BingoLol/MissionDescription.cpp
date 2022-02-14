#include "MissionDescription.h"

MissionDescription::MissionDescription(QWidget* parent) : QLabel(parent)
{
	this->setMinimumHeight(85);
	this->setText("Hover a cell to see the mission description");
}