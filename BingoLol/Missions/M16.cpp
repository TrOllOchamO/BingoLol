#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Bot diff !"
#define MISSION_DESCRIPTION "A botlane inhibitor get destroyed."

M16::M16() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M16::~M16()
{

}


bool M16::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "InhibKilled")
		{
			if (it["InhibKilled"] == "Barracks_T2_R1" || it["InhibKilled"] == "Barracks_T1_R1")
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}