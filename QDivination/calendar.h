#pragma once

#include <list>
#include <map>
#include <string>
#include "rili/lunar.h"

using namespace std;

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


typedef enum
{
	ShaoYang,	// 少阳
	ShaoYin,	// 少阴
	LaoYang,	// 老阳
	LaoYin		// 老阴
}XXSymbol;


typedef enum
{
	FirstXX = 0,	// 初爻
	SecondXX,	// 二爻
	ThirdXX,	// 三爻
	FourXX,		// 四爻
	FiveXX,		// 五爻
	SixXX		// 六爻
}XXIndex;

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

typedef struct
{
	SixAnimal animal;
	string	animalStr;
}SixAnimalProperty;


typedef struct
{
	SixAnimal xxAnimalInfo[6];
}SixAnimalInfo;
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

typedef enum
{
	East,	// 东方
	West,	// 西方
	South,	// 南方
	North,	// 北方
	Center	// 中央
}Direction;


// 天干属性
typedef struct
{
	HeavenlySteam	hsName;		// 天干名称
	string			hsNameStr;
	Direction		direction;	// 方向
	WuXing			wxName;		//  五行
	HeavenlySteam	hsHe;		// 相合
	SixAnimal		animal;		// 安六兽
}HeavenlySteamProperty;


// 地支属性
typedef struct
{
	EarthlyBranch	ebName;		// 地支名称
	string			ebNameStr;	// 地支
	WuXing			wxProperty;	// 五行属性
	EarthlyBranch	ebHe;		// 地支相合
	EarthlyBranch	ebChong;	// 地支相冲
	EarthlyBranch	ebXing;		// 三刑
	EarthlyBranch	ebHai;		// 六害
}EarthlyBranchProperty;

// 阴阳
typedef enum
{
	xxYin,
	xxYang
}HexagramSymbol;

// 每一爻的信息
typedef struct
{
	HexagramSymbol	xxSymbol;		// 当前爻的信息
	SixRelative		xxRelative;		// 当前爻的六亲信息
	TianGanDiZhi	tgdz;			// 天干地支
	bool			isMonthBody;	// 是否是月卦身
	bool			isMonthBodyF;	// 月卦身是否是伏
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

// 时间(年月日), 用神, 求事, 六爻

typedef struct
{
	int			  year;		// 年
	unsigned char month;	// 月
	unsigned char day;		// 日
	unsigned char hour;		// 时
	unsigned char minute;	// 分
	unsigned char second;	// 秒
}DataTime;

typedef struct
{

	DataTime	dataTime;		// 时间
	bool isRun;					// 是否闰月
	TianGanDiZhi	tdYear;		// 年天干
	TianGanDiZhi	tdMonth;	// 月天干
	TianGanDiZhi	tdDay;		// 日天干
}NLDataTime;

// 性别
typedef enum
{
	Man,
	Woman
}Sex;

// 用神信息
typedef struct
{
	SixRelative	relativeInfo;	// 六亲信息
	bool		isFu;		// 是否伏藏
	XXIndex		xxIndex;	// 所在第几爻
	EarthlyBranch	ebInfo;	// 地支信息
}YongShenInfo;

// 占卦信息
class DivineInfo
{
public:
	DivineInfo(XXInfo* xxInfo, DataTime* dataTime, Sex sex);

	~DivineInfo() {};

	void setDataTime(DataTime& dtTime);
	void setYongGod(SixRelative value);	//  设置用神
	void setYongGod(XXIndex	index);		// 设置用神


private:
	void GetYongGod();	// 获取用神
	void GetYuanGod();	// 获取原神
	void GetJiGod();	// 获取忌神
	void GetChouGod();	// 获取仇神

	void CalcHexagram();	// 计算当前是哪个卦
	void CalcYueJian();	// 计算月建
	void CalcYuePo();	// 计算月破
	void CalcXunKong();	// 计算旬空
	void CalcAnimal();	// 安六兽
	void CalcShiYing();	// 安世应
	void CalcYuanShen();	// 计算原神

	bool isWang(XXSymbolInfo* info);	// 旺
	bool isXiang(XXSymbolInfo* info);	// 相
	bool isXiu(XXSymbolInfo* info);	// 休
	bool isQiu(XXSymbolInfo* info);	// 囚


private:
	unsigned char divinatory_symbol;

	

	XXInfo	m_xxInfo;		// 卦爻信息
	
	Hexagram	m_majorHexagram;	// 主卦
	HexagramProperty	m_majorHexProperty;

	Hexagram	m_subHexagram;		// 副卦
	HexagramProperty	m_subHexProperty;

	XXIndex		m_xxShi;			// 世爻
	XXIndex		m_xxYing;			// 应爻
	XXIndex		m_xxMonthBody;		// 月卦身
	YongShenInfo	m_ysInfo;		// 用神

	std::list<EarthlyBranch> m_ebRiKong;	// 旬空
	EarthlyBranch	m_ebYueJian;			// 月建
	EarthlyBranch	m_ebYuePo;				// 月破

	DataTime	m_dataTime;		// 占卦时间（公历）
	Day			m_nlDay;		
	NLDataTime	m_nlDataTime;	// 农历信息
	SixAnimalInfo	m_animalInfo;	// 六兽信息

	Sex	m_sex;
};


// 十天干所属

// 十二地支所属
WuXing GetEarthlyBranchWuXing(EarthlyBranch value);

// 五行相生相克
WuXing GetWuXingSheng(WuXing value);
WuXing GetWuXingKe(WuXing value);

// 六亲相生相克
SixRelative GetSixRelativeSheng(SixRelative value);
SixRelative GetSixRelativeKe(SixRelative value);

// 天干地支八卦方位图

// 天干相合
HeavenlySteam GetHeavenlySteamHe(HeavenlySteam value);

// 地支相合相冲
EarthlyBranch GetEarthlyBranchHe(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchChong(EarthlyBranch value);

// 五行次序

// 八卦次序

// 八卦象例

// 八宫所属

// 六十四卦名（OK）

// 纳甲（OK）

// 安世应（OK）

// 六兽
SixAnimal GetSixAnimalByHeavenlySteam(HeavenlySteam value);

// 安月卦身（OK）

// 三合会局

// 长生掌诀

// 禄马羊刃歌

// 贵人歌诀

// 三刑六害
EarthlyBranch GetEarthlyBranchXing(EarthlyBranch value);
EarthlyBranch GetEarthlyBranchHai(EarthlyBranch value);

// 八宫诸物

// 八宫诸身

// 定间爻

// 年上起月（ok）

// 日上起时（ok）

// 通玄赋

// 碎金赋

// 诸爻持世诀

// 世应生克空亡动静诀

// 卦身喜忌诀

// 飞伏生克吉凶歌

// 断易勿泥神煞

// 六爻安静诀

// 六爻乱动诀

// 忌神歌

// 原神歌

// 用神不上卦诀

// 用神空亡诀

// 用神发动诀

// 日辰诀

// 六亲发动诀

// 六亲变化歌

// 六兽歌断

// 日月建传符

// 八卦相配

// 六甲旬空起例（ok）

// 月破定例（ok）

// 用神分类定例

// 世应论用神

// 用神问答

// 原忌仇神论

// 飞神正论

// 伏神正传

// 六兽评论

// 四生逐位论

// 月破论

// 旬空论

// 反吟卦定例

// 伏吟卦定例

// 旺相休囚论

// 合中带克论

// 合处逢冲，冲中逢合

// 绝处逢生、克处逢生

// 变出进退神论

// 卦有不验

