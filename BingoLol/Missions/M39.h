#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M39 : public AbstractMission
{
public:
    M39();
    ~M39();

protected:
    bool mission();
};