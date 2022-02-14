#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M44 : public AbstractMission
{
public:
    M44();
    ~M44();

protected:
    bool mission();
};