#pragma once

#include <QDialog>
#include <qmenu.h>
#include <qaction.h>

namespace Ui { class MainDlg; };

class MainDlg : public QDialog
{
	Q_OBJECT

public:
	MainDlg(QWidget *parent = Q_NULLPTR);
	~MainDlg();

private slots:	
	void onMinWindow();
	void onCloseWindow();
	void onMenu();

	void onSettings();
	void onNew();
	void onNewMethod();
	void onOpen();
	void onSave();
	void onAbout();

private:
	Ui::MainDlg *ui;
	QAction* actNew;
	QAction* actOpen;
	QAction* actSave;
	QAction* actSetting;
	QAction* actAbout;
	QAction* actNewMethod;
	QMenu* menu;

};
