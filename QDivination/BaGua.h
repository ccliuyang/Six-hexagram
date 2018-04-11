#pragma once

// 六十四卦
typedef enum
{
	QianWeiTian,	// 乾为天(金)
	TianFengGou,	// 天风姤
	TianShanDun,	// 天山遁
	TianDiFou,		// 天地否
	FengDiGuan,		// 风地关
	ShanDiBo,		// 山地剥
	HuoDiJin,		// 火地晋
	HuoTianDaYou,	// 火天大有

	DuiWeiZe,		// 兑为泽（金）
	ZeShuiKun,		// 泽水困
	ZeDiCui,		// 泽地萃
	ZeShanXian,		// 泽山咸
	ShuiShanJian,	// 水山蹇
	DiShanQian,		// 地山谦
	LeiShanXiaoGuo,	// 雷山小过
	LeiZeGuiMei,	// 雷泽归妹

	LiWeiHuo,		// 离为火（火）
	HuoShanLv,		// 火山旅
	HuoFengDing,	// 火风鼎
	HuoShuiWeiJi,	// 火水未济
	ShanShuiMeng,	// 山水蒙
	FengShuiHuan,	// 风水涣
	TianShuiSong,	// 天水讼
	TianHuoTongRen,	// 天火同人

	ZhenWeiLei,		// 震为雷（木）
	LeiDiYu,		// 雷地豫
	LeiShuiJie,		// 雷水解
	LeiFengHeng,	// 雷风恒
	DiFengSheng,	// 地风升
	ShuiFengJing,	// 水风井
	ZeFengDaGuo,	// 泽风大过
	ZeLeiSui,		// 泽雷随

	XunWeiFeng,		// 巽为风（木）
	FengTianXiaoChu,// 风天小畜
	FengHuoJiaRen,	// 风火家人
	FengLeiYi,		// 风雷益
	TianLeiWuWang,	// 天雷无妄
	HuoLeiShiKe,	// 火雷噬嗑
	ShanLeiYi,		// 山雷颐
	ShanFengGu,		// 山风蛊

	KanWeiShui,		// 坎为水（水）
	ShuiZeJie,		// 水泽节
	ShuiLeiTun,		// 水雷屯
	ShuiHuoJiJi,	// 水火既济
	ZeHuoGe,		// 泽火革
	LeiHuoFeng,		// 雷火丰
	DiHuoMingYi,	// 地火明夷
	DiShuiShi,		// 地水师

	GenWeiShan,		// 艮为山（土）
	ShanHuoBen,		// 山火贲
	ShanTianDaChu,	// 山天大畜
	ShanZeSun,		// 山泽损
	HuoZeKui,		// 火泽睽
	TianZeLv,		// 天泽履
	FengZeZhongFu,	// 风泽中孚
	FengShanJian,	// 风山渐

	KunWeiDi,		// 坤为地（土）
	DiLeiFu,		// 地雷复
	DiZeLin,		// 地泽临
	DiTianTai,		// 地天泰
	LeiTianDaZhuang,// 雷天大壮
	ZeTianGuai,		// 泽天夬
	ShuiTianXu,		// 水天需
	ShuiDiBi,		// 水地比
	HEX_Max
}Hexagram;

// 六亲
typedef enum
{
	FuMu,		// 父母
	XiongDi,	// 兄弟
	GuanGui,	// 官鬼
	QiCai,		// 妻财
	ZiSun,		// 子孙
	RelativeMax
}SixRelative;

typedef enum
{
	FirstXX = 0,	// 初爻
	SecondXX,	// 二爻
	ThirdXX,	// 三爻
	FourXX,		// 四爻
	FiveXX,		// 五爻
	SixXX		// 六爻
}XXIndex;

// 阴阳
typedef enum
{
	xxYin,
	xxYang
}HexagramSymbol;

typedef enum
{
	ShaoYang,	// 少阳
	ShaoYin,	// 少阴
	LaoYang,	// 老阳
	LaoYin		// 老阴
}XXSymbol;

typedef struct
{
	XXSymbol	xxSymbol[6];
}XXInfo;


// 五行
typedef enum
{
	WX_Jin,		// 金
	WX_Mu,		// 木
	WX_Shui,	// 水
	WX_Huo,		// 火
	WX_Tu,		// 土
	WX_Max,		// 不在五行中
}WuXing;

