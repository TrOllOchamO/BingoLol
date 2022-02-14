#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME ""
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
			string playerName(Missions::getActivePlayerName(m_gameData));
			string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
			string killerName(it["KillerName"]);
			string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));
			if (activePlayerTeam == killerTeam)
			{
				cout << "gg" << endl;
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}
