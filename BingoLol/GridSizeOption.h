#pragma once

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QPushButton>

#include "BingoGrid.h"
#include "EventHandeler.h"
#include "StartPlayingBingoButton.h"

class GridSizeOption : public QWidget
{
	Q_OBJECT
public:
	GridSizeOption(BingoGrid* grid, StartPlayingBingoButton* startStopPlayingButton, EventHandeler* eventHandeler, QWidget* parent = nullptr);
	~GridSizeOption();

public slots:
	void generateGrid();

private:
	QWidget* m_parent;
	BingoGrid* m_bingoGrid;
	EventHandeler* m_eventHandeler;
	StartPlayingBingoButton* m_startStopPlayingButton;

	QVBoxLayout* m_mainLayout;
	QRadioButton* m_grid5;
	QRadioButton* m_grid4;
	QPushButton* m_buttonGetNewGrid;
	QPushButton* m_buttonResetMissions;
};