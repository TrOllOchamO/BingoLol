#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Just 2V2 now !"
#define MISSION_DESCRIPTION "Only two players are alive in both teams."

M47::M47() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M47::~M47()
{

}


bool M47::mission()
{
	short numberOfPlayerAliveInT1(0);
	short numberOfPlayerAliveInT2(0);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		bool isAlive(!it["isDead"]);

		if (isAlive)
		{
			if (it["team"] == "ORDER") {numberOfPlayerAliveInT1++;}
			else {numberOfPlayerAliveInT2++;}
		}
	}

	if ((numberOfPlayerAliveInT1 == 2) && (numberOfPlayerAliveInT2 == 2))
	{
		m_isMissionDone = true;
		return true;
	}

    return false;
}