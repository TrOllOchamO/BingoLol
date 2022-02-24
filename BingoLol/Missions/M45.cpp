#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Yasuo power spike"
#define MISSION_DESCRIPTION "Someone hit 10 deaths."

M45::M45() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M45::~M45()
{

}


bool M45::mission()
{
	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["scores"]["deaths"] == 10)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	return false;
}