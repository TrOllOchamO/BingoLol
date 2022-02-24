#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "What’s 9 plus 10 ?"
#define MISSION_DESCRIPTION "Someone is involved in 21 or more kills."

M49::M49() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M49::~M49()
{

}


bool M49::mission()
{
	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		short assistScore(it["scores"]["assists"]);
		short killScore(it["scores"]["kills"]);
		if (assistScore + killScore >= 21)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	return false;
}