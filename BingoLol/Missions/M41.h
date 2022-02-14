#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M41 : public AbstractMission
{
public:
    M41();
    ~M41();

protected:
    bool mission();
};