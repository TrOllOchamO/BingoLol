#pragma once

#include <string>

#include <QObject>
#include <QWidget>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include <QPixmap>
#include <QMouseEvent>


class ClickableImage : public QLabel
{
	Q_OBJECT
public:
	ClickableImage(QString description, QLabel* parent = nullptr);
	~ClickableImage();

signals:
	void hasBeenHovered(QString description);
	void clicked();

private:
	void enterEvent(QEvent*);
	void mouseReleaseEvent(QMouseEvent* event);

	QWidget* m_parent;
	
	QString m_description;
};