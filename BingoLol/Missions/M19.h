#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M19 : public AbstractMission
{
public:
    M19();
    ~M19();

protected:
    bool mission();
};

