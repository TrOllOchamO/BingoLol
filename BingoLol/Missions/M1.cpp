#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "PLAY SAFE OMG"
#define MISSION_DESCRIPTION "One of your ally has 7 or more deaths within 15 minutes."

M1::M1() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M1::~M1()
{

}


bool M1::mission()
{
	int gameTime(Missions::getGameTime(m_gameData));

	if (gameTime <= 900)
	{
		string playerName(Missions::getActivePlayerName(m_gameData));
		string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));

		for (auto it : m_gameData->operator[]("allPlayers"))
		{
			if ((it["summonerName"] != playerName) && (it["team"] == activePlayerTeam)) //the player is a teammate
			{
				if ((it["scores"]["deaths"] >= 7))
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
		return false;
	}
	else
	{
		m_isMissionFailed = true;
		return true;
	}
}
