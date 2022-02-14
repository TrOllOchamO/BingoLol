#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Sly Cooper"
#define MISSION_DESCRIPTION "Your team steal a drake."

M25::M25() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M25::~M25()
{

}


bool M25::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "DragonKill")
		{
			if (it["Stolen"] == "True")
			{
				string playerName(Missions::getActivePlayerName(m_gameData));
				string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
				string stealerName(it["KillerName"]);
				string stealerTeam(Missions::getSummonerTeam(m_gameData, stealerName));

				if (activePlayerTeam == stealerTeam)
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
	}
	return false;
}