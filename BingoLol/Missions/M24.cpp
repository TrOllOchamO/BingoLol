#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "XP Grand Canyon gap"
#define MISSION_DESCRIPTION "Two player have 4 or more levels of difference."

M24::M24() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M24::~M24()
{

}


bool M24::mission()
{
	int highestLvl(0);
	int lowestLvl(10000);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["level"] > highestLvl)
		{
			highestLvl = it["level"];
		}
		if (it["level"] < lowestLvl)
		{
			lowestLvl = it["level"];
		}
	}
	if ((highestLvl - lowestLvl) > 3)
	{
		m_isMissionDone = true;
		return true;
	}
	return false;
}

