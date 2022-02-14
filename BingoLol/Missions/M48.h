#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M48 : public AbstractMission
{
public:
    M48();
    ~M48();

protected:
    bool mission();
};