// 十天干
typedef enum
{
	HS_Jia,		// 甲
	HS_Yi,		// 乙
	HS_Bing,	// 丙
	HS_Ding,	// 丁
	HS_Wu,		// 戊
	HS_Ji,		// 己
	HS_Geng,	// 庚
	HS_Xin,		// 辛
	HS_Ren,		// 壬
	HS_Gui,		// 癸
	HS_Max
}HeavenlySteam;

// 十二地支
typedef enum
{
	EB_Zi,		// 子
	EB_Chou,	// 丑
	EB_Yin,		// 寅
	EB_Mao,		// 卯
	EB_Chen,	// 辰
	EB_Si,		// 巳
	EB_Wu,		// 午
	EB_Wei,		// 未
	EB_Shen,	// 申
	EB_You,		// 酉
	EB_Xu,		// 戌
	EB_Hai,		// 亥
	EB_Max
}EarthlyBranch;

// 天干地支信息
typedef struct
{
	HeavenlySteam	hsInfo;	// 天干
	EarthlyBranch	ebInfo;	// 地支
}TianGanDiZhi;

// 六兽
typedef enum
{
	QingLong,	// 青龙
	ZhuQue,		// 朱雀
	GouChen,	// 勾陈
	TengShe,	// 腾蛇
	BaiHu,		// 白虎
	XuanWu,		// 玄武
	AnimalMax
}SixAnimal;



// 十二长生
typedef enum
{
	ZhangSheng,		// 长生
	MuYu,			// 沐浴
	GuanDai,		// 冠带
	LinGuan,		// 临官
	DiWang,			// 帝旺
	Shuai,			// 衰
	Bing,			// 病
	Si,				// 死
	Mu,				// 墓
	Jue,			// 绝
	Tai,			// 胎
	Yang			// 养
}TwelveLife;

// 方位信息
typedef enum
{
	East,	// 东方
	West,	// 西方
	South,	// 南方
	North,	// 北方
	Center	// 中央
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

// 每一爻的信息
typedef struct
{
	HexagramSymbol	xxSymbol;		// 当前爻的信息
	SixRelative		xxRelative;		// 当前爻的六亲信息
	TianGanDiZhi	tgdz;			// 天干地支
	bool			isMonthBody;	// 是否是月卦身
	bool			hasF;			// 是否有伏六亲
	SixRelative		f_xxRelative;	// 伏当前爻的六亲信息
	EarthlyBranch	f_eb;			// 伏地支
}XXSymbolInfo;

// 六十四卦属性
typedef struct
{
	Hexagram	  hexagram;		// 卦的枚举
	unsigned char ucName[255];	// 卦名
	WuXing		wxName;			// 五行
	XXIndex		xxShi;			// 世爻
	XXIndex		xxYing;			// 应爻

	XXSymbolInfo	xxSymbolInfo[6];	// 六爻信息
}HexagramProperty;




// 五行相生相克
extern WuXing GetWuXingSheng(WuXing value);
extern WuXing GetWuXingKe(WuXing value);

// 六亲相生相克
SixRelative GetSixRelativeSheng(SixRelative value);
SixRelative GetSixRelativeKe(SixRelative value);

// 地支相合相冲
EarthlyBranch GetEarthlyBranchHe(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchChong(EarthlyBranch value);

// 十二地支所属
WuXing GetEarthlyBranchWuXing(EarthlyBranch value);

// 六兽
SixAnimal GetSixAnimalByHeavenlySteam(HeavenlySteam value);

HeavenlySteam GetHeavenlySteam(unsigned char index);
EarthlyBranch GetEarthlyBranch(unsigned char index);

// 计算旬空
void GetXunKong(TianGanDiZhi tdDay, EarthlyBranch* k1, EarthlyBranch* k2);

// 三刑六害
EarthlyBranch GetEarthlyBranchXing(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchHai(EarthlyBranch value);

// 天干相合
HeavenlySteam GetHeavenlySteamHe(HeavenlySteam value);

// 计算月建
EarthlyBranch GetYueJian(TianGanDiZhi tdMonth);

// 计算六兽
SixAnimalInfo GetSixAnimalInfo(TianGanDiZhi tdDay);

// 获得主卦变卦
void GetHexagramProperty(XXInfo *pxxInfo, HexagramProperty* majorHex, HexagramProperty* subHex);

