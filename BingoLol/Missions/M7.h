#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M7 : public AbstractMission
{
public:
    M7();
    ~M7();

protected:
    bool mission();
};