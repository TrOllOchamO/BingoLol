#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "How did we get there ?"
#define MISSION_DESCRIPTION "Someone get executed."

M14::M14() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M14::~M14()
{

}


bool M14::mission()
{
	vector<string> playerList;
	Missions::getPlayerList(m_gameData, playerList);

	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "ChampionKill")
		{
			bool hasBeenExecuted(true);
			for (int i = 0; i < playerList.size(); i++)
			{
				if (it["KillerName"] == playerList[i])
				{
					hasBeenExecuted = false;
				}
			}
			if (hasBeenExecuted)
			{
				m_isMissionDone = true;
				return true;
			}
		}
	}
	return false;
}

