#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Bull’s eye"
#define MISSION_DESCRIPTION "The fisrt Herald get killed befor the 9th minutes."

M52::M52() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
     m_inRealTime = false;
}


M52::~M52()
{

}


bool M52::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "HeraldKill")
		{
			if (it["EventTime"] < 540) //if it appenend befor the 9th min
			{
				m_isMissionDone = true;
				return true;
			}
			else
			{
				m_isMissionFailed = true;
				return true;
			}
		}
	}
	return false;
}


void M52::resetMission()
{
    AbstractMission::resetMission();
}