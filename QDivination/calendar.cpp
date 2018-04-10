#include "calendar.h"
#include <vector>
#include <iostream>

//static HeavenlySteam hsInfo[] = { HS_Jia , HS_Yi , HS_Bing , HS_Ding , HS_Wu , HS_Ji , HS_Geng , HS_Xin , HS_Ren , HS_Gui };





DivineInfo::DivineInfo(XXInfo * xxInfo, DateTime* dataTime, Sex sex)
{

	for (int i = 0; i < 6; i++)
	{
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	}
	CalcHexagram();	// 计算主卦、副卦
	CalcShiYing();	// 计算世应
	setDateTime(*dataTime);
	CalcYueJian();	// 月建
	CalcYuePo();	// 月破
	CalcXunKong();	// 旬空
	CalcAnimal();	// 计算六兽
	m_sex = sex;
}

void DivineInfo::setDateTime(DateTime & dtTime)
{
	m_dateTime = dtTime;
	Lunar lunar;
	Month month = lunar.yueLiCalc(m_dateTime.year, m_dateTime.month);
	std::vector<Day> & days = month.days;
	for (auto it = days.begin(); it != days.end(); ++it)
	{
		Day& day = (*it);
		if (day.d != m_dateTime.day)
		{
			continue;
		}
		else
		{
			m_nlDay = day;
			m_nlDateTime.dataTime.year = m_nlDay.Lyear;
			if (m_nlDay.Lmc == 0 || m_nlDay.Lmc == 1)
			{
				m_nlDateTime.dataTime.month = 11 + m_nlDay.Lmc;
			}
			else
			{
				m_nlDateTime.dataTime.month = m_nlDay.Lmc - 1;
			}
			m_nlDateTime.dataTime.day = (m_nlDay.Ldi + 1);
			m_nlDateTime.dataTime.hour = dtTime.hour;
			m_nlDateTime.dataTime.minute = dtTime.minute;
			m_nlDateTime.dataTime.second = dtTime.second;
			m_nlDateTime.isRun = day.Lleap;
			m_nlDateTime.tdYear.hsInfo = GetHeavenlySteam(day.Lyear2.tg);
			m_nlDateTime.tdYear.ebInfo = GetEarthlyBranch(day.Lyear2.dz);
			m_nlDateTime.tdMonth.hsInfo = GetHeavenlySteam(day.Lmonth2.tg);
			m_nlDateTime.tdMonth.ebInfo = GetEarthlyBranch(day.Lmonth2.dz);
			m_nlDateTime.tdDay.hsInfo = GetHeavenlySteam(day.Lday2.tg);
			m_nlDateTime.tdDay.ebInfo = GetEarthlyBranch(day.Lday2.dz);
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
				if ((hour > dtTime.hour) || (hour == dtTime.hour && minute > dtTime.minute) || (hour == dtTime.hour && minute == dtTime.minute && second > dtTime.second))
				{
					// 当前时间未到节气时间
					int yTg = (day.Lyear2.tg - 1) < 0 ? 9 : day.Lyear2.tg - 1;
					int yDz = (day.Lyear2.dz - 1) < 0 ? 11 : day.Lyear2.dz - 1;
					int mTg = (day.Lmonth2.tg - 1) < 0 ? 9 : day.Lmonth2.tg - 1;
					int mDz = (day.Lmonth2.dz - 1) < 0 ? 11 : day.Lmonth2.dz - 1;

					m_nlDateTime.tdYear.hsInfo = GetHeavenlySteam(yTg);
					m_nlDateTime.tdYear.ebInfo = GetEarthlyBranch(yDz);
					m_nlDateTime.tdMonth.hsInfo = GetHeavenlySteam(mTg);
					m_nlDateTime.tdMonth.ebInfo = GetEarthlyBranch(mDz);
				}
				else
				{

				}
			}
			return;
		}

	}
	
}

