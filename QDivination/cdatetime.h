#pragma once

#include "BaGua.h"

typedef struct
{
	int			  year;		// 年
	unsigned char month;	// 月
	unsigned char day;		// 日
	unsigned char hour;		// 时
	unsigned char minute;	// 分
	unsigned char second;	// 秒
}DateTime;

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
	CDateTime(TDDateTime* tdTime);

	void setDateTime(DateTime* dateTime);
	DateTime GetDateTime();

	~CDateTime();

	TDDateTime GetTDDate();

private:


	TDDateTime	m_tdDateTime;	// 天干地支

	// 农历 lunar calendar
	bool isLeapMonth;	// 是否闰月（农历）
	int m_lunarYear;
	unsigned char m_ucLunarMonth;
	unsigned char m_ucLunarDay;

	// 公历gregorian calendar
	DateTime m_greDateTime;
};

