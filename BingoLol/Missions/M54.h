#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M54 : public AbstractMission
{
public:
    M54();
    ~M54();
    void resetMission();

protected:
    bool mission();
};