#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M26 : public AbstractMission
{
public:
    M26();
    ~M26();

protected:
    bool mission();
};


