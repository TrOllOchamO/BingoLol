#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M28 : public AbstractMission
{
public:
    M28();
    ~M28();

protected:
    bool mission();
};

