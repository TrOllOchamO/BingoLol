#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Ace"
#define MISSION_DESCRIPTION "Your team get an ace."

M18::M18() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M18::~M18()
{

}


bool M18::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "Ace")
		{
			string playerName(Missions::getActivePlayerName(m_gameData));
			string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));

			if (it["AcingTeam"] == activePlayerTeam)
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}