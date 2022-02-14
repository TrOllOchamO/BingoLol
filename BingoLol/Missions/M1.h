#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M1 : public AbstractMission
{
public:
    M1();
    ~M1();

protected:
    bool mission();
};
