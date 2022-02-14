#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M45 : public AbstractMission
{
public:
    M45();
    ~M45();

protected:
    bool mission();
};