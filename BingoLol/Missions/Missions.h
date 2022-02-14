#pragma once

#include <string>
#include <vector>
#include <cstdlib>
#include <time.h>
#include <iostream>

#define TOTAL_NUMBER_OF_MISSIONS 52
#include "nlohmann/json.hpp"
#include "AbstractMission.h"
#include "M0.h"
#include "M1.h"
#include "M2.h"
#include "M3.h"
#include "M4.h"
#include "M5.h"
#include "M6.h"
#include "M7.h"
#include "M8.h"
#include "M9.h"
#include "M10.h"
#include "M11.h"
#include "M12.h"
#include "M13.h"
#include "M14.h"
#include "M15.h"
#include "M16.h"
#include "M17.h"
#include "M18.h"
#include "M19.h"
#include "M20.h"
#include "M21.h"
#include "M22.h"
#include "M23.h"
#include "M24.h"
#include "M25.h"
#include "M26.h"
#include "M27.h"
#include "M28.h"
#include "M29.h"
#include "M30.h"
#include "M31.h"
#include "M32.h"
#include "M33.h"
#include "M34.h"
#include "M35.h"
#include "M36.h"
#include "M37.h"
#include "M38.h"
#include "M39.h"
#include "M40.h"
#include "M41.h"
#include "M42.h"
#include "M43.h"
#include "M44.h"
#include "M45.h"
#include "M46.h"
#include "M47.h"
#include "M48.h"
#include "M49.h"
#include "M50.h"
#include "M51.h"


class Missions
{
public :
	static std::string getActivePlayerName(nlohmann::json* gameData);
	static int getSummonerFarm(nlohmann::json* gameData, std::string& summonerName);
	static long getActivePlayerGolds(nlohmann::json* gameData);
	static int getGameTime(nlohmann::json* gameData);
	static int getActivePlayerCurrentHealth(nlohmann::json* gameData);
	static bool getIfSummonerIsDead(nlohmann::json* gameData, std::string& summonerName);
	static int getIfTheGameIsFinished(nlohmann::json* gameData);
	static int getFirstBloodTime(nlohmann::json* gameData);
	static std::string getSummonerTeam(nlohmann::json* gameData, std::string& summonerName);
	static std::string getCreepTeam(std::string& creepName);
	static std::string getInhibTeam(std::string& inhibName);
	static int getActivePlayerMaxHealth(nlohmann::json* gameData);
	static void getPlayerList(nlohmann::json* gameData, std::vector<std::string>& playerList);
	static void getTeamList(nlohmann::json* gameData, std::vector<std::string>& playerList, std::string& team);
	static int getLastKillTimeEvent(nlohmann::json* gameData);
	static std::vector<AbstractMission*> getRandomMissionList(int& numberOfMissionsWanted);
	static std::vector<AbstractMission*> getRandomMissionListForGrid(int gridSize, std::string& saveSeed);
	static std::vector<AbstractMission*> getMissionListFromGridSeed(std::string& gridSeed, std::string& saveSeed);

private:
	static std::vector<int> getRandomListOfMissionNumber(int& numberOfMissionsWanted, unsigned long long& randomSeed);
	static std::vector<AbstractMission*> getMissionListFromlistOfMissionNumber(std::vector<int> listOfMissionNumber);

};