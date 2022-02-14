#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Revenge !"
#define MISSION_DESCRIPTION "Murder back the player who killed you within two minutes of your death."

M38::M38() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_timeOfTheLastDeath(-1), m_murdererName("")
{
    m_inRealTime = true;
}


M38::~M38()
{

}


bool M38::mission()
{
    string playerName(Missions::getActivePlayerName(m_gameData));
    int gameTime(Missions::getGameTime(m_gameData));
    int timeToTakeRevenge(120); //2min to take revenge 

    if (m_timeOfTheLastDeath < 0) //revenge time ?
    {
        bool isActivePlayerDead(Missions::getIfSummonerIsDead(m_gameData, playerName));
        if (isActivePlayerDead) //revenge time begin !
        {
            vector<string> playerList;
            Missions::getPlayerList(m_gameData, playerList);

            //getting the murderer name
            for (auto it : m_gameData->operator[]("events")["Events"]) 
            {
                if (it["EventName"] == "ChampionKill")
                {
                    if ((it["VictimName"] == playerName))
                    {
                        m_murdererName = it["KillerName"];
                        //start the revenge timer only if the player is dead by an ennemy player
                        if (find(playerList.begin(), playerList.end(), m_murdererName) != playerList.end())
                        {
                            m_timeOfTheLastDeath = gameTime;
                        }
                    }
                }
            }
        }    
    }
    else //revenge time.
    {
        if ((gameTime - m_timeOfTheLastDeath) > timeToTakeRevenge) //too late for a revenge
        {
            m_timeOfTheLastDeath = -1;
        }
        else
        {
            //check if the player got his revenge
            for (auto it : m_gameData->operator[]("events")["Events"])
            {
                if (it["EventName"] == "ChampionKill")
                {
                    if ((it["EventTime"] > m_timeOfTheLastDeath) && (it["VictimName"] == m_murdererName))
                    {
                        if (it["KillerName"] == playerName) //he done his revenge
                        {
                            m_isMissionDone = true;
                            return true;
                        }
                        if (find(it["Assisters"].begin(), it["Assisters"].end(), playerName) != it["Assisters"].end()) //he participate
                        {
                            m_isMissionDone = true;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}


void M38::resetMission()
{
    AbstractMission::resetMission();
    m_timeOfTheLastDeath = -1;
}