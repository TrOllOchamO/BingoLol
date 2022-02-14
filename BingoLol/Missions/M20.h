#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M20 : public AbstractMission
{
public:
    M20();
    ~M20();

protected:
    bool mission();
};