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
	HexagramProperty m_majorHex;	// ����
	HexagramProperty m_subHex;		// ����
	XXInfo			 m_xxInfo;		// ��س��Ϣ
	CDateTime		 *m_tdTime;		// ��ɵ�֧����

};
