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
	HexagramProperty m_majorHex;	// ����
	HexagramProperty m_subHex;		// ����
	XXInfo			 m_xxInfo;		// ��س��Ϣ
	CDateTime		 *m_tdTime;		// ��ɵ�֧����
	SixAnimalInfo	m_animalInfo;	// ������Ϣ
	EarthlyBranch m_k1;	// �տ�
	EarthlyBranch m_k2; // �տ�


};
