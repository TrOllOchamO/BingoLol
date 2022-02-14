#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Peaceful & harmless life"
#define MISSION_DESCRIPTION "An ally has 0 kills and 0 assists at 10 minutes."

M5::M5() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M5::~M5()
{

}


bool M5::mission()
{
	int gameTime(Missions::getGameTime(m_gameData));

	if (gameTime >= 600)
	{
		string playerName(Missions::getActivePlayerName(m_gameData));
		string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
		for (auto it : m_gameData->operator[]("allPlayers"))
		{
			if ((it["summonerName"] != playerName) && (it["team"] == activePlayerTeam)) //the player is a teammate
			{
				if ((it["scores"]["assists"] == 0) && (it["scores"]["kills"] == 0)) //the teammate kda is 0/x/0
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
		m_isMissionFailed = true; //if the function hasnt return inside the for loop then the mission is failed
		return true;
	}
	return false;
}

