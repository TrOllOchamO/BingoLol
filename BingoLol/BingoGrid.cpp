#include "BingoGrid.h"

using namespace std;

BingoGrid::BingoGrid(int size, MissionDescription* missionDescription, QWidget* parent) : 
	QWidget(parent), m_parent(parent), m_missionDescription(missionDescription), m_clientData(&m_gameData), m_actualSeed(""), m_haSucceededToGetGameDataBefore(false)
{
	m_mainLayout = new QGridLayout;
	m_grid = new QGridLayout;
	m_flash = new QLabel;
	m_flashEffect = new QGraphicsOpacityEffect(this);
	m_flashAnimation = new QPropertyAnimation(m_flashEffect, "opacity");

	m_flash->setStyleSheet("background-color : #FFFFFF;");
	m_flash->setAttribute(Qt::WA_TransparentForMouseEvents);
	m_flash->setGraphicsEffect(m_flashEffect);
	m_flash->hide();

	m_flashAnimation->setDuration(400);
	m_flashAnimation->setStartValue(0.8);
	m_flashAnimation->setEndValue(0);
	m_flashAnimation->setEasingCurve(QEasingCurve::OutExpo); // correpond the best to a flash behaviour https://doc.qt.io/qt-5/qeasingcurve.html

	m_mainLayout->addLayout(m_grid, 0, 0, -1, -1);
	m_mainLayout->addWidget(m_flash, 0, 0, -1, -1);

	BingoGrid::fillEmptyGridRandomly(size);

	QSizePolicy qsp(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
	qsp.setHeightForWidth(true);
	this->setSizePolicy(qsp);

	this->setLayout(m_mainLayout);

}

BingoGrid::~BingoGrid()
{
	for (int i = 0; i < m_size * m_size; i++)
	{
		delete m_cellsList[i];
	}
}

void BingoGrid::resetMissions()
{
	for (int i = 0; i < m_size * m_size; i++)
	{
		m_cellsList[i]->resetMission();
		m_cellsList[i]->setCellToNormalMode();
	}

	for (int i = 0; i < m_size; i++)
	{
		m_numberOfWinMissionsPerRow[i] = 0;
		m_numberOfWinMissionsPerColumn[i] = 0;
	}
	UsefullFunc::refreshStyleSheet(this);
}

void BingoGrid::checkForCompletedLine()
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_numberOfWinMissionsPerRow[i] == m_size)
		{
			m_numberOfWinMissionsPerRow[i] = 0;
			emit bingoWon();
		}
		if (m_numberOfWinMissionsPerColumn[i] == m_size)
		{
			m_numberOfWinMissionsPerColumn[i] = 0;
			emit bingoWon();
		}
	}
}

void BingoGrid::runMissions()
{
	// if m_hasRecentlyFailToGetGameData > 0 wait a bit, dont send an other request yet
	if (m_hasRecentlyFailToGetGameData > 0) 
	{
		m_hasRecentlyFailToGetGameData -= 1;
	}
	//else send a request
	else 
	{
		//running the missions if we get data from the api
		if (m_clientData.uptadeGamedata()) 
		{
			//running the missions only if the last time we alredy had suceeded to get the data (avoid crash when the game start)
			if (m_haSucceededToGetGameDataBefore) 
			{
				bool anyMissionFinish(false);

				for (int row = 0; row < m_size; row++)
				{
					for (int column = 0; column < m_size; column++)
					{
						int cellNumber(row * m_size + column);

						//run the mission, if return true the mission is finished
						if (m_cellsList[cellNumber]->runMission()) 
						{
							if (m_cellsList[cellNumber]->getIfMissionSucceed())
							{
								m_cellsList[cellNumber]->setCellToSucceedMode();
								m_numberOfWinMissionsPerRow[row] += 1;
								m_numberOfWinMissionsPerColumn[column] += 1;
								anyMissionFinish = true;
							}
							else
							{
								m_cellsList[cellNumber]->setCellToFailMode();
							}
							emit missionFinished(m_cellsList[cellNumber]->getMissionPointer());
						}
					}
				}

				if (anyMissionFinish)
				{
					this->checkForCompletedLine();
				}
			}
			else
			{
				m_haSucceededToGetGameDataBefore = true;
			}

		}
		//if we failed to get the data, we set m_hasRecentlyFailToGetGameData to a positif value,
		//so the next time the timer will call the function it wont send an other reqtest
		else 
		{	 
			m_haSucceededToGetGameDataBefore = false;
			m_hasRecentlyFailToGetGameData = 20; 
		}
	}
}


void BingoGrid::fillEmptyGrid(vector<AbstractMission*> missionList, int gridSize)
{
	m_size = gridSize;
	int numberOfCells(m_size * m_size);

	for (int i = 0; i < m_size; i++)
	{
		m_numberOfWinMissionsPerRow.push_back(0);
		m_numberOfWinMissionsPerColumn.push_back(0);
	}

	for (int row = 0; row < m_size; row++)
	{
		for (int column = 0; column < m_size; column++)
		{
			int cellNumber(row * m_size + column);
			m_cellsList.push_back(new BingoCell(m_missionDescription, m_parent));
			m_cellsList[cellNumber]->setMission(missionList[cellNumber]);
			m_cellsList[cellNumber]->setMissionGameData(&m_gameData);
			m_cellsList[cellNumber]->displayMissionName();
			m_grid->addWidget(m_cellsList[cellNumber], row, column, 1, 1);
		}
	}

	m_flash->raise(); //replace the flash on top of the grid
}

void BingoGrid::fillEmptyGridRandomly(int size)
{
	vector<AbstractMission*> missionList(Missions::getRandomMissionListForGrid(size, m_actualSeed));
	BingoGrid::fillEmptyGrid(missionList, size);
}

void BingoGrid::fillEmptyGridWithSeed(string seed)
{
	int gridSize(std::stoi(seed.substr(0, 1).c_str()));
	vector<AbstractMission*> missionList(Missions::getMissionListFromGridSeed(seed, m_actualSeed));
	BingoGrid::fillEmptyGrid(missionList, gridSize);
}

void BingoGrid::emptyTheGrid()
{
	for (int i = 0; i < m_size * m_size; i++)
	{
		m_grid->removeWidget(m_cellsList[i]);
		delete m_cellsList[i];
	}
	m_cellsList.clear();
	m_numberOfWinMissionsPerColumn.clear();
	m_numberOfWinMissionsPerRow.clear();
}

void BingoGrid::changeGridMissions(int size)
{
	this->emptyTheGrid();
	this->fillEmptyGridRandomly(size);
	emit gridSeedHasChanged();
}

void BingoGrid::setGridMissionsFromSeed(std::string seed)
{
	this->emptyTheGrid();
	this->fillEmptyGridWithSeed(seed);
}

string BingoGrid::getActualGridSeed()
{
	return m_actualSeed;
}

void BingoGrid::flash()
{
	m_flash->show();
	m_flashAnimation->start();
}