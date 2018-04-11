#pragma once

#include "BaGua.h"

typedef struct
{
	TianGanDiZhi	tdYear;		// 年天干
	TianGanDiZhi	tdMonth;	// 月天干
	TianGanDiZhi	tdDay;		// 日天干
}TDDateTime;

class CDateTime
{
public:
	CDateTime();
	~CDateTime();

//	void GetTDDate(TianGanDiZhi* year, TianGanDiZhi* month, TianGanDiZhi* day);
	//void GetGreDate()

private:
	unsigned char hour;		// 时
	unsigned char minute;	// 分
	unsigned char second;	// 秒

	TDDateTime	m_tdDateTime;	// 天干地支

	// 农历 lunar calendar
	bool isLeapMonth;	// 是否闰月（农历）
	int lunarYear;
	unsigned char ucLunarMonth;
	unsigned char ucLunarDay;

	// 公历gregorian calendar
	int			  year;		// 年
	unsigned char month;	// 月
	unsigned char day;		// 日

};

