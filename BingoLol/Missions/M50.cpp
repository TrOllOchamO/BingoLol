#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "Your team has 35 kills or more."

M50::M50() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M50::~M50()
{

}


bool M50::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	string playerTeam(Missions::getSummonerTeam(m_gameData, playerName));
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