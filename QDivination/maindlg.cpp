#include "maindlg.h"
#include "ui_maindlg.h"
#include <qmenu.h>
#include <qaction.h>
#include <qmessagebox.h>

MainDlg::MainDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::MainDlg();
	ui->setupUi(this);
	setWindowFlags(Qt::FramelessWindowHint);
	connect(ui->btnMenuMin, SIGNAL(clicked()), this, SLOT(onMinWindow()));
	connect(ui->btnMenuClose, SIGNAL(clicked()), this, SLOT(onCloseWindow()));

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
	menu->addAction(actNewMethod);
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

void MainDlg::onMinWindow()
{
	showMinimized();
}
