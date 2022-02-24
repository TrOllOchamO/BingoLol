#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M55 : public AbstractMission
{
public:
    M55();
    ~M55();
    void resetMission();

protected:
    bool mission();
};