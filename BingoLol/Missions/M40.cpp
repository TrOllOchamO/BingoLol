#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Survivor"
#define MISSION_DESCRIPTION "Your team inhibitors respawn 2 times."

M40::M40() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M40::~M40()
{

}


bool M40::mission()
{
    short numberOfrespwnedInhibs(0);
    string playerName(Missions::getActivePlayerName(m_gameData));
    string playerTeam(Missions::getSummonerTeam(m_gameData, playerName));

    for (auto it : m_gameData->operator[]("events")["Events"])
    {
        if (it["EventName"] == "InhibRespawned")
        {
            string inhibName(it["InhibRespawned"]);
            if (Missions::getInhibTeam(inhibName) == playerTeam)
            {
                numberOfrespwnedInhibs++;
            }
        }
    }

    if (numberOfrespwnedInhibs > 1) 
    {
        m_isMissionDone = true;
        return true;
    }

    return false;
}