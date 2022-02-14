#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M35 : public AbstractMission
{
public:
    M35();
    ~M35();

protected:
    bool mission();
};
