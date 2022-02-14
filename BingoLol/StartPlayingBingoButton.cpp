#include "StartPlayingBingoButton.h"

StartPlayingBingoButton::StartPlayingBingoButton(BingoGrid* grid, QWidget* parent) :
	QPushButton(parent), m_grid(grid), m_parent(parent), m_gameIsPlaying(false), m_isHovered(false)
{
	m_hoveredGif = new QMovie(":/resources/images/play-hovered.gif");

	m_startButtonPixmap.load(":/resources/images/play.png");
	m_startedButtonPixmap.load(":/resources/images/play-cliked.png");
	m_startButtonIcon.addPixmap(m_startButtonPixmap);
	m_startedButtonIcon.addPixmap(m_startedButtonPixmap);

	this->setStartButton();
	this->setObjectName("startButton");

	//creating the timer that will run the missions every 0.1 sec
	m_timerThatUpdtateMissions = new QTimer(this);
	m_timerThatUpdtateMissions->start(100);

	QObject::connect(m_timerThatUpdtateMissions, SIGNAL(timeout()), this, SLOT(runMissions()));
	QObject::connect(this, SIGNAL(clicked()), this, SLOT(togglePlayingGame()));
	QObject::connect(m_hoveredGif, SIGNAL(frameChanged(int)), this, SLOT(updateGifAnimation(int)));
}

StartPlayingBingoButton::~StartPlayingBingoButton()
{

}

void StartPlayingBingoButton::runMissions()
{
	if (m_gameIsPlaying)
	{
		m_grid->runMissions();
	}
}

void StartPlayingBingoButton::startPlayingGame()
{
	m_gameIsPlaying = true;
	this->setStartedButton();
}

void StartPlayingBingoButton::stopPlayingGame()
{
	m_gameIsPlaying = false;
	this->setStartButton();
}

void StartPlayingBingoButton::togglePlayingGame()
{
	if (m_gameIsPlaying)
	{
		this->stopPlayingGame();
	}
	else
	{
		this->startPlayingGame();
	}
}

void StartPlayingBingoButton::enterEvent(QEvent*)
{
	m_hoveredGif->start();
	m_isHovered = true;
}

void StartPlayingBingoButton::leaveEvent(QEvent*)
{
	m_hoveredGif->stop();
	m_isHovered = false;
	this->setCorrectButtonImage();
}

void StartPlayingBingoButton::setStartButton()
{
	this->setIcon(m_startButtonIcon);
	this->setIconSize(m_startButtonPixmap.rect().size());
}

void StartPlayingBingoButton::setStartedButton()
{
	this->setIcon(m_startedButtonIcon);
	this->setIconSize(m_startedButtonPixmap.rect().size());
}

void StartPlayingBingoButton::updateGifAnimation(int frame)
{
	if (!m_gameIsPlaying && m_isHovered)
	{
		this->setIcon(QIcon(m_hoveredGif->currentPixmap()));
	}
}

void StartPlayingBingoButton::setCorrectButtonImage()
{
	if (m_gameIsPlaying)
	{
		this->setStartedButton();
	}
	else
	{
		this->setStartButton();
	}
}