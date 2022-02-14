#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M49 : public AbstractMission
{
public:
    M49();
    ~M49();

protected:
    bool mission();
};