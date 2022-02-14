#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Wrecking ball"
#define MISSION_DESCRIPTION "The first tower fall before minute 10."

M44::M44() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M44::~M44()
{

}


bool M44::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "FirstBrick")
		{
			if (it["EventTime"] < 600) //if it appenend befor 10 min
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