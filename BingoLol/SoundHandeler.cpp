#include "SoundHandeler.h"

SoundHandeler::SoundHandeler(QWidget* parent) :
	QWidget(parent), m_parent(parent), m_soundActivated(true)
{
	//initialise the volume to every sounds players
	for (int i = 0; i < SoundHandeler::NUMBER_OF_SOUNDS - 1; ++i)
	{
		m_soundPlayers[i].setVolume(0.5);
	}

	m_soundPlayers[SoundHandeler::MISSION_SUCCEED].setSource(QUrl::fromLocalFile(":/resources/sounds/MissionSucceedSound.wav"));
	m_soundPlayers[SoundHandeler::MISSION_FAILED].setSource(QUrl::fromLocalFile(":/resources/sounds/MissionFailedSound.wav"));
	m_soundPlayers[SoundHandeler::BINGO_WON].setSource(QUrl::fromLocalFile(":/resources/sounds/BingoSucceedSound.wav"));
	m_soundPlayers[SoundHandeler::SCREENSHOT].setSource(QUrl::fromLocalFile(":/resources/sounds/ScreenshotSound.wav"));
}

SoundHandeler::~SoundHandeler()
{

}

void SoundHandeler::playSound(SoundHandeler::Sounds id)
{
	if (m_soundActivated)
	{
		m_soundPlayers[id].play();
	}
}

void SoundHandeler::playMissionSucceedSound()
{
	this->playSound(SoundHandeler::MISSION_SUCCEED);
}

void SoundHandeler::playMissionFailedSound()
{
	this->playSound(SoundHandeler::MISSION_FAILED);
}

void SoundHandeler::playBingoWonSound()
{
	this->playSound(SoundHandeler::BINGO_WON);
}

void SoundHandeler::setVolumeLevel(float volume)
{
	//set the volume to every sounds players
	for (int i = 0; i < SoundHandeler::NUMBER_OF_SOUNDS - 1; ++i)
	{
		m_soundPlayers[i].setVolume(volume);
	}
}

void SoundHandeler::activateOrDesactivateSound(int state)
{
	if (state == 2)
	{
		m_soundActivated = true;
	}
	else
	{
		m_soundActivated = false;
	}
}