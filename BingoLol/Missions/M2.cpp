#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Should i b ?"
#define MISSION_DESCRIPTION "Stay alive 1min30 with your HP below 40%."

M2::M2() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_wasUnder40Percent(false), m_whenDidHeWasUnder40Percent(0)
{
	m_inRealTime = true;
}


M2::~M2()
{

}


bool M2::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	bool isActivePlayerDead(Missions::getIfSummonerIsDead(m_gameData, playerName));
	int gameTime(Missions::getGameTime(m_gameData));

	if (isActivePlayerDead)
	{
		m_wasUnder40Percent = false;
		return false;
	}
	else
	{
		int playerHealth(Missions::getActivePlayerCurrentHealth(m_gameData));
		int playerMaxHealth(Missions::getActivePlayerMaxHealth(m_gameData));

		if (m_wasUnder40Percent) //he was alredy below 40%
		{
			if (playerHealth < playerMaxHealth * 0.4) //he didnt regen 
			{

				if (gameTime - m_whenDidHeWasUnder40Percent >= 90) //the player is under 40% since 1min30
				{ 
					m_isMissionDone = true;
					return true;
				}
				return false;
			}
			else //he has regen
			{
				m_wasUnder40Percent = false;
				return false;
			}
		}
		else
		{
			if (playerHealth < playerMaxHealth * 0.4)
			{
				m_wasUnder40Percent = true;
				m_whenDidHeWasUnder40Percent = gameTime;
			}
			return false;
		}
	}
}


void M2::resetMission()
{
	AbstractMission::resetMission();
	m_wasUnder40Percent = false;
	m_whenDidHeWasUnder40Percent = 0;
}