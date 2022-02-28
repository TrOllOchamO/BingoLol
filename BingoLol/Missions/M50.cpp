#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Genocide"
#define MISSION_DESCRIPTION "Your team has 35 kills or more."

M50::M50() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M50::~M50()
{

}


bool M50::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	std::string playerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	short playerTeamKillCounter(0);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["team"] == playerTeam)
		{
			playerTeamKillCounter += it["scores"]["kills"];
		}
	}

	if (playerTeamKillCounter >= 35)
	{
		m_isMissionDone = true;
		return true;
	}

	return false;
}