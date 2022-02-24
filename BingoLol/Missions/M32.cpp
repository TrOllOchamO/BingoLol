#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Speedrun"
#define MISSION_DESCRIPTION "The game last less than 21min."

M32::M32() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M32::~M32()
{

}


bool M32::mission()
{
	int gameTime(Missions::getGameTime(m_gameData));

	if (gameTime <= 1260)
	{
		if (Missions::getIfTheGameIsFinished(m_gameData) != 0)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	else
	{
		m_isMissionFailed = true;
		return true;
	}
	return false;
}
