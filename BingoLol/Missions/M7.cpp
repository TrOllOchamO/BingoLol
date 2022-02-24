#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Are you winning son ?"
#define MISSION_DESCRIPTION "Win the game."

M7::M7() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{
    m_inRealTime = true;
}


M7::~M7()
{

}


bool M7::mission()
{
    switch (Missions::getIfTheGameIsFinished(m_gameData))
    {
    case 0: //0 mean the game isn't finished
        return false;
    case 1: //1 mean the game has been won
        m_isMissionDone = true;
        return true;
    case -1: //-1 mean the game has been lost
        m_isMissionFailed = true;
        return true;
    }
    return false;
}