// 设置用神
void DivineInfo::setYongGod(SixRelative value)
{
	int count = 0;

	for (int i = 0; i < 6; i++)
	{
		if (m_majorHexProperty.xxSymbolInfo[i].xxRelative == value)
			count++;
	}
	if (count == 0)
	{
		// 没找到所须六亲,找伏六亲
		for (int i = 0; i < 6; i++)
		{
			if (m_majorHexProperty.xxSymbolInfo[i].hasF == true)
			{
				if (m_majorHexProperty.xxSymbolInfo[i].f_xxRelative == value)
				{
					m_ysInfo.isFu = true;
					m_ysInfo.ebInfo = m_majorHexProperty.xxSymbolInfo[i].f_eb;
					m_ysInfo.relativeInfo = value;
					m_ysInfo.xxIndex = (XXIndex)i;
				}
			}
		}
	}
	else if (count == 1)
	{
		// 找到一个
		m_ysInfo.isFu = false;
		for (int i = 0; i < 6; i++)
		{
			if (m_majorHexProperty.xxSymbolInfo[i].xxRelative == value)
			{
				m_ysInfo.ebInfo = m_majorHexProperty.xxSymbolInfo[i].tgdz.ebInfo;
				m_ysInfo.relativeInfo = value;
				m_ysInfo.xxIndex = (XXIndex)i;
			}
		}	
	}
	else
	{
		// 舍其闲爻而用持世，舍其无权而用月日，舍其不破而用月破，舍用不空而用旬空，天机尽泄
		// 于有病之间，断法总在医药之处
		std::cout << "暂未实现" << std::endl;
	}
	
}

void DivineInfo::setYongGod(XXIndex index)
{
	// 指定第几爻为用神
	m_ysInfo.xxIndex = (XXIndex)index;
	m_ysInfo.ebInfo = m_majorHexProperty.xxSymbolInfo[(int)index].tgdz.ebInfo;
	m_ysInfo.relativeInfo = m_majorHexProperty.xxSymbolInfo[(int)index].xxRelative;

}

void DivineInfo::drawDivineInfo(DivineInfo * pInfo)
{
	// 判断是否有动爻
	
}


void DivineInfo::GetYongGod()
{
}

void DivineInfo::GetYuanGod()
{
}

void DivineInfo::GetJiGod()
{
}

void DivineInfo::GetChouGod()
{
}


void DivineInfo::CalcHexagram()
{
	GetHexagramProperty(&m_xxInfo, &m_majorHexProperty, &m_subHexProperty);
}

void DivineInfo::CalcYueJian()
{
	m_ebYueJian = GetYueJian(m_nlDateTime.tdMonth);
}

void DivineInfo::CalcYuePo()
{
	m_ebYuePo = GetEarthlyBranchChong(m_nlDateTime.tdMonth.ebInfo);
}

void DivineInfo::CalcXunKong()
{
	EarthlyBranch k1, k2;

	GetXunKong(m_nlDateTime.tdDay, &k1, &k2);
	m_ebRiKong.push_back(k1);
	m_ebRiKong.push_back(k2);
}

void DivineInfo::CalcAnimal()
{
	m_animalInfo = GetSixAnimalInfo(m_nlDateTime.tdDay);
}

void DivineInfo::CalcShiYing()
{
	m_xxShi = m_majorHexProperty.xxShi;
	m_xxYing = m_majorHexProperty.xxYing;
}

void DivineInfo::CalcYuanShen()
{

}

bool DivineInfo::isWang(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (xxWuxing == yueWuxing)
		return true;
	return false;
}

bool DivineInfo::isXiang(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (GetWuXingSheng(yueWuxing) == xxWuxing)
		return true;
	return false;
}

bool DivineInfo::isXiu(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (GetWuXingKe(yueWuxing) == xxWuxing)
		return true;
	return false;
}

bool DivineInfo::isQiu(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (GetWuXingKe(GetWuXingSheng(yueWuxing)) == xxWuxing)
		return true;
	return false;
}

