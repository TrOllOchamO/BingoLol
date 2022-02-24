#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M56 : public AbstractMission
{
public:
    M56();
    ~M56();
    void resetMission();

protected:
    bool mission();
};