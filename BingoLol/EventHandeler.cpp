#include "EventHandeler.h"

EventHandeler::EventHandeler(BingoGrid* grid, SoundHandeler* soundHandeler, QWidget* parent) :
	QWidget(parent), m_bingoInQueue(false), m_parent(parent), m_grid(grid), m_soundHandeler(soundHandeler)
{
	//creating the timer that will check for event to handle every 2 sec
	m_timerThatCheckForEvent = new QTimer(this);
	QObject::connect(m_timerThatCheckForEvent, SIGNAL(timeout()), this, SLOT(handleFirstEventOfTheQueue()));
	m_timerThatCheckForEvent->start(2000);

	//connecting signal emited by the eventHandeler to slots that must be triggers in case of this event
	//in case the player finish a mission
	QObject::connect(m_grid, SIGNAL(missionFinished(AbstractMission*)), this, SLOT(addEventToQueue(AbstractMission*)));
	//in case the player finish a line
	QObject::connect(m_grid, SIGNAL(bingoWon()), this, SLOT(addBingoToQueue()));

	//emmiting signals once the event has been through the queue
	//in case of a bingo :
	QObject::connect(this, SIGNAL(eventBingoCompletedStarted()), m_soundHandeler, SLOT(playBingoWonSound()));
	//in case a mission is completed :
	QObject::connect(this, SIGNAL(eventMissionCompletedStarted()), m_soundHandeler, SLOT(playMissionSucceedSound()));
	//in case a mission is failed :
	QObject::connect(this, SIGNAL(eventMissionFailedStarted()), m_soundHandeler, SLOT(playMissionFailedSound()));
}

EventHandeler::~EventHandeler()
{

}

void EventHandeler::addEventToQueue(AbstractMission* event)
{
	m_eventQueue.push_back(event);
}

void EventHandeler::addBingoToQueue()
{
	m_bingoInQueue = true;
}

void EventHandeler::destroyQueue()
{
	m_eventQueue.clear();
}

void EventHandeler::handleFirstEventOfTheQueue()
{
	if (m_bingoInQueue)
	{
		emit eventBingoCompletedStarted();
		m_bingoInQueue = false;
	}
	else if (!m_eventQueue.empty())
	{
		if (m_eventQueue.front()->getIfMissionSucceed())
		{
			emit eventMissionCompletedStarted();
		}
		else
		{
			emit eventMissionFailedStarted();
		}
		m_eventQueue.pop_front();
	}
}

