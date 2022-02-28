#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Rush B-aron"
#define MISSION_DESCRIPTION "Your team get a nashor."

M27::M27() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M27::~M27()
{

}


bool M27::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "BaronKill")
		{
			std::string playerName(Missions::getActivePlayerName(m_gameData));
			std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
			std::string killerName(it["KillerName"]);
			std::string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));
			if (activePlayerTeam == killerTeam)
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}
