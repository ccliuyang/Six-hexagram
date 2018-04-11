#pragma once

#include <QDialog>
#include <qmenu.h>
#include <qaction.h>
#include "BaGua.h"

namespace Ui { class MainDlg; };

class CGuaInfo;

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

	void onStart();
private:
	XXSymbol getXXSymbol(int index);

private:
	Ui::MainDlg *ui;
	QAction* actNew;
	QAction* actOpen;
	QAction* actSave;
	QAction* actSetting;
	QAction* actAbout;
	QAction* actNewMethod;
	QMenu* menu;

	CGuaInfo *m_guaInfo;
};
