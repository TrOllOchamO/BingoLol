#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Come here Shelly"
#define MISSION_DESCRIPTION "Your team kill the first Herald."

M15::M15() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M15::~M15()
{

}


bool M15::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "HeraldKill")
		{
			std::string playerName(Missions::getActivePlayerName(m_gameData));
			std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
			std::string heraldKillerName(it["KillerName"]);
			std::string heraldKillerTeam(Missions::getSummonerTeam(m_gameData, heraldKillerName));
			
			if (heraldKillerTeam == activePlayerTeam)
			{
				m_isMissionDone = true;
				return true;
			}
			else
			{
				m_isMissionFailed = true;
				return true;
			}
		}
	}
	return false;
}