#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "FUS RO DAH !!!"
#define MISSION_DESCRIPTION "Your team get a montain drake."

M22::M22() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M22::~M22()
{

}


bool M22::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["DragonType"] == "Earth")
			{
				string killerName(it["KillerName"]);
				string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));

				if (activePlayerTeam == killerTeam)
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
	}
	return false;
}