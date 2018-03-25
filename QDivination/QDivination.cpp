#include "QDivination.h"
#include "calendar.h"


QDivination::QDivination(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	XXInfo info;
	for (int i = 0; i < 6; i++)
	{
		info.xxSymbol[i] = ShaoYang;
	}
	
	DataTime dataTime;
	dataTime.year = 2018;
	dataTime.month = 3;
	dataTime.day = 5;
	dataTime.hour = 15;
	dataTime.minute = 03;
	dataTime.second = 0;

	divineInfo = new DivineInfo(&info, &dataTime, Man);

}
