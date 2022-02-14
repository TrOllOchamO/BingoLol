#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M40 : public AbstractMission
{
public:
    M40();
    ~M40();

protected:
    bool mission();
};