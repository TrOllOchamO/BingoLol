#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M6 : public AbstractMission
{
public:
    M6();
    ~M6();

protected:
    bool mission();
};
