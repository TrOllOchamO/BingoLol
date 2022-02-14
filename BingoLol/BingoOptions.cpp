#include "BingoOptions.h"

BingoOptions::BingoOptions(BingoGrid* bingoGrid, QWidget* parent) :
	m_parent(parent), m_bingoGrid(bingoGrid)
{
	m_mainLayout = new QVBoxLayout(this);

	m_bingoLolSection = new QLabel("<b>BINGO</b>", this);
	m_soundSection = new QLabel("<b>SOUNDS</b>", this);
	m_gridSection = new QLabel("<b>GRID</b>", this);

	m_bingoLolSection->setObjectName("section");
	m_soundSection->setObjectName("section");
	m_gridSection->setObjectName("section");

	m_soundHandeler = new SoundHandeler(this);
	m_shareOption = new ShareOption(m_bingoGrid, m_soundHandeler, this);
	m_startStopPlayingButton = new StartPlayingBingoButton(m_bingoGrid, this);
	m_eventHandeler = new EventHandeler(m_bingoGrid, m_soundHandeler, this);
	m_soundOptions = new SoundsOption(m_bingoGrid, m_soundHandeler, this);
	m_gridSizeOption = new GridSizeOption(m_bingoGrid, m_startStopPlayingButton, m_eventHandeler, this);
	m_gridSeedOption = new GridSeedOption(m_bingoGrid, m_eventHandeler, m_startStopPlayingButton, this);

	m_mainLayout->addWidget(m_startStopPlayingButton);

	m_mainLayout->addWidget(m_bingoLolSection);
	m_mainLayout->addWidget(m_shareOption);

	m_mainLayout->addWidget(m_soundSection);
	m_mainLayout->addWidget(m_soundOptions);

	m_mainLayout->addWidget(m_gridSection);
	m_mainLayout->addWidget(m_gridSizeOption);
	m_mainLayout->addWidget(m_gridSeedOption);

	QSizePolicy qsp;
	qsp.setHeightForWidth(true);
	this->setSizePolicy(qsp);

	this->setLayout(m_mainLayout);
}

BingoOptions::~BingoOptions()
{

}