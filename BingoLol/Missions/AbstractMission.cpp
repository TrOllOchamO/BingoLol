#include "AbstractMission.h"

using json = nlohmann::json;

AbstractMission::AbstractMission(std::string missionName, std::string missionDescription) :
    m_isMissionDone(false), m_isMissionFailed(false), m_missionName(missionName), m_missionDescription(missionDescription),
    m_inRealTime(false), m_notRealTimeTimer(20)
{
    std::random_device rd;
    m_notRealTimeTimer = rd() % 20; //start the counter with a random value in [0;19] so every non-realtime mission doesn't execute at the same time
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

std::string AbstractMission::getMissionName() const
{
    return m_missionName;
}

std::string AbstractMission::getMissionDescription() const
{
    return m_missionDescription;
}