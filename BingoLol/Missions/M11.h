#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M11 : public AbstractMission
{
public:
    M11();
    ~M11();

protected:
    bool mission();
};

