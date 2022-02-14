#pragma once

#include <string>

#include <QObject>
#include <QWidget>
#include <QPushButton>
#include <QPixmap>
#include <QIcon>
#include <QMovie>

#include "BingoGrid.h"
#include "UsefullFunc.h"

class StartPlayingBingoButton : public QPushButton
{
	Q_OBJECT
public:
	StartPlayingBingoButton(BingoGrid* grid, QWidget* parent = nullptr);
	~StartPlayingBingoButton();

public slots:
	void startPlayingGame();
	void stopPlayingGame();
	void togglePlayingGame();
	void runMissions();
	void setStartButton();
	void setStartedButton();
	void setCorrectButtonImage();
	void updateGifAnimation(int frame);

signals:
	void hovered();
	void notHovered();

private:
	void enterEvent(QEvent*);
	void leaveEvent(QEvent*);

	QWidget* m_parent;
	BingoGrid* m_grid;

	QPixmap m_startButtonPixmap;
	QPixmap m_startedButtonPixmap;
	QIcon m_startButtonIcon;
	QIcon m_startedButtonIcon;
	QMovie* m_hoveredGif;

	bool m_gameIsPlaying;
	bool m_isHovered;
	QTimer* m_timerThatUpdtateMissions;
};