#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Not even close !"
#define MISSION_DESCRIPTION "Survive one minute after your HP dropped below 20."

M3::M3() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_wasCloseToDie(false), m_whenDidHeWasCloseToDie(0)
{
	m_inRealTime = true;
}


M3::~M3()
{

}


bool M3::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	bool isActivePlayerDead(Missions::getIfSummonerIsDead(m_gameData, playerName));

	if (isActivePlayerDead)
	{
		m_wasCloseToDie = false;
		return false;
	}
	else
	{
		int gameTime(Missions::getGameTime(m_gameData));
		if (m_wasCloseToDie)
		{
			if (gameTime - m_whenDidHeWasCloseToDie > 60)
			{
				m_isMissionDone = true;
				return true;
			}
			return false;
		}
		else
		{
			int playerHealth(Missions::getActivePlayerCurrentHealth(m_gameData));
			if (playerHealth < 20)
			{
				m_wasCloseToDie = true;
				m_whenDidHeWasCloseToDie = gameTime;
			}
			return false;
		}
	}
}


void M3::resetMission()
{
	AbstractMission::resetMission();
	m_wasCloseToDie = false;
	m_whenDidHeWasCloseToDie = 0;
}