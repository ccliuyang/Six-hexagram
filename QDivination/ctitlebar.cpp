#include "ctitlebar.h"
#include <qevent.h>
#include <qstyleoption.h>
#include <qpainter.h>

CTitleBar::CTitleBar(QWidget *parent)
	: QWidget(parent)
{
}

CTitleBar::~CTitleBar()
{
}

void CTitleBar::mousePressEvent(QMouseEvent * e)
{
	if (e->button() == Qt::LeftButton)
	{
		mousePressed = true;
		mousePt = (e->globalPos() - parentWidget()->pos());
	}
}

void CTitleBar::mouseMoveEvent(QMouseEvent * e)
{
	if (mousePressed && (e->buttons() & Qt::LeftButton))
		this->parentWidget()->move(e->globalPos() - mousePt);
}

void CTitleBar::mouseReleaseEvent(QMouseEvent * e)
{
	mousePressed = false;
}

void CTitleBar::paintEvent(QPaintEvent *)
{
	QStyleOption opt;
	opt.init(this);
	QPainter p(this);
	style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}

void CTitleBar::mouseDoubleClickEvent(QMouseEvent * e)
{
}
