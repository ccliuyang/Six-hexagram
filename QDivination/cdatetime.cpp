#include "cdatetime.h"
#include "rili/lunar.h"



CDateTime::CDateTime()
{
}

CDateTime::CDateTime(TDDateTime * tdTime)
{
	m_tdDateTime = *tdTime;
}

void CDateTime::setDateTime(DateTime * dateTime)
{
	m_greDateTime = *dateTime;
	Lunar lunar;
	Month month = lunar.yueLiCalc(m_greDateTime.year, m_greDateTime.month);
	std::vector<Day> & days = month.days;
	for (auto it = days.begin(); it != days.end(); ++it)
	{
		Day& day = (*it);
		if (day.d != m_greDateTime.day)
		{
			continue;
		}
		else
		{
			m_lunarYear = day.Lyear + 1984;
			if (day.Lmc == 0 || day.Lmc == 1)
			{
				m_ucLunarMonth = 11 + day.Lmc;
			}
			else
			{
				m_ucLunarMonth = day.Lmc - 1;
			}
			m_ucLunarDay = (day.Ldi + 1);
			isLeapMonth = day.Lleap;
			m_tdDateTime.tdYear.hsInfo = GetHeavenlySteam(day.Lyear2.tg);
			m_tdDateTime.tdYear.ebInfo = GetEarthlyBranch(day.Lyear2.dz);
			m_tdDateTime.tdMonth.hsInfo = GetHeavenlySteam(day.Lmonth2.tg);
			m_tdDateTime.tdMonth.ebInfo = GetEarthlyBranch(day.Lmonth2.dz);
			m_tdDateTime.tdDay.hsInfo = GetHeavenlySteam(day.Lday2.tg);
			m_tdDateTime.tdDay.ebInfo = GetEarthlyBranch(day.Lday2.dz);
			if (day.qk == -1)
			{
				// 如果当天不是节气
			}
			else
			{
				// 当天是节气，判断当前时间在节气前还是后,在前为前一天天干地支，在后为后一天天干地支
				std::string jqTime = day.jqsj;
				int hour = atoi(jqTime.substr(0, 2).c_str());
				int minute = atoi(jqTime.substr(3, 2).c_str());
				int second = atoi(jqTime.substr(6, 2).c_str());
				if ((hour > m_greDateTime.hour) || (hour == m_greDateTime.hour && minute > m_greDateTime.minute) || (hour == m_greDateTime.hour && minute == m_greDateTime.minute && second > m_greDateTime.second))
				{
					// 当前时间未到节气时间
					int yTg = (day.Lyear2.tg - 1) < 0 ? 9 : day.Lyear2.tg - 1;
					int yDz = (day.Lyear2.dz - 1) < 0 ? 11 : day.Lyear2.dz - 1;
					int mTg = (day.Lmonth2.tg - 1) < 0 ? 9 : day.Lmonth2.tg - 1;
					int mDz = (day.Lmonth2.dz - 1) < 0 ? 11 : day.Lmonth2.dz - 1;

					m_tdDateTime.tdYear.hsInfo = GetHeavenlySteam(yTg);
					m_tdDateTime.tdYear.ebInfo = GetEarthlyBranch(yDz);
					m_tdDateTime.tdMonth.hsInfo = GetHeavenlySteam(mTg);
					m_tdDateTime.tdMonth.ebInfo = GetEarthlyBranch(mDz);
				}
				else
				{

				}
			}
			return;
		}

	}
}

DateTime CDateTime::GetDateTime()
{
	return m_greDateTime;
}


CDateTime::~CDateTime()
{
}

TDDateTime CDateTime::GetTDDate()
{
	return m_tdDateTime;
}
