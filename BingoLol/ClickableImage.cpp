#include "ClickableImage.h"

ClickableImage::ClickableImage(QString description, QLabel* parent) :
	QLabel(parent), m_parent(parent), m_description(description)
{
	this->setCursor(Qt::PointingHandCursor);
}

ClickableImage::~ClickableImage()
{

}

void ClickableImage::enterEvent(QEvent*)
{
	emit hasBeenHovered(m_description);
}

void ClickableImage::mouseReleaseEvent(QMouseEvent *event)
{
	if (event->button() == Qt::LeftButton)
	{
		emit clicked();
	}
}