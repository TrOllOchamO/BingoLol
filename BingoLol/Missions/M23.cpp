#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "I’m Unda da Watur"
#define MISSION_DESCRIPTION "Your team get an ocean drake."

M23::M23() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M23::~M23()
{

}


bool M23::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["DragonType"] == "Water")
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