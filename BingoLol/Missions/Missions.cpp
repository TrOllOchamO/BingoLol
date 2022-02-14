#include "Missions.h"

using namespace std;
using json = nlohmann::json;


string Missions::getActivePlayerName(json* gameData)
{
	return gameData->operator[]("activePlayer")["summonerName"];
}


int Missions::getSummonerFarm(json* gameData, string& summonerName)
{
	for (auto it : gameData->operator[]("allPlayers"))
	{
		if (it["summonerName"] == summonerName) {
			return it["scores"]["creepScore"];
		}
	}
	cout << "something goes wrong with Missions::getSummonerFarm()" << endl;
	return -1;
}


long Missions::getActivePlayerGolds(nlohmann::json* gameData)
{
	return gameData->operator[]("activePlayer")["currentGold"];
}


int Missions::getGameTime(json* gameData)
{
	return gameData->operator[]("gameData")["gameTime"];
}


int Missions::getActivePlayerCurrentHealth(json* gameData)
{
	return gameData->operator[]("activePlayer")["championStats"]["currentHealth"];
}


bool Missions::getIfSummonerIsDead(json* gameData, string& summonerName)
{
	for (auto it : gameData->operator[]("allPlayers"))
	{
		if (it["summonerName"] == summonerName) 
		{
			return it["isDead"];
		}
	}
	cout << "something goes wrong with Missions::getIfSummonerIsDead()" << endl;
	return false;
}

int Missions::getIfTheGameIsFinished(json* gameData)
{
	//this function return 0 if the game isn't finished,
	//1 in case the game has been won,
	//-1 if the game has been lost
	for (auto it : gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "GameEnd")
		{
			if (it["Result"] == "Win") { return 1; }
			return -1;
		}
	}
	return 0;
}


int Missions::getFirstBloodTime(json* gameData)
{
	//return the gametime of the first blood and if there is no firstblood return -1
	int eventTime(-1);

	for (auto it : gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "FirstBlood") 
		{
			eventTime = it["EventTime"];
		}
	}
	return eventTime;
}


string Missions::getSummonerTeam(json* gameData, string& summonerName)
{
	for (auto it : gameData->operator[]("allPlayers"))
	{
		if (it["summonerName"] == summonerName)
		{
			return it["team"];
		}
	}
	cout << "something goes wrong with Missions::getSummonerTeam()" << endl;
	return "";
}

string Missions::getCreepTeam(string& creepName)
{
	if (creepName.substr(7, 2) == "T1")
	{
		return "ORDER";
	}
	return "CHAOS";
}

string Missions::getInhibTeam(string& inhibName)
{
	if (inhibName.substr(9, 2) == "T1")
	{
		return "ORDER";
	}
	return "CHAOS";
}


int Missions::getActivePlayerMaxHealth(json* gameData)
{
	return gameData->operator[]("activePlayer")["championStats"]["maxHealth"];
}

void Missions::getPlayerList(json* gameData, vector<string>& playerList)
{
	for (auto it : gameData->operator[]("allPlayers"))
	{
		playerList.push_back(it["summonerName"]);
	}
}

void Missions::getTeamList(json* gameData, vector<string>& playerList, string& team)
{
	for (auto it : gameData->operator[]("allPlayers"))
	{
		if (it["team"] == team)
		{
			playerList.push_back(it["summonerName"]);
		}
	}
}

int Missions::getLastKillTimeEvent(json* gameData) //return -1 if nobody has been killed yet
{
	int lastKillEventTime(-1);
	for (auto it : gameData->operator[]("events")["Events"])
	{
		if (it["EventName"] == "ChampionKill")
		{
			lastKillEventTime = it["EventTime"];
		}
	}
	return lastKillEventTime;
}

vector<int> Missions::getRandomListOfMissionNumber(int& numberOfMissionsWanted, unsigned long long& randomSeed)
{
	if (numberOfMissionsWanted > TOTAL_NUMBER_OF_MISSIONS)
	{
		throw "Missions::getRandomMissionList : Sorry, you can request for " + to_string(TOTAL_NUMBER_OF_MISSIONS) + " maximum.";
	}
	if (numberOfMissionsWanted < 1)
	{
		throw "Missions::getRandomMissionList : Sorry, you can't request for less than one mission.";
	}

	srand(randomSeed);
	vector<int> listOfMissionNumber;
	listOfMissionNumber.push_back(rand() % TOTAL_NUMBER_OF_MISSIONS);

	while (listOfMissionNumber.size() < numberOfMissionsWanted)
	{
		int newMissionNumber = rand() % TOTAL_NUMBER_OF_MISSIONS;
		bool theNewNumberIsNotInTheList(true);

		for (int i = 0; i < listOfMissionNumber.size(); i++)
		{
			if (listOfMissionNumber[i] == newMissionNumber)
			{
				theNewNumberIsNotInTheList = false;
			}
		}

		if (theNewNumberIsNotInTheList)
		{
			listOfMissionNumber.push_back(newMissionNumber);
		}
	}
	return listOfMissionNumber;
}


