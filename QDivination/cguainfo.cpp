#include "cguainfo.h"
#include "BaGua.h"

CGuaInfo::CGuaInfo(XXInfo * xxInfo, CDateTime * dtTime) : m_tdTime(dtTime)
{
	for (int i = 0; i < 6; i++)
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	GetHexagramProperty(&m_xxInfo, &m_majorHex, &m_subHex);
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

