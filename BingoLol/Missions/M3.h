#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M3 : public AbstractMission
{
public:
    M3();
    ~M3();
    void resetMission();

protected:
    bool m_wasCloseToDie; //set to true if the player goes under 20HP and set to false if the player die
    int m_whenDidHeWasCloseToDie; //get the value of gameTime when the player is close to die
    bool mission();
};

