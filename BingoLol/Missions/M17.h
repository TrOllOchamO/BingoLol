#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M17 : public AbstractMission
{
public:
    M17();
    ~M17();

protected:
    bool mission();
};
