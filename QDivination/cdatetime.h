#pragma once

#include "calendar.h"

typedef struct
{
	int			  year;		// ��
	unsigned char month;	// ��
	unsigned char day;		// ��
}GreDate;

class CDateTime
{
public:
	CDateTime();
	~CDateTime();

private:
	unsigned char hour;		// ʱ
	unsigned char minute;	// ��
	unsigned char second;	// ��

	TianGanDiZhi	tdYear;		// �����
	TianGanDiZhi	tdMonth;	// �����
	TianGanDiZhi	tdDay;		// �����

	bool isLeapMonth;	// �Ƿ����£�ũ����

};

