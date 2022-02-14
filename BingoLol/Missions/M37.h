#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M37 : public AbstractMission
{
public:
    M37();
    ~M37();

protected:
    bool mission();
};