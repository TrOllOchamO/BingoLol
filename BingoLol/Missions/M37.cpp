#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Split pusher"
#define MISSION_DESCRIPTION "Finish a turret without the help of any of your allies."

M37::M37() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M37::~M37()
{

}


bool M37::mission()
{
	std::string playerName(Missions::getActivePlayerName(m_gameData));

	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "TurretKilled")
		{
			if ((it["KillerName"] == playerName) && (it["Assisters"].size() == 0))
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}