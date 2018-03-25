#pragma once

#include <list>
#include <map>
#include <string>
#include "rili/lunar.h"

using namespace std;

// ��ʮ����
typedef enum
{
	QianWeiTian,	// ǬΪ��(��)
	TianFengGou,	// ��犥
	TianShanDun,	// ��ɽ��
	TianDiFou,		// ��ط�
	FengDiGuan,		// ��ع�
	ShanDiBo,		// ɽ�ذ�
	HuoDiJin,		// ��ؽ�
	HuoTianDaYou,	// �������

	DuiWeiZe,		// ��Ϊ�󣨽�
	ZeShuiKun,		// ��ˮ��
	ZeDiCui,		// �����
	ZeShanXian,		// ��ɽ��
	ShuiShanJian,	// ˮɽ�
	DiShanQian,		// ��ɽǫ
	LeiShanXiaoGuo,	// ��ɽС��
	LeiZeGuiMei,	// �������

	LiWeiHuo,		// ��Ϊ�𣨻�
	HuoShanLv,		// ��ɽ��
	HuoFengDing,	// ��綦
	HuoShuiWeiJi,	// ��ˮδ��
	ShanShuiMeng,	// ɽˮ��
	FengShuiHuan,	// ��ˮ��
	TianShuiSong,	// ��ˮ��
	TianHuoTongRen,	// ���ͬ��

	ZhenWeiLei,		// ��Ϊ�ף�ľ��
	LeiDiYu,		// �׵�ԥ
	LeiShuiJie,		// ��ˮ��
	LeiFengHeng,	// �׷��
	DiFengSheng,	// �ط���
	ShuiFengJing,	// ˮ�羮
	ZeFengDaGuo,	// �����
	ZeLeiSui,		// ������

	XunWeiFeng,		// ��Ϊ�磨ľ��
	FengTianXiaoChu,// ����С��
	FengHuoJiaRen,	// ������
	FengLeiYi,		// ������
	TianLeiWuWang,	// ��������
	HuoLeiShiKe,	// �������
	ShanLeiYi,		// ɽ����
	ShanFengGu,		// ɽ���

	KanWeiShui,		// ��Ϊˮ��ˮ��
	ShuiZeJie,		// ˮ���
	ShuiLeiTun,		// ˮ����
	ShuiHuoJiJi,	// ˮ��ȼ�
	ZeHuoGe,		// ����
	LeiHuoFeng,		// �׻��
	DiHuoMingYi,	// �ػ�����
	DiShuiShi,		// ��ˮʦ

	GenWeiShan,		// ��Ϊɽ������
	ShanHuoBen,		// ɽ����
	ShanTianDaChu,	// ɽ�����
	ShanZeSun,		// ɽ����
	HuoZeKui,		// �����
	TianZeLv,		// ������
	FengZeZhongFu,	// ��������
	FengShanJian,	// ��ɽ��

	KunWeiDi,		// ��Ϊ�أ�����
	DiLeiFu,		// ���׸�
	DiZeLin,		// ������
	DiTianTai,		// ����̩
	LeiTianDaZhuang,// �����׳
	ZeTianGuai,		// �����
	ShuiTianXu,		// ˮ����
	ShuiDiBi,		// ˮ�ر�
	HEX_Max
}Hexagram;


typedef enum
{
	ShaoYang,	// ����
	ShaoYin,	// ����
	LaoYang,	// ����
	LaoYin		// ����
}XXSymbol;


typedef enum
{
	FirstXX = 0,	// ��س
	SecondXX,	// ��س
	ThirdXX,	// ��س
	FourXX,		// ��س
	FiveXX,		// ��س
	SixXX		// ��س
}XXIndex;

typedef struct
{
	XXSymbol	xxSymbol[6];
}XXInfo;


// ����
typedef enum
{
	WX_Jin,		// ��
	WX_Mu,		// ľ
	WX_Shui,	// ˮ
	WX_Huo,		// ��
	WX_Tu,		// ��
	WX_Max,		// ����������
}WuXing;

// ʮ���
typedef enum
{
	HS_Jia,		// ��
	HS_Yi,		// ��
	HS_Bing,	// ��
	HS_Ding,	// ��
	HS_Wu,		// ��
	HS_Ji,		// ��
	HS_Geng,	// ��
	HS_Xin,		// ��
	HS_Ren,		// ��
	HS_Gui,		// ��
	HS_Max
}HeavenlySteam;

// ʮ����֧
typedef enum
{
	EB_Zi,		// ��
	EB_Chou,	// ��
	EB_Yin,		// ��
	EB_Mao,		// î
	EB_Chen,	// ��
	EB_Si,		// ��
	EB_Wu,		// ��
	EB_Wei,		// δ
	EB_Shen,	// ��
	EB_You,		// ��
	EB_Xu,		// ��
	EB_Hai,		// ��
	EB_Max		
}EarthlyBranch;


// ��ɵ�֧��Ϣ
typedef struct
{
	HeavenlySteam	hsInfo;	// ���
	EarthlyBranch	ebInfo;	// ��֧
}TianGanDiZhi;



// ����
typedef enum
{
	QingLong,	// ����
	ZhuQue,		// ��ȸ
	GouChen,	// ����
	TengShe,	// ����
	BaiHu,		// �׻�
	XuanWu,		// ����
	AnimalMax
}SixAnimal;

typedef struct
{
	SixAnimal animal;
	string	animalStr;
}SixAnimalProperty;


