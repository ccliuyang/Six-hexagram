#pragma once

#include "cdatetime.h"


class CDateTime;

class CGuaInfo
{
public:
	CGuaInfo(XXInfo* xxInfo, CDateTime* dtTime);
	~CGuaInfo();
	bool hasSubHex();

private:
	

private:
	HexagramProperty m_majorHex;	// 主卦
	HexagramProperty m_subHex;		// 变卦
	XXInfo			 m_xxInfo;		// 卦爻信息
	CDateTime		 *m_tdTime;		// 天干地支日期

};
