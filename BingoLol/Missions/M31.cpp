#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME ""
#define MISSION_DESCRIPTION "Someone buy a cull."

M31::M31() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_whenCullHasBeenPurchase(-1)
{

}


M31::~M31()
{

}

void M31::resetMission()
{
	AbstractMission::resetMission();
	m_whenCullHasBeenPurchase = -1;
}


bool M31::mission()
{
	int cullId(1083);
	bool someoneHasTheMissionItem(false);

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		for (auto itItems : it["items"])
		{
			if (itItems["itemID"] == cullId)
			{
				someoneHasTheMissionItem = true;
			}
		}
	}

	if (someoneHasTheMissionItem)
	{
		int timeBeforeTheMissionValidate(60);
		int gameTime(Missions::getGameTime(m_gameData));
		if (m_whenCullHasBeenPurchase < 0)
		{
			m_whenCullHasBeenPurchase = gameTime;
		}
		else if ((gameTime - m_whenCullHasBeenPurchase) >= timeBeforeTheMissionValidate)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	else
	{
		m_whenCullHasBeenPurchase = -1;
	}
	return false;
}
