#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M50 : public AbstractMission
{
public:
    M50();
    ~M50();

protected:
    bool mission();
};