#include "guawidget.h"
#include "cguainfo.h"


GuaWidget::GuaWidget(QWidget *parent)
	: QWidget(parent)
{
	
}

GuaWidget::~GuaWidget()
{
}

void GuaWidget::setGuaInfo(CGuaInfo * pInfo)
{

	this->update();
}


void GuaWidget::paintEvent(QPaintEvent * event)
{
	
}
