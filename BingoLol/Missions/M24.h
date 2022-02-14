#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M24 : public AbstractMission
{
public:
    M24();
    ~M24();

protected:
    bool mission();
};