#pragma once

#include "calendar.h"

class CGuaInfo
{
public:
	CGuaInfo(XXInfo* xxInfo, DateTime* dtTime);
	CGuaInfo(XXInfo* xxInfo, NLDateTime* dtTime);
	CGuaInfo(XXInfo* xxInfo, TDDateTime* dtTime);


	~CGuaInfo();
	bool hasSubHex();

private:
	void setDateTime(DateTime* dtTime);
	void setDateTime(NLDateTime* dtTime);
	void setDateTime(TDDateTime* dtTime);

private:
	HexagramProperty m_majorHex;	// 主卦
	HexagramProperty m_subHex;		// 变卦
	XXInfo			 m_xxInfo;		// 卦爻信息
	TDDateTime		 m_tdTime;		// 天干地支日期

};
