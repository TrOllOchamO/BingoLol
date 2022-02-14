#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Cyber bullying"
#define MISSION_DESCRIPTION "Kill the same enemy twice in a row."

M46::M46() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M46::~M46()
{

}


bool M46::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	string lastVictimeName("");

	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if ((it["EventName"] == "ChampionKill") && (it["KillerName"] == playerName))
		{
			if (it["VictimName"] == lastVictimeName)
			{
				m_isMissionDone = true;
				return true;
			}
			lastVictimeName = it["VictimName"];
		}
	}
    return false;
}