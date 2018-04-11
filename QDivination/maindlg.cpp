#include "maindlg.h"
#include "ui_maindlg.h"
#include <qmenu.h>
#include <qaction.h>
#include <qmessagebox.h>
#include "cdatetime.h"
#include "cguainfo.h"

MainDlg::MainDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::MainDlg();
	ui->setupUi(this);
	ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());
	setWindowFlags(Qt::FramelessWindowHint);
	connect(ui->btnMenuMin, SIGNAL(clicked()), this, SLOT(onMinWindow()));
	connect(ui->btnMenuClose, SIGNAL(clicked()), this, SLOT(onCloseWindow()));
	connect(ui->btnStart, SIGNAL(clicked()), this, SLOT(onStart()));

	actNew = new QAction(tr("New"), this);
	actOpen = new QAction(tr("Open"), this);
	actAbout = new QAction(tr("About"), this);
	actNewMethod = new QAction(tr("New Method"), this);
	actSave = new QAction(tr("Save"), this);
	actSetting = new QAction(tr("Setting"), this);
	connect(actNew, SIGNAL(triggered()), this, SLOT(onNew()));
	connect(actOpen, SIGNAL(triggered()), this, SLOT(onOpen()));
	connect(actAbout, SIGNAL(triggered()), this, SLOT(onAbout()));
	connect(actNewMethod, SIGNAL(triggered()), this, SLOT(onNewMethod()));
	connect(actSave, SIGNAL(triggered()), this, SLOT(onSave()));
	connect(actSetting, SIGNAL(triggered()), this, SLOT(onSettings()));


	menu = new QMenu(this);
	menu->addAction(actNew);
//	menu->addAction(actNewMethod);
	menu->addAction(actOpen);
	menu->addAction(actSave);
	menu->addAction(actSetting);
	menu->addAction(actAbout);
	connect(ui->btnMenu, SIGNAL(clicked()), this, SLOT(onMenu()));

}

MainDlg::~MainDlg()
{
	delete ui;
}

void MainDlg::onCloseWindow()
{
	close();

}

void MainDlg::onMenu()
{
	menu->show();

	menu->move(cursor().pos());
}

void MainDlg::onSettings()
{
}

void MainDlg::onNew()
{
}

void MainDlg::onNewMethod()
{
}

void MainDlg::onOpen()
{
}

void MainDlg::onSave()
{
}

void MainDlg::onAbout()
{
	QMessageBox::about(this, tr("About"),
		tr("The <b>QDivination</b> is used to divine the  "
			"result of what's in your mind.     <br />"
			"Email:416954509@qq.com"));
}

void MainDlg::onStart()
{
	QDateTime tm = ui->dateTimeEdit->dateTime();
	DateTime dtTime;
	dtTime.year = tm.date().year();
	dtTime.month = tm.date().month();
	dtTime.day = tm.date().day();
	dtTime.hour = tm.time().hour();
	dtTime.minute = tm.time().minute();
	dtTime.second = tm.time().second();

	CDateTime dateTime;
	dateTime.setDateTime(&dtTime);
	XXInfo info;
	info.xxSymbol[0] = getXXSymbol(ui->cb_1->currentIndex());
	info.xxSymbol[1] = getXXSymbol(ui->cb_2->currentIndex());
	info.xxSymbol[2] = getXXSymbol(ui->cb_3->currentIndex());
	info.xxSymbol[3] = getXXSymbol(ui->cb_4->currentIndex());
	info.xxSymbol[4] = getXXSymbol(ui->cb_5->currentIndex());
	info.xxSymbol[5] = getXXSymbol(ui->cb_6->currentIndex());

	m_guaInfo = new CGuaInfo(&info, &dateTime);
	ui->textBrowser->setText(QString::fromLocal8Bit(m_guaInfo->getGuaInfo().c_str()));

//	ui->textBrowser->setText()

}

XXSymbol MainDlg::getXXSymbol(int index)
{
	switch (index)
	{
	case 0:
		return ShaoYang;
	case 1:
		return ShaoYin;
	case 2:
		return LaoYang;
	case 3:
		return LaoYin;
	default:
		return ShaoYang;
	}
}

void MainDlg::onMinWindow()
{
	showMinimized();
}
