#include "GridSeedOption.h"

GridSeedOption::GridSeedOption(BingoGrid* grid, EventHandeler* eventHandeler, StartPlayingBingoButton* startPlayingBingoButton, QWidget* parent) :
	QWidget(parent), m_parent(parent), m_grid(grid), m_eventHandeler(eventHandeler), m_startPlayingBingoButton(startPlayingBingoButton)
{
	const QRegExp re("[4|5][0-9]{0,19}"); // the seed must start by a valid grid size (5 or 4)
										  // and the following is 0 up to 19 digits (no more or the unsigned long long will overflow)

	m_mainLayout = new QVBoxLayout(this);
	m_inputLayout = new QHBoxLayout;
	m_seedDisplay = new QLabel("The actual seed is :", this);
	m_seedInput = new QLineEdit(this);
	m_seedValidator = new QRegExpValidator(re, this);
	m_buttonSetSeed = new QPushButton("Set seed", this);
	m_buttonCopySeedToClipboard = new ClickableImage(QString::fromStdString(""));
	
	m_inputLayout->addWidget(m_seedInput);
	m_inputLayout->addWidget(m_buttonCopySeedToClipboard);

	m_seedInput->setPlaceholderText("Seed");
	m_seedInput->setValidator(m_seedValidator);
	m_seedInput->setText(QString::fromStdString(m_grid->getActualGridSeed()));
	m_buttonSetSeed->setCursor(Qt::PointingHandCursor);
	m_buttonCopySeedToClipboard->setCursor(Qt::PointingHandCursor);
	m_buttonCopySeedToClipboard->setObjectName("seedClipboard");
	m_buttonCopySeedToClipboard->setMinimumSize(16, 16);

	m_mainLayout->addWidget(m_seedDisplay);
	m_mainLayout->addLayout(m_inputLayout);
	m_mainLayout->addWidget(m_buttonSetSeed);

	this->setLayout(m_mainLayout);

	QObject::connect(m_grid, SIGNAL(gridSeedHasChanged()), this, SLOT(updateSeedDisplay()));

	QObject::connect(m_buttonSetSeed, SIGNAL(clicked()), this, SLOT(setSeed()));
	QObject::connect(m_buttonSetSeed, SIGNAL(clicked()), m_grid, SLOT(resetMissions()));
	QObject::connect(m_buttonSetSeed, SIGNAL(clicked()), m_startPlayingBingoButton, SLOT(stopPlayingGame()));
	QObject::connect(m_buttonSetSeed, SIGNAL(clicked()), m_eventHandeler, SLOT(destroyQueue()));

	QObject::connect(m_buttonCopySeedToClipboard, SIGNAL(clicked()), this, SLOT(copySeedToClipboard()));
}

GridSeedOption::~GridSeedOption()
{

}

void GridSeedOption::setSeed()
{
	std::string seed(m_seedInput->text().toStdString());
	if (seed.length() > 1)
	{
		m_grid->setGridMissionsFromSeed(seed);
	}
}

void GridSeedOption::updateSeedDisplay()
{
	m_seedInput->setText(QString::fromStdString(m_grid->getActualGridSeed()));
}

void GridSeedOption::copySeedToClipboard()
{
	std::string seed(m_seedInput->text().toStdString());
	QClipboard* clipboard = QGuiApplication::clipboard();

	clipboard->setText(QString::fromStdString(seed));
}