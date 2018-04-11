#include "cguainfo.h"
#include "BaGua.h"



CGuaInfo::CGuaInfo(XXInfo * xxInfo, CDateTime * dtTime) : m_tdTime(dtTime)
{
	for (int i = 0; i < 6; i++)
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	GetHexagramProperty(&m_xxInfo, &m_majorHex, &m_subHex);
	m_animalInfo = GetSixAnimalInfo(m_tdTime->GetTDDate().tdDay);
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

std::string CGuaInfo::getGuaInfo()
{
	std::string str;
	char tmp[200] = { 0x00 };
	memset(tmp, 0, sizeof(tmp));
	
	str.append("����");
	sprintf(tmp, "%d��%02d��%02d�� %02d:%02d:%02d\n", m_tdTime->GetDateTime().year,
		m_tdTime->GetDateTime().month, m_tdTime->GetDateTime().day,
		m_tdTime->GetDateTime().hour, m_tdTime->GetDateTime().minute,
		m_tdTime->GetDateTime().second);
	str.append(tmp);
	memset(tmp, 0, sizeof(tmp));

	sprintf(tmp, "���գ�%s%s�� %s%s�� %s%s��\n", GetHeavenlyName(m_tdTime->GetTDDate().tdYear.hsInfo).c_str(),
		GetEarthlyName(m_tdTime->GetTDDate().tdYear.ebInfo).c_str(),
		GetHeavenlyName(m_tdTime->GetTDDate().tdMonth.hsInfo).c_str(),
		GetEarthlyName(m_tdTime->GetTDDate().tdMonth.ebInfo).c_str(),
		GetHeavenlyName(m_tdTime->GetTDDate().tdDay.hsInfo).c_str(),
		GetEarthlyName(m_tdTime->GetTDDate().tdDay.ebInfo).c_str());

	str.append(tmp);




	str.append("         ");
	memset(tmp, 0, sizeof(tmp));
	sprintf(tmp, "%s:%s", getGuaGong(m_majorHex.hexagram).c_str(), m_majorHex.ucName);
	str.append(tmp);		
	if (hasSubHex())
	{
		str.append("                 ");
		memset(tmp, 0, sizeof(tmp));
		sprintf(tmp, "%s:%s", getGuaGong(m_subHex.hexagram).c_str(), m_subHex.ucName);
		str.append(tmp);
	}
	str.append("\n");

	for (int i = 5; i >= 0; i--)
	{
		memset(tmp, 0, sizeof(tmp));
		// ��س ����  ���� ��֧���� ���� ��Ӧ
		sprintf(tmp, "%s   %s %s%s", GetAnimalName(m_animalInfo.xxAnimalInfo[i]).c_str(),
			GetSixRelativeName(m_majorHex.xxSymbolInfo[i].xxRelative).c_str(),
			GetEarthlyName(m_majorHex.xxSymbolInfo[i].tgdz.ebInfo).c_str(),
			GetWuXingName(GetEarthlyBranchWuXing(m_majorHex.xxSymbolInfo[i].tgdz.ebInfo)).c_str());
		str.append(tmp);
		if(m_majorHex.xxSymbolInfo[i].xxSymbol == xxYang)
			str.append("�|�|�|�|�|");
		else
			str.append("�|�|  �|�|");
		

		std::string strTmp;

		if ((int)(m_majorHex.xxShi) == i)
			strTmp.append("��");
		else if ((int)(m_majorHex.xxYing) == i)
			strTmp.append("Ӧ");

		if (m_xxInfo.xxSymbol[i] == LaoYang)
			strTmp.append("��");
		else if (m_xxInfo.xxSymbol[i] == LaoYin)
			strTmp.append("��-��");

		memset(tmp, 0, sizeof(tmp));
		sprintf(tmp, "%-8s", strTmp.c_str());
		str.append(tmp);

		if (hasSubHex())
		{
			//str.append("      ");
			if (m_subHex.xxSymbolInfo[i].xxSymbol == xxYang)
				str.append("�|�|�|�|�|");
			else
				str.append("�|�|  �|�|");
			memset(tmp, 0, sizeof(tmp));
			sprintf(tmp, " %s %s%s", GetSixRelativeName(m_subHex.xxSymbolInfo[i].xxRelative).c_str(),
				GetEarthlyName(m_subHex.xxSymbolInfo[i].tgdz.ebInfo).c_str(),
				GetWuXingName(GetEarthlyBranchWuXing(m_subHex.xxSymbolInfo[i].tgdz.ebInfo)).c_str());
			str.append(tmp);
		}
		str.append("\n");
		if (m_majorHex.xxSymbolInfo[i].hasF)
		{
			memset(tmp, 0, sizeof(tmp));
			sprintf(tmp, "��:    %s %s%s\n", GetSixRelativeName(m_majorHex.xxSymbolInfo[i].f_xxRelative).c_str(),
				GetEarthlyName(m_majorHex.xxSymbolInfo[i].f_eb).c_str(),
				GetWuXingName(GetEarthlyBranchWuXing(m_majorHex.xxSymbolInfo[i].f_eb)).c_str());
			str.append(tmp);
		}
		else
			str.append("\n");
	}
	return str;
}

static std::string guaGong[] = {
	"Ǭ", "��", "��", "��", "��", "��", "��","��"
};
std::string CGuaInfo::getGuaGong(Hexagram value)
{
	int x = (int)(value) % 8;
	return guaGong[x];
}


