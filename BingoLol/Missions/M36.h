#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M36 : public AbstractMission
{
public:
    M36();
    ~M36();
    void resetMission();

protected:
    int m_whenThe2ControlWardshasBeenPurchase;
    bool mission();
};