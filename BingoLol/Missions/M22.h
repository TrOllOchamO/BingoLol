#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M22 : public AbstractMission
{
public:
    M22();
    ~M22();

protected:
    bool mission();
};