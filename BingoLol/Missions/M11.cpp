#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Give penta pls !"
#define MISSION_DESCRIPTION "Someone get a quadrakill."

M11::M11() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M11::~M11()
{

}


bool M11::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "Multikill")
		{
			if (it["KillStreak"] == 4)
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}

