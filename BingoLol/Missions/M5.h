#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M5 : public AbstractMission
{
public:
    M5();
    ~M5();

protected:
    bool mission();
};