typedef struct
{
	SixAnimal xxAnimalInfo[6];
}SixAnimalInfo;
// ����
typedef enum
{
	FuMu,		// ��ĸ
	XiongDi,	// �ֵ�
	GuanGui,	// �ٹ�
	QiCai,		// �޲�
	ZiSun,		// ����
	RelativeMax
}SixRelative;


// ʮ������
typedef enum
{
	ZhangSheng,		// ����
	MuYu,			// ��ԡ
	GuanDai,		// �ڴ�
	LinGuan,		// �ٹ�
	DiWang,			// ����
	Shuai,			// ˥
	Bing,			// ��
	Si,				// ��
	Mu,				// Ĺ
	Jue,			// ��
	Tai,			// ̥
	Yang			// ��
}TwelveLife;

typedef enum
{
	East,	// ����
	West,	// ����
	South,	// �Ϸ�
	North,	// ����
	Center	// ����
}Direction;


// �������
typedef struct
{
	HeavenlySteam	hsName;		// �������
	string			hsNameStr;
	Direction		direction;	// ����
	WuXing			wxName;		//  ����
	HeavenlySteam	hsHe;		// ���
	SixAnimal		animal;		// ������
}HeavenlySteamProperty;


// ��֧����
typedef struct
{
	EarthlyBranch	ebName;		// ��֧����
	string			ebNameStr;	// ��֧
	WuXing			wxProperty;	// ��������
	EarthlyBranch	ebHe;		// ��֧���
	EarthlyBranch	ebChong;	// ��֧���
	EarthlyBranch	ebXing;		// ����
	EarthlyBranch	ebHai;		// ����
}EarthlyBranchProperty;

// ����
typedef enum
{
	xxYin,
	xxYang
}HexagramSymbol;

// ÿһس����Ϣ
typedef struct
{
	HexagramSymbol	xxSymbol;		// ��ǰس����Ϣ
	SixRelative		xxRelative;		// ��ǰس��������Ϣ
	TianGanDiZhi	tgdz;			// ��ɵ�֧
	bool			isMonthBody;	// �Ƿ���������
	bool			isMonthBodyF;	// �������Ƿ��Ƿ�
	bool			hasF;			// �Ƿ��з�����
	SixRelative		f_xxRelative;	// ����ǰس��������Ϣ
	EarthlyBranch	f_eb;			// ����֧
}XXSymbolInfo;


// ��ʮ��������
typedef struct
{
	Hexagram	  hexagram;		// �Ե�ö��
	unsigned char ucName[255];	// ����
	WuXing		wxName;			// ����
	XXIndex		xxShi;			// ��س
	XXIndex		xxYing;			// Ӧس
	
	XXSymbolInfo	xxSymbolInfo[6];	// ��س��Ϣ
}HexagramProperty;

// ʱ��(������), ����, ����, ��س

typedef struct
{
	int			  year;		// ��
	unsigned char month;	// ��
	unsigned char day;		// ��
	unsigned char hour;		// ʱ
	unsigned char minute;	// ��
	unsigned char second;	// ��
}DataTime;

typedef struct
{

	DataTime	dataTime;		// ʱ��
	bool isRun;					// �Ƿ�����
	TianGanDiZhi	tdYear;		// �����
	TianGanDiZhi	tdMonth;	// �����
	TianGanDiZhi	tdDay;		// �����
}NLDataTime;

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
	DivineInfo(XXInfo* xxInfo, DataTime* dataTime, Sex sex);

	~DivineInfo() {};

	void setDataTime(DataTime& dtTime);
	void setYongGod(SixRelative value);	//  ��������
	void setYongGod(XXIndex	index);		// ��������


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
	unsigned char divinatory_symbol;

	

	XXInfo	m_xxInfo;		// ��س��Ϣ
	
	Hexagram	m_majorHexagram;	// ����
	HexagramProperty	m_majorHexProperty;

	Hexagram	m_subHexagram;		// ����
	HexagramProperty	m_subHexProperty;

	XXIndex		m_xxShi;			// ��س
	XXIndex		m_xxYing;			// Ӧس
	XXIndex		m_xxMonthBody;		// ������
	YongShenInfo	m_ysInfo;		// ����

	std::list<EarthlyBranch> m_ebRiKong;	// Ѯ��
	EarthlyBranch	m_ebYueJian;			// �½�
	EarthlyBranch	m_ebYuePo;				// ����

	DataTime	m_dataTime;		// ռ��ʱ�䣨������
	Day			m_nlDay;		
	NLDataTime	m_nlDataTime;	// ũ����Ϣ
	SixAnimalInfo	m_animalInfo;	// ������Ϣ

	Sex	m_sex;
};


// ʮ�������

// ʮ����֧����
WuXing GetEarthlyBranchWuXing(EarthlyBranch value);

// �����������
WuXing GetWuXingSheng(WuXing value);
WuXing GetWuXingKe(WuXing value);

// �����������
SixRelative GetSixRelativeSheng(SixRelative value);
SixRelative GetSixRelativeKe(SixRelative value);

// ��ɵ�֧���Է�λͼ

// ������
HeavenlySteam GetHeavenlySteamHe(HeavenlySteam value);

// ��֧������
EarthlyBranch GetEarthlyBranchHe(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchChong(EarthlyBranch value);

// ���д���

// ���Դ���

// ��������

// �˹�����

// ��ʮ��������OK��

// �ɼף�OK��

// ����Ӧ��OK��

// ����
SixAnimal GetSixAnimalByHeavenlySteam(HeavenlySteam value);

// ��������OK��

// ���ϻ��

// �����ƾ�

// »�����и�

// ���˸��

// ��������
EarthlyBranch GetEarthlyBranchXing(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchHai(EarthlyBranch value);

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

