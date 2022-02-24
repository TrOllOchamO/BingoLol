#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Peace treaty"
#define MISSION_DESCRIPTION "2 min has passed since the last kill."

M34::M34() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M34::~M34()
{

}


bool M34::mission()
{
	int lastKillEventTime(Missions::getLastKillTimeEvent(m_gameData));
	if (lastKillEventTime > 0)
	{
		int gameTime(Missions::getGameTime(m_gameData));
		if ((gameTime - lastKillEventTime) >= 120)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	return false;
}
