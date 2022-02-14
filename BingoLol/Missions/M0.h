#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M0 : public AbstractMission
{
public:
    M0();
    ~M0();

protected:
    bool mission();
};
