#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Nine eleven"
#define MISSION_DESCRIPTION "Two towers are destroyed within 30 seconds."

M41::M41() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M41::~M41()
{

}


bool M41::mission()
{
    int timeWhenLastTurretFallen(-1);
    int timeBetween2TurretsFalls(30);

    for (auto it : m_gameData->operator[]("events")["Events"])
    {
        if (it["EventName"] == "TurretKilled")
        {
            if ((timeWhenLastTurretFallen > 0))
            {
                if (it["EventTime"] - timeWhenLastTurretFallen <= timeBetween2TurretsFalls)
                {
                    m_isMissionDone = true;
                    return true;
                }
            }
            timeWhenLastTurretFallen = it["EventTime"];
        }
    }

    return false;
}