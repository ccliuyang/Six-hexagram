#pragma once

#include <QDialog>
#include "calendar.h"

namespace Ui { class InputHexagramDlg; };

class InputHexagramDlg : public QDialog
{
	Q_OBJECT

public:
	InputHexagramDlg(QWidget *parent = Q_NULLPTR);
	~InputHexagramDlg();
	QDateTime getInputDateTime() const;
	XXInfo	getInputXXInfo();
	Sex		getInputSex();
public slots:

	void onOK();
	void onCancel();

private:
	Ui::InputHexagramDlg *ui;

	XXSymbol	getXXSymbol(int index);

};
