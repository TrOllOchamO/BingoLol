#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M21 : public AbstractMission
{
public:
    M21();
    ~M21();

protected:
    bool mission();
};