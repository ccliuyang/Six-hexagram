#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QDivination.h"

class DivineInfo;

class QDivination : public QMainWindow
{
	Q_OBJECT

public:
	QDivination(QWidget *parent = Q_NULLPTR);

private:
	Ui::QDivinationClass ui;
	DivineInfo *divineInfo;
};
