#pragma once

#include "cdatetime.h"
#include <string>


class CDateTime;

class CGuaInfo
{
public:
	CGuaInfo(XXInfo* xxInfo, CDateTime* dtTime);
	~CGuaInfo();
	bool hasSubHex();
	std::string getGuaInfo();

private:
	std::string getGuaGong(Hexagram value);


private:
	HexagramProperty m_majorHex;	// 主卦
	HexagramProperty m_subHex;		// 变卦
	XXInfo			 m_xxInfo;		// 卦爻信息
	CDateTime		 *m_tdTime;		// 天干地支日期
	SixAnimalInfo	m_animalInfo;	// 六兽信息
	EarthlyBranch m_k1;	// 日空
	EarthlyBranch m_k2; // 日空


};
