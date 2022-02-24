#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Face the wind !"
#define MISSION_DESCRIPTION "Your team get a cloud drake."

M20::M20() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M20::~M20()
{

}


bool M20::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["DragonType"] == "Air")
			{
				std::string killerName(it["KillerName"]);
				std::string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));

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