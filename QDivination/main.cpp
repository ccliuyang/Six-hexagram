#include <QtWidgets/QApplication>
#include <qfile.h>
#include "maindlg.h"

void setStyle(const QString &qssFile)
{
	QFile file(qssFile);
	if (file.open(QFile::ReadOnly))
	{
		QString qss = QLatin1String(file.readAll());
		qApp->setStyleSheet(qss);
		file.close();
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	setStyle(":/QDivination/qss/black.css");

	MainDlg w;
	w.show();

//	QDivination w;
//	w.show();
	return a.exec();
}
