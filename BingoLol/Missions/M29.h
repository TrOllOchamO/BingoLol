#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M29 : public AbstractMission
{
public:
    M29();
    ~M29();

protected:
    bool mission();
};

