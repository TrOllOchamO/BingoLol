#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Team play"
#define MISSION_DESCRIPTION "Your whole team participates in the elimination of an enemy."

M39::M39() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M39::~M39()
{

}


bool M39::mission()
{
    string playerName(Missions::getActivePlayerName(m_gameData));
    string playerTeam(Missions::getSummonerTeam(m_gameData, playerName));
    vector<string> playerteamList;
    Missions::getTeamList(m_gameData, playerteamList, playerTeam);

    for (auto it : m_gameData->operator[]("events")["Events"])
    {
        if (it["EventName"] == "ChampionKill")
        {
            if (it["Assisters"].size() == playerteamList.size() - 1)
            {
                string killername(it["KillerName"]);
                if (Missions::getSummonerTeam(m_gameData, killername) == playerTeam)
                {
                    m_isMissionDone = true;
                    return true;
                }
            }
        }
    }
    return false;
}