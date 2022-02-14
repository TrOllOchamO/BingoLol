#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Bruh moment"
#define MISSION_DESCRIPTION "The ennemy team get a triple kill."

M10::M10() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M10::~M10()
{

}


bool M10::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "Multikill")
		{
			if (it["KillStreak"] == 3)
			{
				string playerName(Missions::getActivePlayerName(m_gameData));
				string playerTeam(Missions::getSummonerTeam(m_gameData, playerName));
				string killerName(it["KillerName"]);
				string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));
				if (playerTeam != killerTeam)
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
	}
	return false;
}

