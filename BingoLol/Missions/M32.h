#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M32 : public AbstractMission
{
public:
    M32();
    ~M32();

protected:
    bool mission();
};