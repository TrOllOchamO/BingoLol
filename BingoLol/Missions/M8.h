#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M8 : public AbstractMission
{
public:
    M8();
    ~M8();

protected:
    bool mission();
};