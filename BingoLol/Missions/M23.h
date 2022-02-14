#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M23 : public AbstractMission
{
public:
    M23();
    ~M23();

protected:
    bool mission();
};