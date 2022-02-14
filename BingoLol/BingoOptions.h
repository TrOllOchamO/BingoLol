#pragma once

#include <vector>
#include <iostream>
#include <string>

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QRadioButton>
#include <QTimer>
#include <QLineEdit>
#include <QLabel>
#include <QRegExp>
#include <QRegExpValidator>

#include "BingoGrid.h"
#include "SoundsOption.h"
#include "SoundHandeler.h"
#include "GridSizeOption.h"
#include "GridSeedOption.h"
#include "StartPlayingBingoButton.h"
#include "EventHandeler.h"
#include "ShareOption.h"


class BingoOptions : public QWidget
{
	Q_OBJECT

public:
	BingoOptions(BingoGrid* bingoGrid, QWidget* parent = nullptr);
	~BingoOptions();

public slots:

private:
	QWidget* m_parent;
	BingoGrid* m_bingoGrid;

	QVBoxLayout* m_mainLayout;

	QLabel* m_bingoLolSection;
	QLabel* m_soundSection;
	QLabel* m_gridSection;

	SoundHandeler* m_soundHandeler;
	EventHandeler* m_eventHandeler;
	GridSizeOption* m_gridSizeOption;
	GridSeedOption* m_gridSeedOption;
	ShareOption* m_shareOption;
	SoundsOption* m_soundOptions;
	StartPlayingBingoButton* m_startStopPlayingButton;
};