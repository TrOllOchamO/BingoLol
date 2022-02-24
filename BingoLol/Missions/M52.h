#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M52 : public AbstractMission
{
public:
    M52();
    ~M52();
    void resetMission();

protected:
    bool mission();
};