/*
 * fbcellitem.h
 *
 * Copyright 2012-2012 Yang Hong
 *
 */

#ifndef FBCELLITEM_H
#define FBCELLITEM_H

#include <QGraphicsItem>
#include <QMutex>

#include "adbfb.h"

class FBCellItem : public QGraphicsItem
{
public:
	enum {
		UPDATE_INVALID = -1,
		UPDATE_DONE,
		UPDATE_IGNORED,
	};

	FBCellItem();
	FBCellItem(const QPixmap &p);

	QRectF boundingRect() const;
	void paint(QPainter *painter,
			const QStyleOptionGraphicsItem *option,
			QWidget *widget = 0);

	void paintFB(QPainter *painter);

	void setPixmap(const QPixmap &p);
	void setFBConnected(bool state);
	void setFBSize(QSize size);
	int  setFBRaw(QByteArray *raw);
	void setBPP(int n) { bpp = n; };

	int  getFBDataSize(void) {
		return fbSize.width() * fbSize.height() * bpp;
	}

protected:
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
	void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
	QPixmap pixmap;
	QSize cellSize;

	QByteArray bytes;
	QByteArray inn;
	QPixmap fb;
	QSize fbSize;
	int bpp;
	bool fbConnected;
	bool fbUpdated;

	QMutex mutex;
	quint16 lastSum;
};

#endif // FBCELLITEM_H
