#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Swiper no swiping !"
#define MISSION_DESCRIPTION "The ennemy team steal a drake."

M26::M26() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M26::~M26()
{

}


bool M26::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["Stolen"] == "True")
			{
				std::string playerName(Missions::getActivePlayerName(m_gameData));
				std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
				std::string stealerName(it["KillerName"]);
				std::string stealerTeam(Missions::getSummonerTeam(m_gameData, stealerName));

				if (activePlayerTeam != stealerTeam)
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
	}
	return false;
}
