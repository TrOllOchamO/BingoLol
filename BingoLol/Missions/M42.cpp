#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Martyrdom"
#define MISSION_DESCRIPTION "Kill someone while beeing dead."

M42::M42() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_whenPlayerGotKilled(-1)
{
    m_inRealTime = true;
}


M42::~M42()
{

}


bool M42::mission()
{
    std::string playerName(Missions::getActivePlayerName(m_gameData));
    bool isPlayerDead(Missions::getIfSummonerIsDead(m_gameData, playerName));

    if (isPlayerDead)
    {
        if (m_whenPlayerGotKilled < 0)
        {
            m_whenPlayerGotKilled = Missions::getGameTime(m_gameData);
        }
        for (auto it : m_gameData->operator[]("events")["Events"])
        {
            if (it["EventName"] == "ChampionKill")
            {
                std::string killerName(it["KillerName"]);
                int whenThekillHappened(it["EventTime"]);

                if ((killerName == playerName) && (whenThekillHappened >= m_whenPlayerGotKilled))
                {
                    m_isMissionDone = true;
                    return true;
                }
            }
        }
    }
    else
    {
        m_whenPlayerGotKilled = -1;
    }
    return false;
}


void M42::resetMission()
{
    AbstractMission::resetMission();
    m_whenPlayerGotKilled = -1;
}