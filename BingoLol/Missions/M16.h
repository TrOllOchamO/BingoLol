#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M16 : public AbstractMission
{
public:
    M16();
    ~M16();

protected:
    bool mission();
};
