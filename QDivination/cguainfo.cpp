#include "cguainfo.h"

CGuaInfo::CGuaInfo(XXInfo * xxInfo, DateTime * dtTime)
{
	for(int i = 0; i < 6; i++)
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	setDateTime(dtTime);
}

CGuaInfo::CGuaInfo(XXInfo * xxInfo, NLDateTime * dtTime)
{
	for (int i = 0; i < 6; i++)
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	setDateTime(dtTime);
}

CGuaInfo::CGuaInfo(XXInfo * xxInfo, TDDateTime * dtTime)
{
	for (int i = 0; i < 6; i++)
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	setDateTime(dtTime);
}

CGuaInfo::~CGuaInfo()
{
}

bool CGuaInfo::hasSubHex()
{
	for (int i = 0; i < 6; i++)
	{
		if (m_xxInfo.xxSymbol[i] == LaoYang || m_xxInfo.xxSymbol[i] == LaoYin)
			return true;
	}
	return false;
}

void CGuaInfo::setDateTime(DateTime * dtTime)
{
	Lunar lunar;
	Month month = lunar.yueLiCalc(dtTime->year, dtTime->month);
	std::vector<Day>& days = month.days;
	for (auto it = days.begin(); it != days.end(); ++it)
	{
		Day& day = (*it);
		if (day.d != dtTime->day)
			continue;
		else
		{

		}
	}
}

void CGuaInfo::setDateTime(NLDateTime * dtTime)
{
}

void CGuaInfo::setDateTime(TDDateTime * dtTime)
{
}