vector<AbstractMission*> Missions::getRandomMissionList(int& numberOfMissionsWanted)
{
	unsigned long long actualTime(time(NULL));

	return getMissionListFromlistOfMissionNumber(Missions::getRandomListOfMissionNumber(numberOfMissionsWanted, actualTime));
}

vector<AbstractMission*> Missions::getRandomMissionListForGrid(int gridSize, string& saveSeed)
{
	int numberOfMissionsWanted(gridSize * gridSize);
	unsigned long long actualTime(time(NULL));

	saveSeed = to_string(gridSize) + to_string(actualTime);

	return getMissionListFromlistOfMissionNumber(Missions::getRandomListOfMissionNumber(numberOfMissionsWanted, actualTime));
}

vector<AbstractMission*> Missions::getMissionListFromGridSeed(string& gridSeed, string& saveSeed)
{
	int gridSize(std::stoi(gridSeed.substr(0, 1).c_str()));
	int numberOfMissionsWanted(gridSize * gridSize);
	unsigned long long seed(std::strtoull(gridSeed.substr(1).c_str(), NULL, 10));

	saveSeed = to_string(gridSize) + to_string(seed);

	return getMissionListFromlistOfMissionNumber(Missions::getRandomListOfMissionNumber(numberOfMissionsWanted, seed));
}

vector<AbstractMission*> Missions::getMissionListFromlistOfMissionNumber(vector<int> listOfMissionNumber)
{
	vector<AbstractMission*> missionList;

	for (int i = 0; i < listOfMissionNumber.size(); i++)
	{
		switch (listOfMissionNumber[i])
		{
		case 0:
			missionList.push_back(new M0);
			break;
		case 1:
			missionList.push_back(new M1);
			break;
		case 2:
			missionList.push_back(new M2);
			break;
		case 3:
			missionList.push_back(new M3);
			break;
		case 4:
			missionList.push_back(new M4);
			break;
		case 5:
			missionList.push_back(new M5);
			break;
		case 6:
			missionList.push_back(new M6);
			break;
		case 7:
			missionList.push_back(new M7);
			break;
		case 8:
			missionList.push_back(new M8);
			break;
		case 9:
			missionList.push_back(new M9);
			break;
		case 10:
			missionList.push_back(new M10);
			break;
		case 11:
			missionList.push_back(new M11);
			break;
		case 12:
			missionList.push_back(new M12);
			break;
		case 13:
			missionList.push_back(new M13);
			break;
		case 14:
			missionList.push_back(new M14);
			break;
		case 15:
			missionList.push_back(new M15);
			break;
		case 16:
			missionList.push_back(new M16);
			break;
		case 17:
			missionList.push_back(new M17);
			break;
		case 18:
			missionList.push_back(new M18);
			break;
		case 19:
			missionList.push_back(new M19);
			break;
		case 20:
			missionList.push_back(new M20);
			break;
		case 21:
			missionList.push_back(new M21);
			break;
		case 22:
			missionList.push_back(new M22);
			break;
		case 23:
			missionList.push_back(new M23);
			break;
		case 24:
			missionList.push_back(new M24);
			break;
		case 25:
			missionList.push_back(new M25);
			break;
		case 26:
			missionList.push_back(new M26);
			break;
		case 27:
			missionList.push_back(new M27);
			break;
		case 28:
			missionList.push_back(new M28);
			break;
		case 29:
			missionList.push_back(new M29);
			break;
		case 30:
			missionList.push_back(new M30);
			break;
		case 31:
			missionList.push_back(new M31);
			break;
		case 32:
			missionList.push_back(new M32);
			break;
		case 33:
			missionList.push_back(new M33);
			break;
		case 34:
			missionList.push_back(new M34);
			break;
		case 35:
			missionList.push_back(new M35);
			break;
		case 36:
			missionList.push_back(new M36);
			break;
		case 37:
			missionList.push_back(new M37);
			break;
		case 38:
			missionList.push_back(new M38);
			break;
		case 39:
			missionList.push_back(new M39);
			break;
		case 40:
			missionList.push_back(new M40);
			break;
		case 41:
			missionList.push_back(new M41);
			break;
		case 42:
			missionList.push_back(new M42);
			break;
		case 43:
			missionList.push_back(new M43);
			break;
		case 44:
			missionList.push_back(new M44);
			break;
		case 45:
			missionList.push_back(new M45);
			break;
		case 46:
			missionList.push_back(new M46);
			break;
		case 47:
			missionList.push_back(new M47);
			break;
		case 48:
			missionList.push_back(new M48);
			break;
		case 49:
			missionList.push_back(new M49);
			break;
		case 50:
			missionList.push_back(new M50);
			break;
		case 51:
			missionList.push_back(new M51);
			break;
		default:
			throw "Missions::getMissionListFromlistOfMissionNumber : One of the int in your list does not correspond with any mission.";
		}
	}
	return missionList;
}