#include "InputHexagramDlg.h"
#include "ui_InputHexagramDlg.h"

InputHexagramDlg::InputHexagramDlg(QWidget *parent)
	: QDialog(parent)
{
	ui = new Ui::InputHexagramDlg();
	ui->setupUi(this);
	connect(ui->btnOk, SIGNAL(clicked()), this, SLOT(onOK()));
	connect(ui->btnCancel, SIGNAL(clicked()), this, SLOT(onCancel()));

	// 获取当前时间
	QDateTime dtTime = QDateTime::currentDateTime();
	ui->dateTimeEdit->setDateTime(dtTime);
	

}

InputHexagramDlg::~InputHexagramDlg()
{
	delete ui;
}

QDateTime InputHexagramDlg::getInputDateTime() const
{
	return ui->dateTimeEdit->dateTime();
}

XXInfo InputHexagramDlg::getInputXXInfo()
{
	XXInfo info;
	info.xxSymbol[0] = getXXSymbol(ui->cb_1->currentIndex());
	info.xxSymbol[1] = getXXSymbol(ui->cb_2->currentIndex());
	info.xxSymbol[2] = getXXSymbol(ui->cb_3->currentIndex());
	info.xxSymbol[3] = getXXSymbol(ui->cb_4->currentIndex());
	info.xxSymbol[4] = getXXSymbol(ui->cb_5->currentIndex());
	info.xxSymbol[5] = getXXSymbol(ui->cb_6->currentIndex());
	return info;
}

Sex InputHexagramDlg::getInputSex()
{
	int index = ui->cbSex->currentIndex();
	if (index == 0)
	{
		return Man;
	}
	else if (index == 1)
	{
		return Woman;
	}
	else
	{
		return Man;
	}
}

void InputHexagramDlg::onOK()
{
	this->accept();
}

void InputHexagramDlg::onCancel()
{
	this->reject();
}

XXSymbol InputHexagramDlg::getXXSymbol(int index)
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
