#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M47 : public AbstractMission
{
public:
    M47();
    ~M47();

protected:
    bool mission();
};