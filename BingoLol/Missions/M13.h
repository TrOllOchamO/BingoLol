#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M13 : public AbstractMission
{
public:
    M13();
    ~M13();

protected:
    bool mission();
};