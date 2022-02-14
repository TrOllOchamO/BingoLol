#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "Your team get the first Turret."

M35::M35() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M35::~M35()
{

}


bool M35::mission()
{
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "FirstBrick")
		{
			string playerName(Missions::getActivePlayerName(m_gameData));
			string activePlayerTeam(Missions::getSummonerTeam(m_gameData, playerName));
			string killerName(it["KillerName"]);
			vector<string> playerList;
			Missions::getPlayerList(m_gameData, playerList);
			string killerTeam;

			//if the tower has been destroyed by a player
			if (find(playerList.begin(), playerList.end(), killerName) != playerList.end())
			{
				killerTeam = Missions::getSummonerTeam(m_gameData, killerName);
			}
			//if the tower has been finished by a creep
			else
			{
				killerTeam = Missions::getCreepTeam(killerName);
			}

			if (killerTeam == activePlayerTeam)
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
