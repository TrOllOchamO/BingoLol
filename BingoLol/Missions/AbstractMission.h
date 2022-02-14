#pragma once

#include <string>
#include <iostream>

#include "nlohmann/json.hpp"

class AbstractMission
{
public:
    AbstractMission(std::string missionName, std::string missionDescription);
    ~AbstractMission();
    void setGameData(nlohmann::json* gameData);
    bool runMission(); //run the daughter's mission function if not alredy completed
    void resetMission(); //reset the state of the mission (will be overridden if needed)
    bool getIfMissionFailed() const;
    bool getIfMissionSucceed() const;
    std::string getMissionName() const;
    std::string getMissionDescription() const;


protected:
    virtual bool mission() = 0;
    nlohmann::json* m_gameData;
    bool m_isMissionDone;
    bool m_isMissionFailed;
    bool m_inRealTime; //if true the mission will run every times it get calledand not only once in a while 
    short m_notRealTimeTimer; //used to count when the mission will be next called (if real time is to false)
    const std::string m_missionName;
    const std::string m_missionDescription;

};

