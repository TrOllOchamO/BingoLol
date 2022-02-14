#pragma once

#include "AbstractMission.h"
#include "Missions.h"

class M2 : public AbstractMission
{
public:
    M2();
    ~M2();
    void resetMission();

protected:
    bool m_wasUnder40Percent; //set to true if the player goes under 40% of his max health and set to false if the player die
    int m_whenDidHeWasUnder40Percent; //get the value of gameTime when the player fallen under 40%
    bool mission();
};