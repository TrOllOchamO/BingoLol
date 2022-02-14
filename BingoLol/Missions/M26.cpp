#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "The ennemy team steal a drake."

M26::M26() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M26::~M26()
{

}


bool M26::mission()
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

				if (activePlayerTeam != stealerTeam)
				{
					m_isMissionDone = true;
					return true;
				}
			}
		}
	}
	return false;
}
