#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "Your team has 15 more vision score than the opposing team."

M55::M55() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
     m_inRealTime = true;
}


M55::~M55()
{

}


bool M55::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));
	std::string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	float playerTeamScore(0);
	float ennemyTeamScore(0);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["team"] == activePlayerTeam)
		{
			const float wardScore = it["scores"]["wardScore"]; //must dump the value in a variable first or the += doesn't work
			playerTeamScore += wardScore;
		}
		else
		{
			ennemyTeamScore += it["scores"]["wardScore"];
		}
	}

	if (playerTeamScore - ennemyTeamScore >= 15)
	{
		m_isMissionDone = true;
		return true;
	}

	return false;
}


void M55::resetMission()
{
    AbstractMission::resetMission();
}