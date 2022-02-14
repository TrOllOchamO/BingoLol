#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M18 : public AbstractMission
{
public:
    M18();
    ~M18();

protected:
    bool mission();
};
