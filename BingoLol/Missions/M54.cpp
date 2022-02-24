#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "FF ?"
#define MISSION_DESCRIPTION "There is a difference of 10 kills between the 2 teams."

M54::M54() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
     m_inRealTime = true;
}


M54::~M54()
{

}


bool M54::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	int playerTeamScore(0);
	int ennemyTeamScore(0);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["team"] == activePlayerTeam)
		{
			playerTeamScore += it["scores"]["kills"];
		}
		else
		{
			ennemyTeamScore += it["scores"]["kills"];
		}
	}

	if (std::abs(playerTeamScore - ennemyTeamScore) >= 10)
	{
		m_isMissionDone = true;
		return true;
	}

	return false;
}


void M54::resetMission()
{
    AbstractMission::resetMission();
}