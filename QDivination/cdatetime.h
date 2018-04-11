#pragma once

#include "BaGua.h"

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
	~CDateTime();

//	void GetTDDate(TianGanDiZhi* year, TianGanDiZhi* month, TianGanDiZhi* day);
	//void GetGreDate()

private:
	unsigned char hour;		// ʱ
	unsigned char minute;	// ��
	unsigned char second;	// ��

	TDDateTime	m_tdDateTime;	// ��ɵ�֧

	// ũ�� lunar calendar
	bool isLeapMonth;	// �Ƿ����£�ũ����
	int lunarYear;
	unsigned char ucLunarMonth;
	unsigned char ucLunarDay;

	// ����gregorian calendar
	int			  year;		// ��
	unsigned char month;	// ��
	unsigned char day;		// ��

};

