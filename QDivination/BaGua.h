#pragma once

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

typedef enum
{
	FirstXX = 0,	// ��س
	SecondXX,	// ��س
	ThirdXX,	// ��س
	FourXX,		// ��س
	FiveXX,		// ��س
	SixXX		// ��س
}XXIndex;

// ����
typedef enum
{
	xxYin,
	xxYang
}HexagramSymbol;

typedef enum
{
	ShaoYang,	// ����
	ShaoYin,	// ����
	LaoYang,	// ����
	LaoYin		// ����
}XXSymbol;

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

// ��λ��Ϣ
typedef enum
{
	East,	// ����
	West,	// ����
	South,	// �Ϸ�
	North,	// ����
	Center	// ����
}Direction;

typedef struct
{
	SixAnimal animal;
	char 	animalStr[255];
}SixAnimalProperty;


typedef struct
{
	SixAnimal xxAnimalInfo[6];
}SixAnimalInfo;

// ÿһس����Ϣ
typedef struct
{
	HexagramSymbol	xxSymbol;		// ��ǰس����Ϣ
	SixRelative		xxRelative;		// ��ǰس��������Ϣ
	TianGanDiZhi	tgdz;			// ��ɵ�֧
	bool			isMonthBody;	// �Ƿ���������
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




// �����������
extern WuXing GetWuXingSheng(WuXing value);
extern WuXing GetWuXingKe(WuXing value);

// �����������
SixRelative GetSixRelativeSheng(SixRelative value);
SixRelative GetSixRelativeKe(SixRelative value);

// ��֧������
EarthlyBranch GetEarthlyBranchHe(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchChong(EarthlyBranch value);

// ʮ����֧����
WuXing GetEarthlyBranchWuXing(EarthlyBranch value);

// ����
SixAnimal GetSixAnimalByHeavenlySteam(HeavenlySteam value);

HeavenlySteam GetHeavenlySteam(unsigned char index);
EarthlyBranch GetEarthlyBranch(unsigned char index);

// ����Ѯ��
void GetXunKong(TianGanDiZhi tdDay, EarthlyBranch* k1, EarthlyBranch* k2);

// ��������
EarthlyBranch GetEarthlyBranchXing(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchHai(EarthlyBranch value);

// ������
HeavenlySteam GetHeavenlySteamHe(HeavenlySteam value);

// �����½�
EarthlyBranch GetYueJian(TianGanDiZhi tdMonth);

// ��������
SixAnimalInfo GetSixAnimalInfo(TianGanDiZhi tdDay);

// ������Ա���
void GetHexagramProperty(XXInfo *pxxInfo, HexagramProperty* majorHex, HexagramProperty* subHex);

