#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M10 : public AbstractMission
{
public:
    M10();
    ~M10();

protected:
    bool mission();
};