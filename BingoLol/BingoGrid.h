#pragma once

#include <vector>
#include <iostream>
#include <string>

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QMessagebox.h>
#include <QTimer>
#include <QGraphicsEffect>
#include <QPropertyAnimation>
#include <QSizePolicy>

#include "nlohmann/json.hpp"

#include "Missions/Missions.h"
#include "Missions/AbstractMission.h"
#include "Missions/ClientData.h"
#include "BingoCell.h"

class BingoGrid : public QWidget
{
	Q_OBJECT

public:
	BingoGrid(int size, MissionDescription* missionDescription, QWidget* parent = nullptr);
	~BingoGrid();
	std::string getActualGridSeed();

public slots:
	void resetMissions();
	void runMissions();
	void changeGridMissions(int size);
	void setGridMissionsFromSeed(std::string seed);
	void flash();

signals:
	void bingoWon();
	void missionFinished(AbstractMission* mission);
	void gridSeedHasChanged();

private:
	void emptyTheGrid();
	void fillEmptyGrid(std::vector<AbstractMission*> missionList, int gridSize);
	void fillEmptyGridRandomly(int size);
	void fillEmptyGridWithSeed(std::string seed);
	void checkForCompletedLine();

	std::string m_actualSeed;
	int m_size;
	int m_hasRecentlyFailToGetGameData;
	bool m_haSucceededToGetGameDataBefore;
	QGridLayout* m_mainLayout;
	QGridLayout* m_grid;
	QWidget* m_parent;
	ClientData m_clientData;
	nlohmann::json m_gameData;
	MissionDescription* m_missionDescription;
	std::vector<int> m_numberOfWinMissionsPerRow;
	std::vector<int> m_numberOfWinMissionsPerColumn;
	std::vector<BingoCell*> m_cellsList;

	QLabel* m_flash;
	QGraphicsOpacityEffect* m_flashEffect;
	QPropertyAnimation* m_flashAnimation;
};
