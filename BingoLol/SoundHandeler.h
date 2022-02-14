#pragma once

#include <string>

#include <QObject>
#include <QWidget>
#include <QString>
#include <QSound>
#include <QSoundEffect>

#include "BingoGrid.h"

class SoundHandeler : public QWidget
{
	Q_OBJECT

public:
	SoundHandeler(QWidget* parent = nullptr);
	~SoundHandeler();

	enum  Sounds
	{
		MISSION_SUCCEED,
		MISSION_FAILED,
		BINGO_WON,
		SCREENSHOT,
		NUMBER_OF_SOUNDS // this must remain in last position, it's used to know the number of sounds
	};

public slots:
	void playSound(SoundHandeler::Sounds id);
	void playMissionSucceedSound();
	void playMissionFailedSound();
	void playBingoWonSound();
	void setVolumeLevel(float volume);
	void activateOrDesactivateSound(int state);

private:
	QWidget* m_parent;
	QSoundEffect m_soundPlayers[SoundHandeler::NUMBER_OF_SOUNDS];
	bool m_soundActivated;
};

