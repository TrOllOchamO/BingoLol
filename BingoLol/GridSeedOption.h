#pragma once

#include <QObject>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QPushButton>
#include <QRegExpValidator>
#include <QClipboard>

#include "BingoGrid.h"
#include "StartPlayingBingoButton.h"
#include "EventHandeler.h"
#include "ClickableImage.h"


class GridSeedOption : public QWidget
{
	Q_OBJECT
public:
	GridSeedOption(BingoGrid* grid, EventHandeler* eventHandeler, StartPlayingBingoButton* startPlayingBingoButton, QWidget* parent = nullptr);
	~GridSeedOption();
	

public slots:
	void setSeed();
	void updateSeedDisplay();
	void copySeedToClipboard();

private:
	QWidget* m_parent;
	BingoGrid* m_grid;
	EventHandeler* m_eventHandeler;
	StartPlayingBingoButton* m_startPlayingBingoButton;

	QVBoxLayout* m_mainLayout;
	QHBoxLayout* m_inputLayout;

	QLabel* m_seedDisplay;
	QLineEdit* m_seedInput;
	ClickableImage* m_buttonCopySeedToClipboard;
	QPushButton* m_buttonSetSeed;
	QRegExpValidator* m_seedValidator;
};
