#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M9 : public AbstractMission
{
public:
    M9();
    ~M9();

protected:
    bool mission();
};