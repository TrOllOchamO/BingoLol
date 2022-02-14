#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M34 : public AbstractMission
{
public:
    M34();
    ~M34();

protected:
    bool mission();
};