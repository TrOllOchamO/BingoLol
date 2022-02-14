#pragma once

#include <string>

#include <QObject>
#include <QWidget>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QGroupBox>
#include <QString>
#include <QDesktopServices>
#include <QUrl>
#include <QImage>
#include <QPixmap>
#include <QClipboard>
#include <QMimeData>
#include <QBuffer>

#include "BingoGrid.h"
#include "ClickableImage.h"
#include "SoundHandeler.h"

class ShareOption : public QWidget
{
	Q_OBJECT
public:
	ShareOption(BingoGrid* bingoGrid, SoundHandeler* soundHandeler, QWidget* parent = nullptr);
	~ShareOption();

public slots:
	void openGithubUrl();
	void copyGridToClipboard();
	void openPaypalUrl();
	void openTwitterUrl();
	void updateDisplayPannel(QString description);

signals:


private:
	QWidget* m_parent;
	BingoGrid* m_grid;
	SoundHandeler* m_soundHandeler;

	QVBoxLayout* m_mainLayout;
	QGridLayout* m_clickableImagesLayout;

	ClickableImage* m_githubImage;
	ClickableImage* m_clipboardImage;
	ClickableImage* m_paypalImage;
	ClickableImage* m_twitterImage;
	QLabel* m_infoDisplayPannel;
};
