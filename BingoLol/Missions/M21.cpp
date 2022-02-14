#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "I am fire, I am death."
#define MISSION_DESCRIPTION "Your team get a fire drake."

M21::M21() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M21::~M21()
{

}


bool M21::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["DragonType"] == "Fire")
			{
				string killerName(it["KillerName"]);
				string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));

				if (activePlayerTeam == killerTeam)
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
	}
	return false;
}