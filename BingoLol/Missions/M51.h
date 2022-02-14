#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M51 : public AbstractMission
{
public:
    M51();
    ~M51();

protected:
    bool mission();
};