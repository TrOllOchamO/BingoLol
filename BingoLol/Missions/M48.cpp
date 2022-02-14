#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Feel the loneliness..."
#define MISSION_DESCRIPTION "You are the only one still alive in your team."

M48::M48() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M48::~M48()
{

}


bool M48::mission()
{
    bool isPlayerAlive(true);
	short numberAlivesSummonersInPlayerTeam(0);
	string playerName(Missions::getActivePlayerName(m_gameData));
	string playerTeam(Missions::getSummonerTeam(m_gameData, playerName));

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["summonerName"] == playerName)
		{
			isPlayerAlive = !it["isDead"];
		}
		else if (!it["isDead"] && (it["team"] == playerTeam))
		{
			numberAlivesSummonersInPlayerTeam++;
		}
	}

	if (isPlayerAlive && (numberAlivesSummonersInPlayerTeam == 0))
	{
		m_isMissionDone = true;
		return true;
	}

    return false;
}