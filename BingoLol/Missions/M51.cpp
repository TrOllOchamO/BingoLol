#include "Missions.h"

using namespace std;
using json = nlohmann::json;

#define MISSION_NAME "Godzilla"
#define MISSION_DESCRIPTION "You participate in the destruction of 4 batiments, tourret or inhibitor."

M51::M51() : AbstractMission(MISSION_NAME, MISSION_DESCRIPTION)
{

}


M51::~M51()
{

}


bool M51::mission()
{
	string playerName(Missions::getActivePlayerName(m_gameData));
	short numberOfParticipationOnBatiments(0);

	for (auto it : m_gameData->operator[]("events")["Events"])
	{
		if ((it["EventName"] == "InhibKilled") || (it["EventName"] == "TurretKilled"))
		{
			string killerName(it["KillerName"]);

			//the player killed the batiment 
			if (killerName == playerName) {numberOfParticipationOnBatiments++;}

			//the player participated to destroy the batiment
			else if (find(it["Assisters"].begin(), it["Assisters"].end(), playerName) != it["Assisters"].end()) {numberOfParticipationOnBatiments++;}
		}
	}

	if (numberOfParticipationOnBatiments >= 4)
	{
		m_isMissionDone = true;
		return true;
	}

	return false;
}