#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M12 : public AbstractMission
{
public:
    M12();
    ~M12();

protected:
    bool mission();
};
