#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M30 : public AbstractMission
{
public:
    M30();
    ~M30();
    void resetMission();

protected:
    int m_whenBootHasBeenPurchase;
    bool mission();
};