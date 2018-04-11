#pragma once

#include "BaGua.h"

typedef struct
{
	int			  year;		// ��
	unsigned char month;	// ��
	unsigned char day;		// ��
	unsigned char hour;		// ʱ
	unsigned char minute;	// ��
	unsigned char second;	// ��
}DateTime;

typedef struct
{
	TianGanDiZhi	tdYear;		// �����
	TianGanDiZhi	tdMonth;	// �����
	TianGanDiZhi	tdDay;		// �����
}TDDateTime;

class CDateTime
{
public:
	CDateTime();
	CDateTime(TDDateTime* tdTime);

	void setDateTime(DateTime* dateTime);
	DateTime GetDateTime();

	~CDateTime();

	TDDateTime GetTDDate();

private:


	TDDateTime	m_tdDateTime;	// ��ɵ�֧

	// ũ�� lunar calendar
	bool isLeapMonth;	// �Ƿ����£�ũ����
	int m_lunarYear;
	unsigned char m_ucLunarMonth;
	unsigned char m_ucLunarDay;

	// ����gregorian calendar
	DateTime m_greDateTime;
};

