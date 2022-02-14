#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M4 : public AbstractMission
{
public:
    M4();
    ~M4();

protected:
    bool mission();
};

