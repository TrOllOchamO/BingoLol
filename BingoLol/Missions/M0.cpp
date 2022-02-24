#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Scrooge McDuck"
#define MISSION_DESCRIPTION "Accumulate 3000 gold or more."

M0::M0() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M0::~M0()
{

}


bool M0::mission()
{
	if (Missions::getActivePlayerGolds(m_gameData) >= 3000) 
	{
		m_isMissionDone = true;
		return true;
	}
	else
	{
		return false;
	}
}
