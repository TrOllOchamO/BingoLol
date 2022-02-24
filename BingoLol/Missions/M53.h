#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M53 : public AbstractMission
{
public:
    M53();
    ~M53();
    void resetMission();

protected:
    bool mission();
};