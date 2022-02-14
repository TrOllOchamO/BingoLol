#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M46 : public AbstractMission
{
public:
    M46();
    ~M46();

protected:
    bool mission();
};