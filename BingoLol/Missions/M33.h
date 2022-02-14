#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M33 : public AbstractMission
{
public:
    M33();
    ~M33();

protected:
    bool mission();
};