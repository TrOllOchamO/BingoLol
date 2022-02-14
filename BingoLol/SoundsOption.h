#pragma once

#include <string>

#include <QObject>
#include <QWidget>
#include <QCheckBox>
#include <QSlider>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QString>

#include "BingoGrid.h"
#include "SoundHandeler.h"

class SoundsOption : public QWidget
{
	Q_OBJECT
public:
	SoundsOption(BingoGrid* grid, SoundHandeler* soundHandeler, QWidget* parent = nullptr);
	~SoundsOption();

public slots:
	void convertSliderValueToFloat(int sliderValue);

signals:
	void volumeValueChanged(float newVolume);

private:
	QWidget* m_parent;
	BingoGrid* m_grid;
	SoundHandeler* m_soundHandeler;

	QVBoxLayout* m_mainLayout;
	QHBoxLayout* m_sliderLayout;
	QLabel* m_volumeDisplay;
	QSlider* m_volumeSlider;
	QCheckBox* m_activateSoundCheckBox;
};