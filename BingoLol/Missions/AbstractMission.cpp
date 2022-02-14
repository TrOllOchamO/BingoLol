#include "AbstractMission.h"

using namespace std;
using json = nlohmann::json;

AbstractMission::AbstractMission(string missionName, string missionDescription) : 
    m_isMissionDone(false), m_isMissionFailed(false), m_missionName(missionName), m_missionDescription(missionDescription), 
    m_inRealTime(false), m_notRealTimeTimer(20)
{

}


AbstractMission::~AbstractMission()
{

}


void AbstractMission::setGameData(nlohmann::json* gameData)
{
    m_gameData = gameData;
}


bool AbstractMission::runMission()
{
    if (!(m_isMissionDone || m_isMissionFailed))
    {
        if (m_inRealTime)
        {
            return this->mission();
        }
        else
        {
            if (m_notRealTimeTimer == 0)
            {
                m_notRealTimeTimer = 20;
                return this->mission();
            }
            else
            {
                m_notRealTimeTimer--;
            }
        }
    }

    return false;
}


void AbstractMission::resetMission()
{
    m_isMissionDone = false;
    m_isMissionFailed = false;
}

bool AbstractMission::getIfMissionFailed() const
{
    return m_isMissionFailed;
}

bool AbstractMission::getIfMissionSucceed() const
{
    return m_isMissionDone;
}

string AbstractMission::getMissionName() const
{
    return m_missionName;
}

string AbstractMission::getMissionDescription() const
{
    return m_missionDescription;
}