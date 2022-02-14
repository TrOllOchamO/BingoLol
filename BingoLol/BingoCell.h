#pragma once

#include <QWidget>
#include <QLabel>
#include <QMouseEvent>
#include <string>

#include <nlohmann/json.hpp>

#include "Missions/AbstractMission.h"
#include "MissionDescription.h"
#include "UsefullFunc.h"

class BingoCell : public QLabel
{
	Q_OBJECT

public:
	BingoCell(MissionDescription* missionDescription, QWidget* parent = nullptr);
	~BingoCell();
	void setMission(AbstractMission* mission);
	void setMissionGameData(nlohmann::json* gameData);
	bool runMission();
	void resetMission();
	bool getIfMissionFailed() const;
	bool getIfMissionSucceed() const;
	AbstractMission* getMissionPointer() const;
	std::string getMissionName() const;
	std::string getMissionDescription() const;
	void setCellToFailMode();
	void setCellToNormalMode();
	void setCellToSucceedMode();
	void displayMissionName();


private:
	void enterEvent(QEvent*);
	MissionDescription* m_missionDescription;
	AbstractMission* m_mission;
};