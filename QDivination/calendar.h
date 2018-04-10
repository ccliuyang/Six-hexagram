#pragma once

#include "BaGua.h"


#include <list>
#include <map>
#include <string>
#include "rili/lunar.h"

using namespace std;

// ʱ��(������), ����, ����, ��س

typedef struct
{
	int			  year;		// ��
	unsigned char month;	// ��
	unsigned char day;		// ��
	unsigned char hour;		// ʱ
	unsigned char minute;	// ��
	unsigned char second;	// ��
}DateTime;

typedef struct
{

	DateTime	dataTime;		// ʱ��
	bool isRun;					// �Ƿ�����
	TianGanDiZhi	tdYear;		// �����
	TianGanDiZhi	tdMonth;	// �����
	TianGanDiZhi	tdDay;		// �����
}NLDateTime;

typedef struct
{
	TianGanDiZhi	tdYear;		// �����
	TianGanDiZhi	tdMonth;	// �����
	TianGanDiZhi	tdDay;		// �����
}TDDateTime;

// �Ա�
typedef enum
{
	Man,
	Woman
}Sex;

// ������Ϣ
typedef struct
{
	SixRelative	relativeInfo;	// ������Ϣ
	bool		isFu;		// �Ƿ����
	XXIndex		xxIndex;	// ���ڵڼ�س
	EarthlyBranch	ebInfo;	// ��֧��Ϣ
}YongShenInfo;

// ռ����Ϣ
class DivineInfo
{
public:
	DivineInfo(XXInfo* xxInfo, DateTime* dataTime, Sex sex = Man);

	~DivineInfo() {};

	void setDateTime(DateTime& dtTime);
	void setYongGod(SixRelative value);	//  ��������
	void setYongGod(XXIndex	index);		// ��������

	void drawDivineInfo(DivineInfo* pInfo);


private:
	void GetYongGod();	// ��ȡ����
	void GetYuanGod();	// ��ȡԭ��
	void GetJiGod();	// ��ȡ����
	void GetChouGod();	// ��ȡ����

	void CalcHexagram();	// ���㵱ǰ���ĸ���
	void CalcYueJian();	// �����½�
	void CalcYuePo();	// ��������
	void CalcXunKong();	// ����Ѯ��
	void CalcAnimal();	// ������
	void CalcShiYing();	// ����Ӧ
	void CalcYuanShen();	// ����ԭ��

	bool isWang(XXSymbolInfo* info);	// ��
	bool isXiang(XXSymbolInfo* info);	// ��
	bool isXiu(XXSymbolInfo* info);	// ��
	bool isQiu(XXSymbolInfo* info);	// ��


private:
	XXInfo	m_xxInfo;		// ��س��Ϣ
	HexagramProperty	m_majorHexProperty;	// ����	
	HexagramProperty	m_subHexProperty;	// ����

	XXIndex		m_xxShi;			// ��س
	XXIndex		m_xxYing;			// Ӧس
	XXIndex		m_xxMonthBody;		// ������
	YongShenInfo	m_ysInfo;		// ����

	std::list<EarthlyBranch> m_ebRiKong;	// Ѯ��
	EarthlyBranch	m_ebYueJian;			// �½�
	EarthlyBranch	m_ebYuePo;				// ����

	DateTime	m_dateTime;		// ռ��ʱ�䣨������
	Day			m_nlDay;		
	NLDateTime	m_nlDateTime;	// ũ����Ϣ
	SixAnimalInfo	m_animalInfo;	// ������Ϣ

	Sex	m_sex;
};


// ʮ�������



// ��ɵ�֧���Է�λͼ





// ���д���

// ���Դ���

// ��������

// �˹�����

// ��ʮ��������OK��

// �ɼף�OK��

// ����Ӧ��OK��



// ��������OK��

// ���ϻ��

// �����ƾ�

// »�����и�

// ���˸��



// �˹�����

// �˹�����

// ����س

// �������£�ok��

// ������ʱ��ok��

// ͨ����

// ���

// ��س������

// ��Ӧ���˿���������

// ����ϲ�ɾ�

// �ɷ����˼��׸�

// ����������ɷ

// ��س������

// ��س�Ҷ���

// �����

// ԭ���

// �������Ծ�

// ���������

// ���񷢶���

// �ճ���

// ���׷�����

// ���ױ仯��

// ���޸��

// ���½�����

// ��������

// ����Ѯ��������ok��

// ���ƶ�����ok��

// ������ඨ��

// ��Ӧ������

// �����ʴ�

// ԭ�ɳ�����

// ��������

// ��������

// ��������

// ������λ��

// ������

// Ѯ����

// �����Զ���

// �����Զ���

// ����������

// ���д�����

// �ϴ���壬���з��

// �����������˴�����

// �����������

// ���в���

