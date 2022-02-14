#pragma once

#include <string>
#include <queue>

#include <QObject>
#include <QWidget>
#include <QTimer>

#include "Missions/AbstractMission.h"
#include "SoundsOption.h"
#include "BingoGrid.h"
#include "SoundHandeler.h"

class EventHandeler : public QWidget
{
	Q_OBJECT
public:
	EventHandeler(BingoGrid* grid, SoundHandeler* soundHandeler, QWidget* parent = nullptr);
	~EventHandeler();

public slots:
	void addEventToQueue(AbstractMission* event);
	void addBingoToQueue();
	void destroyQueue();
	void handleFirstEventOfTheQueue();

signals:
	void eventBingoCompletedStarted();
	void eventMissionCompletedStarted();
	void eventMissionFailedStarted();

private:
	QWidget* m_parent;
	BingoGrid* m_grid;
	SoundHandeler* m_soundHandeler;
	QTimer* m_timerThatCheckForEvent;

	std::deque<AbstractMission*> m_eventQueue;
	bool m_bingoInQueue;
};