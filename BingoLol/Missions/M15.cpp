#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Bull's eye"
#define MISSION_DESCRIPTION "Your team kill the Herald."

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
			string playerName(Missions::getActivePlayerName(m_gameData));
			string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
			string heraldKillerName(it["KillerName"]);
			string heraldKillerTeam(Missions::getSummonerTeam(m_gameData, heraldKillerName));
			
			if (heraldKillerTeam == activePlayerTeam)
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}