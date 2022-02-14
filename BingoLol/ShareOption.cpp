#include "ShareOption.h"

ShareOption::ShareOption(BingoGrid* bingoGrid, SoundHandeler* soundHandeler, QWidget* parent) :
	QWidget(parent), m_parent(parent), m_grid(bingoGrid), m_soundHandeler(soundHandeler)
{
	m_mainLayout = new QVBoxLayout(this);
	m_clickableImagesLayout = new QGridLayout();
	
	m_infoDisplayPannel = new QLabel(this);
	m_infoDisplayPannel->setText("Hoover icons above to show details.");
	m_infoDisplayPannel->setObjectName("shareDisplay");
	m_infoDisplayPannel->setMinimumHeight(40);

	m_githubImage = new ClickableImage("Go to the project website.");
	m_clipboardImage = new ClickableImage("Get a screenshot of your grid in your clipboard.");
	m_paypalImage = new ClickableImage("Donate on Paypal.");
	m_twitterImage = new ClickableImage("Follow on twitter.");

	m_githubImage->setObjectName("github");
	m_clipboardImage->setObjectName("clipboard");
	m_paypalImage->setObjectName("paypal");
	m_twitterImage->setObjectName("twitter");
	
	m_clickableImagesLayout->addWidget(m_githubImage, 0, 0, 1, 1);
	m_clickableImagesLayout->addWidget(m_clipboardImage, 0, 1, 1, 1);
	m_clickableImagesLayout->addWidget(m_paypalImage, 1, 0, 1, 1);
	m_clickableImagesLayout->addWidget(m_twitterImage, 1, 1, 1, 1);

	m_mainLayout->addLayout(m_clickableImagesLayout);
	m_mainLayout->addWidget(m_infoDisplayPannel);

	// making sure the display pannel dont grow instead of wordwrapping
	m_infoDisplayPannel->setMaximumWidth(100);
	QSizePolicy qsp(QSizePolicy::Fixed, QSizePolicy::Fixed);
	m_infoDisplayPannel->setSizePolicy(qsp);

	this->setLayout(m_mainLayout);

	QObject::connect(m_githubImage, SIGNAL(clicked()), this, SLOT(openGithubUrl()));
	QObject::connect(m_githubImage, SIGNAL(hasBeenHovered(QString)), this, SLOT(updateDisplayPannel(QString)));

	QObject::connect(m_clipboardImage, SIGNAL(clicked()), this, SLOT(copyGridToClipboard()));
	QObject::connect(m_clipboardImage, SIGNAL(hasBeenHovered(QString)), this, SLOT(updateDisplayPannel(QString)));

	QObject::connect(m_paypalImage, SIGNAL(clicked()), this, SLOT(openPaypalUrl()));
	QObject::connect(m_paypalImage, SIGNAL(hasBeenHovered(QString)), this, SLOT(updateDisplayPannel(QString)));

	QObject::connect(m_twitterImage, SIGNAL(clicked()), this, SLOT(openTwitterUrl()));
	QObject::connect(m_twitterImage, SIGNAL(hasBeenHovered(QString)), this, SLOT(updateDisplayPannel(QString)));
}

ShareOption::~ShareOption()
{

}

void ShareOption::openGithubUrl()
{
	QString link = "https://github.com/TrOllOchamO/BingoLol";
	QDesktopServices::openUrl(QUrl(link));
}

void ShareOption::copyGridToClipboard()
{
	QPixmap gridPixmmap(m_grid->grab()); //create a pixmap of the actual grid
	QImage gridScreenShot(gridPixmmap.toImage()); //convert the pixmap to a QImage Object

	QMimeData* data = new QMimeData;
	QClipboard* clipboard = QGuiApplication::clipboard();
	data->setImageData(gridScreenShot);
	clipboard->setMimeData(data); //set the screen shot in the clipboard

	m_grid->flash();
	m_soundHandeler->playSound(SoundHandeler::SCREENSHOT);
}

void ShareOption::openPaypalUrl()
{
	QString link = "https://paypal.me/TrOllOchamO?locale.x=fr_FR";
	QDesktopServices::openUrl(QUrl(link));
}

void ShareOption::openTwitterUrl()
{
	QString link = "https://twitter.com/BingoLolOff?t=yPA1L9fdSnT5uPuYASeYLQ&s=09";
	QDesktopServices::openUrl(QUrl(link));
}

void ShareOption::updateDisplayPannel(QString description)
{
	m_infoDisplayPannel->setText(description);
}
