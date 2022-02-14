#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Can't touch this"
#define MISSION_DESCRIPTION "Have 0 death at 10min."

M29::M29() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M29::~M29()
{

}


bool M29::mission()
{
	int gameTime(Missions::getGameTime(m_gameData));
	string playerName(Missions::getActivePlayerName(m_gameData));

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["summonerName"] == playerName)
		{
			if (it["scores"]["deaths"] == 0)
			{
				if (gameTime >= 600)
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
		}
	}

	return false;
}
