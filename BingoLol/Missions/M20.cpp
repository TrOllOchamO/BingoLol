#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "Your team get a cloud drake."

M20::M20() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M20::~M20()
{

}


bool M20::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["DragonType"] == "Air")
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