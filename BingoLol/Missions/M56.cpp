#include "Missions.h"

using json = nlohmann::json;
using string = std::string;

#define MISSION_NAME "Dominating"
#define MISSION_DESCRIPTION "A player does a streak of 6 kills without dying from an other player."

M56::M56() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
     m_inRealTime = false;
}


M56::~M56()
{

}


bool M56::mission()
{
    std::vector<string> playersList;
    Missions::getPlayerList(m_gameData, playersList);
    size_t nbPlayer(playersList.size());
    const int killStreakGoal(6); // The number of kill needed befor dying by a player

    std::map<string, int> killStreak;

    // initialise the kill streak to 0 for every players
    for (size_t i = 0; i < nbPlayer; ++i)
    {
        killStreak.insert(std::pair<string, int>(playersList[i], 0));
    }

    // walk in the event list and update the kill streak at every kills (also test if the streak is long enought to validate the mission)
	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "ChampionKill")
		{
			string killerName(it["KillerName"]);

			if (std::find(playersList.begin(), playersList.end(), killerName) != playersList.end()) //verify this is a kill and not an execute
			{
                string victimName(it["VictimName"]);
                killStreak[killerName] += 1;
                killStreak[victimName] = 0;

                for (std::map<string, int>::iterator iter = killStreak.begin(); iter != killStreak.end(); ++iter)
                {
                    if (iter->second == killStreakGoal) // someone hit the kill streak goal
                    {
                        m_isMissionDone = true;
                        return true;
                    }
                }
			}
		}
	}

	return false;
}


void M56::resetMission()
{
    AbstractMission::resetMission();
}