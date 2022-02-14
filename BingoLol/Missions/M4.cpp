#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Farmer"
#define MISSION_DESCRIPTION "Have 80 cs or more before minute 10."

M4::M4() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
	m_inRealTime = true;
}


M4::~M4()
{

}


bool M4::mission()
{
	int gameTime(Missions::getGameTime(m_gameData));

	if (gameTime <= 600) 
	{
		string playerName(Missions::getActivePlayerName(m_gameData));
		int summonerFarm(Missions::getSummonerFarm(m_gameData, playerName));
		if (summonerFarm >= 80) 
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