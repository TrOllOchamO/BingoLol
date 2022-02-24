#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "A team get the dragon soul."

M33::M33() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M33::~M33()
{

}


bool M33::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	int numberOfDrakeForAllyTeam(0);
	int numberOfDrakeForEnnemyTeam(0);

	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			std::string killerName(it["KillerName"]);
			std::string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));

			if (activePlayerTeam == killerTeam)
			{
				numberOfDrakeForAllyTeam += 1;
			}
			else
			{
				numberOfDrakeForEnnemyTeam += 1;
			}
		}
	}
	if (numberOfDrakeForAllyTeam == 4 || numberOfDrakeForEnnemyTeam == 4)
	{
		m_isMissionDone = true;
		return true;
	}
	return false;
}
