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
	HexagramProperty m_majorHex;	// ����
	HexagramProperty m_subHex;		// ����
	XXInfo			 m_xxInfo;		// ��س��Ϣ
	TDDateTime		 m_tdTime;		// ��ɵ�֧����

};
