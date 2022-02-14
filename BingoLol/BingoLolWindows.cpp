#include "BingoLolWindows.h"

BingoLolWindows::BingoLolWindows() : QWidget()
{
    QGridLayout* mainGridLayout = new QGridLayout(this);

    m_missionDescription = new MissionDescription(this);
    m_bingoGrid = new BingoGrid(5, m_missionDescription, this);
    m_bingoOptions = new BingoOptions(m_bingoGrid, this);

    mainGridLayout->addWidget(m_bingoOptions, 0, 0, 1, 1);
    mainGridLayout->addWidget(m_bingoGrid, 0, 1, 4, 4);
    mainGridLayout->addWidget(m_missionDescription, 5, 0, 1, 5);
    mainGridLayout->setSpacing(0);

    this->setLayout(mainGridLayout);
}

void BingoLolWindows::setWindowsSize(int gridSize)
{
    switch (gridSize)
    {
    case 5:
        this->setFixedSize(500, 500);
        break;
    case 4:
        this->setFixedSize(500, 500);
        break;
    default:
        throw "Invalid grid size passed as argument to the function BingoLolWindows::setWindowsSize(int gridSize)";
    }
}