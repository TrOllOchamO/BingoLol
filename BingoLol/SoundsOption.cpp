#include "SoundsOption.h"

SoundsOption::SoundsOption(BingoGrid* grid, SoundHandeler* soundHandeler, QWidget* parent) :
	QWidget(parent), m_parent(parent), m_grid(grid), m_soundHandeler(soundHandeler)
{
	m_activateSoundCheckBox = new QCheckBox("Sounds effects", this);
	m_volumeSlider = new QSlider(Qt::Horizontal, this);
	m_mainLayout = new QVBoxLayout(this);
	m_sliderLayout = new QHBoxLayout();
	m_volumeDisplay = new QLabel(this);

	m_volumeSlider->setRange(0, 100);
	m_volumeSlider->setValue(50);
	m_volumeSlider->setCursor(Qt::PointingHandCursor);
	m_volumeDisplay->setObjectName("volumeDisplay");
	m_volumeDisplay->setText("50");
	m_volumeDisplay->setFixedSize(18, 15);
	m_activateSoundCheckBox->setChecked(true);
	m_activateSoundCheckBox->setCursor(Qt::PointingHandCursor);

	m_sliderLayout->addWidget(m_volumeSlider);
	m_sliderLayout->addWidget(m_volumeDisplay);

	m_mainLayout->addWidget(m_activateSoundCheckBox);
	m_mainLayout->addLayout(m_sliderLayout);

	this->setLayout(m_mainLayout);
	this->m_mainLayout->setSpacing(3);

	QObject::connect(m_volumeSlider, SIGNAL(valueChanged(int)), m_volumeDisplay, SLOT(setNum(int)));
	QObject::connect(m_volumeSlider, SIGNAL(valueChanged(int)), this, SLOT(convertSliderValueToFloat(int)));
	QObject::connect(this, SIGNAL(volumeValueChanged(float)), m_soundHandeler, SLOT(setVolumeLevel(float)));
	QObject::connect(m_activateSoundCheckBox, SIGNAL(stateChanged(int)), m_soundHandeler, SLOT(activateOrDesactivateSound(int)));
}

SoundsOption::~SoundsOption()
{

}

void SoundsOption::convertSliderValueToFloat(int sliderValue)
{
	float floatVolumeValue = sliderValue / 100.0;
	emit volumeValueChanged(floatVolumeValue);
}