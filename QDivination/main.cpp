#include "QDivination.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QDivination w;
	w.show();
	return a.exec();
}
