#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "One stone two birds"
#define MISSION_DESCRIPTION "Get a double kill."

M8::M8() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M8::~M8()
{

}


bool M8::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "Multikill")
		{
			string playerName(Missions::getActivePlayerName(m_gameData));
			if (it["KillerName"] == playerName)
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}
