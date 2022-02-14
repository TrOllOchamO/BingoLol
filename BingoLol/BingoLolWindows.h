#pragma once

#include <chrono>
#include <thread>

#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QGridLayout>
#include <QFile>
#include <QIODevice>

#include "BingoGrid.h"
#include "BingoOptions.h"
#include "MissionDescription.h"

class BingoLolWindows : public QWidget
{
	Q_OBJECT

public:
	BingoLolWindows();

public slots:
	void setWindowsSize(int gridSize);

private:
	BingoGrid* m_bingoGrid;
	BingoOptions* m_bingoOptions;
	MissionDescription* m_missionDescription;
};

