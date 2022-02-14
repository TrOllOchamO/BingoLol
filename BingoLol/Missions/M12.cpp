#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Pearl Harbor"
#define MISSION_DESCRIPTION "Your team get the first blood."

M12::M12() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M12::~M12()
{

}


bool M12::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "FirstBlood")
		{
			string playerName(Missions::getActivePlayerName(m_gameData));
			string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
			string killerName(it["Recipient"]);
			string killerTeam(Missions::getSummonerTeam(m_gameData, killerName));

			if (killerTeam == activePlayerTeam)
			{
				m_isMissionDone = true;
				return true;
			}
			else
			{
				m_isMissionFailed = true;
				return true;
			}
		}
	}
	return false;
}
