#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M27 : public AbstractMission
{
public:
    M27();
    ~M27();

protected:
    bool mission();
};


