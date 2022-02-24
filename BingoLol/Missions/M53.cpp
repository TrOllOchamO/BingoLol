#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Species extinction"
#define MISSION_DESCRIPTION "Two Heralds got killed."

M53::M53() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
     m_inRealTime = false;
}


M53::~M53()
{

}


bool M53::mission()
{
	short nbHelradKilled(0);
	int gameTime(Missions::getGameTime(m_gameData));
	const int nashorSpawnTime(1200);

	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "HeraldKill")
		{
			++nbHelradKilled;
		}
	}

	if (nbHelradKilled >= 2)
	{
		m_isMissionDone = true;
		return true;
	}

	if (gameTime > nashorSpawnTime) //if the mission is still running after 20' and 30 sec in game, the mission can't be validate anymore because the Nashor has replace the Herald
	{
		m_isMissionFailed = true;
		return true;
	}

	return false;
}


void M53::resetMission()
{
    AbstractMission::resetMission();
}