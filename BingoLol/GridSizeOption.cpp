#include "GridSizeOption.h"

GridSizeOption::GridSizeOption(BingoGrid* grid, StartPlayingBingoButton* startStopPlayingButton, EventHandeler* eventHandeler, QWidget* parent) :
	QWidget(parent), m_parent(parent), m_bingoGrid(grid), m_startStopPlayingButton(startStopPlayingButton), m_eventHandeler(eventHandeler)
{
	m_mainLayout = new QVBoxLayout(this);
	m_grid5 = new QRadioButton("5 x 5", this);
	m_grid4 = new QRadioButton("4 x 4", this);

	m_buttonGetNewGrid = new QPushButton("Change grid", this);
	m_buttonResetMissions = new QPushButton("Reset grid", this);

	m_grid5->setChecked(true);
	m_grid5->setCursor(Qt::PointingHandCursor);
	m_grid4->setCursor(Qt::PointingHandCursor);
	m_grid4->setObjectName("radiobutton4"); // giving a name to be able to set a bottom margin in the stylesheet

	m_mainLayout->addWidget(m_grid5);
	m_mainLayout->addWidget(m_grid4);
	m_mainLayout->addWidget(m_buttonGetNewGrid);
	m_mainLayout->addWidget(m_buttonResetMissions);

	this->setLayout(m_mainLayout);

	QObject::connect(m_buttonResetMissions, SIGNAL(clicked()), m_bingoGrid, SLOT(resetMissions()));
	QObject::connect(m_buttonResetMissions, SIGNAL(clicked()), m_startStopPlayingButton, SLOT(stopPlayingGame()));
	QObject::connect(m_buttonResetMissions, SIGNAL(clicked()), m_eventHandeler, SLOT(destroyQueue()));

	QObject::connect(m_buttonGetNewGrid, SIGNAL(clicked()), this, SLOT(generateGrid()));
	QObject::connect(m_buttonGetNewGrid, SIGNAL(clicked()), m_startStopPlayingButton, SLOT(stopPlayingGame()));
	QObject::connect(m_buttonGetNewGrid, SIGNAL(clicked()), m_eventHandeler, SLOT(destroyQueue()));
}

GridSizeOption::~GridSizeOption()
{

}

void GridSizeOption::generateGrid()
{
	if (m_grid5->isChecked())
	{
		m_bingoGrid->changeGridMissions(5);
	}
	else
	{
		m_bingoGrid->changeGridMissions(4);
	}
}