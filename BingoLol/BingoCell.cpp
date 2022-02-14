#include "BingoCell.h"

using string = std::string;

BingoCell::BingoCell(MissionDescription* missionDescription, QWidget* parent) : QLabel(parent), m_mission(0), m_missionDescription(missionDescription)
{
	this->setCellToNormalMode();
	this->setMinimumSize(112, 112);

	QSizePolicy qsp(QSizePolicy::Minimum, QSizePolicy::Minimum);
	qsp.setHeightForWidth(true);
	this->setSizePolicy(qsp);
}

BingoCell::~BingoCell()
{
	delete m_mission;
}

void BingoCell::setMission(AbstractMission* mission)
{
	m_mission = mission;
}

void BingoCell::setMissionGameData(nlohmann::json* gameData)
{
	m_mission->setGameData(gameData);
}

bool BingoCell::runMission()
{
	return m_mission->runMission();
}

void BingoCell::resetMission()
{
	m_mission->resetMission();
}

bool BingoCell::getIfMissionFailed() const
{
	return m_mission->getIfMissionFailed();
}

bool BingoCell::getIfMissionSucceed() const
{
	return m_mission->getIfMissionSucceed();
}

AbstractMission* BingoCell::getMissionPointer() const
{
	return m_mission;
}

string BingoCell::getMissionName() const
{
	return m_mission->getMissionName();
}

string BingoCell::getMissionDescription() const
{
	return m_mission->getMissionDescription();
}

void BingoCell::setCellToFailMode()
{
	this->setObjectName("fail");
	UsefullFunc::refreshStyleSheet(this);
}

void BingoCell::setCellToNormalMode()
{
	this->setObjectName("normal");
}

void BingoCell::setCellToSucceedMode()
{
	this->setObjectName("succeed");
	UsefullFunc::refreshStyleSheet(this);
}

void BingoCell::displayMissionName()
{
	this->setText(QString::fromStdString(m_mission->getMissionName()));
}

void BingoCell::enterEvent(QEvent*)
{
	string missionName(m_mission->getMissionName());
	string missionDescription(m_mission->getMissionDescription());
	string description("<b>" + missionName + "</b><br>" + missionDescription);

	m_missionDescription->setText(QString::fromStdString(description));
}