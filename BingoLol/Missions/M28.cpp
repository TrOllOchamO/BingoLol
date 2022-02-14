#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Turbo feed"
#define MISSION_DESCRIPTION "Someone die before 2min."

M28::M28() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M28::~M28()
{

}


bool M28::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "ChampionKill")
		{
			if (it["EventTime"] < 120)
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
