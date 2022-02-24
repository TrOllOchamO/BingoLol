#include "Missions.h"

using json = nlohmann::json;

#define MISSION_NAME "Vision is the key"
#define MISSION_DESCRIPTION "Leave the shop with 2 pinks."

M36::M36() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION), m_whenThe2ControlWardshasBeenPurchase(-1)
{

}


M36::~M36()
{

}


bool M36::mission()
{
	int controlWardId(2055);
	bool someoneHasTheMissionItem(false);
	std::string playerName(Missions::getActivePlayerName(m_gameData));

	for (auto it : m_gameData->operator[]("allPlayers"))
	{
		if (it["summonerName"] == playerName)
		{
			for (auto itItems : it["items"])
			{
				if ((itItems["itemID"] == controlWardId) && (itItems["count"] == 2))
				{
					someoneHasTheMissionItem = true;
				}
			}
		}
	}

	if (someoneHasTheMissionItem)
	{
		int timeBeforeTheMissionValidate(20);
		int gameTime(Missions::getGameTime(m_gameData));
		if (m_whenThe2ControlWardshasBeenPurchase < 0)
		{
			m_whenThe2ControlWardshasBeenPurchase = gameTime;
		}
		else if ((gameTime - m_whenThe2ControlWardshasBeenPurchase) >= timeBeforeTheMissionValidate)
		{
			m_isMissionDone = true;
			return true;
		}
	}
	else
	{
		m_whenThe2ControlWardshasBeenPurchase = -1;
	}
	return false;
}


void M36::resetMission()
{
    AbstractMission::resetMission();
}