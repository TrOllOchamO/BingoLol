#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M31 : public AbstractMission
{
public:
    M31();
    ~M31();
    void resetMission();

protected:
    int m_whenCullHasBeenPurchase;
    bool mission();
};