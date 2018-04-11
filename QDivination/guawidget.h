#pragma once

#include <QWidget>

class CGuaInfo;

class GuaWidget : public QWidget
{
	Q_OBJECT

public:
	GuaWidget(QWidget *parent);
	~GuaWidget();
	void setGuaInfo(CGuaInfo* pInfo);

	friend class CGuaInfo;


protected:
	virtual void paintEvent(QPaintEvent* event);

private:
	CGuaInfo* m_guaInfo;
};
