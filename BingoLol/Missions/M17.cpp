#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Tot diff !"
#define MISSION_DESCRIPTION "A toplane inhibitor get destroyed."

M17::M17() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M17::~M17()
{

}


bool M17::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "InhibKilled")
		{
			if (it["InhibKilled"] == "Barracks_T2_L1" || it["InhibKilled"] == "Barracks_T1_L1")
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}
