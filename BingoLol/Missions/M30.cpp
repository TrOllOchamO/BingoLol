#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Fast as fuck boiii"
#define MISSION_DESCRIPTION "Someone buy mobility boots."

M30::M30() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_whenBootHasBeenPurchase(-1)
{

}


M30::~M30()
{

}

void M30::resetMission()
{
	AbstractMission::resetMission();
	m_whenBootHasBeenPurchase = -1;
}


bool M30::mission()
{
	int mobyBootsId(3117);
	bool someoneHasTheMissionItem(false);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		for (auto itItems : it["items"])
		{
			if (itItems["itemID"] == mobyBootsId)
			{
				someoneHasTheMissionItem = true;
			}
		}
	}

	if (someoneHasTheMissionItem)
	{
		int timeBeforeTheMissionValidate(30);
		int gameTime(Missions::getGameTime(m_gameData));
		if (m_whenBootHasBeenPurchase < 0)
		{
			m_whenBootHasBeenPurchase = gameTime;
		}
		else if ((gameTime - m_whenBootHasBeenPurchase) >= timeBeforeTheMissionValidate)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	else
	{
		m_whenBootHasBeenPurchase = -1;
	}
	return false;
}
