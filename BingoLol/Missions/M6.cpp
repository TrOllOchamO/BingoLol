#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Is this LCS ?"
#define MISSION_DESCRIPTION "No first blood until minute 4."

M6::M6() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M6::~M6()
{

}


bool M6::mission()
{
	int firstBloodTime(Missions::getFirstBloodTime(m_gameData));

	if (firstBloodTime > 0)
	{
		if (firstBloodTime >= 240)
		{
			m_isMissionDone = true;
		}
		else
		{
			m_isMissionFailed = true;
		}
		return true;
	}
	else
	{
		return false;
	}
}