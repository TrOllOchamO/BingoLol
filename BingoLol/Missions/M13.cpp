#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Take your time"
#define MISSION_DESCRIPTION "The game last more than 35 min."

M13::M13() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M13::~M13()
{

}


bool M13::mission()
{
	int gameTime(Missions::getGameTime(m_gameData));

	if (gameTime >= 2100)
	{
		m_isMissionDone = true;
		return true;
	}
	return false;
}
