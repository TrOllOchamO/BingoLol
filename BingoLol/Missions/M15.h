#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M15 : public AbstractMission
{
public:
    M15();
    ~M15();

protected:
    bool mission();
};
