#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Four twenty"
#define MISSION_DESCRIPTION "Someone has 4/2/0 as kda."

M43::M43() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M43::~M43()
{

}


bool M43::mission()
{
	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if ((it["scores"]["kills"] == 4) && (it["scores"]["deaths"] == 2) && (it["scores"]["assists"] == 0))
		{
			m_isMissionDone = true;
			return true;
		}
	}
	return false;
}