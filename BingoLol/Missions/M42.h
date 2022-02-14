#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M42 : public AbstractMission
{
public:
    M42();
    ~M42();
    void resetMission();

protected:
    int m_whenPlayerGotKilled;
    bool mission();
};