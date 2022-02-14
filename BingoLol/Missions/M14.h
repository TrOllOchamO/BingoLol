#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M14 : public AbstractMission
{
public:
    M14();
    ~M14();

protected:
    bool mission();
};