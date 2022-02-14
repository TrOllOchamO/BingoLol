#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M25 : public AbstractMission
{
public:
    M25();
    ~M25();

protected:
    bool mission();
};
