#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M38 : public AbstractMission
{
public:
    M38();
    ~M38();
    void resetMission();

protected:
    int m_timeOfTheLastDeath;
    std::string m_murdererName;
    bool mission();
};