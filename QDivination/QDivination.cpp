#include "QDivination.h"
#include "calendar.h"
#include "InputHexagramDlg.h"
#include <qdatetime.h>


QDivination::QDivination(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	connect(ui.actNew, SIGNAL(triggered()), this, SLOT(onNewDocument()));
}

void QDivination::onNewDocument()
{
	InputHexagramDlg dlg(this);
	if (dlg.exec() == QDialog::Accepted)
	{
		QDateTime dtTime = dlg.getInputDateTime();
		XXInfo info = dlg.getInputXXInfo();
		DataTime dataTime;
		dataTime.year = dtTime.date().year();
		dataTime.month = dtTime.date().month();
		dataTime.day = dtTime.date().day();
		dataTime.hour = dtTime.time().hour();
		dataTime.minute = dtTime.time().minute();
		dataTime.second = dtTime.time().second();
		divineInfo = new DivineInfo(&info, &dataTime, Man);


	}
	else
	{

	}
}