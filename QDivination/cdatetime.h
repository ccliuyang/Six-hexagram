#pragma once

#include "calendar.h"

typedef struct
{
	int			  year;		// 年
	unsigned char month;	// 月
	unsigned char day;		// 日
}GreDate;

class CDateTime
{
public:
	CDateTime();
	~CDateTime();

private:
	unsigned char hour;		// 时
	unsigned char minute;	// 分
	unsigned char second;	// 秒

	TianGanDiZhi	tdYear;		// 年天干
	TianGanDiZhi	tdMonth;	// 月天干
	TianGanDiZhi	tdDay;		// 日天干

	bool isLeapMonth;	// 是否闰月（农历）

};

