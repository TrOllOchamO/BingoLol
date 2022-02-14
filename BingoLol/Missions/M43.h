#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M43 : public AbstractMission
{
public:
    M43();
    ~M43();

protected:
    bool mission();
};