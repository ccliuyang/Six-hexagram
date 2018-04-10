#pragma once

#include "BaGua.h"


#include <list>
#include <map>
#include <string>
#include "rili/lunar.h"

using namespace std;

// 时间(年月日), 用神, 求事, 六爻

typedef struct
{
	int			  year;		// 年
	unsigned char month;	// 月
	unsigned char day;		// 日
	unsigned char hour;		// 时
	unsigned char minute;	// 分
	unsigned char second;	// 秒
}DateTime;

typedef struct
{

	DateTime	dataTime;		// 时间
	bool isRun;					// 是否闰月
	TianGanDiZhi	tdYear;		// 年天干
	TianGanDiZhi	tdMonth;	// 月天干
	TianGanDiZhi	tdDay;		// 日天干
}NLDateTime;

typedef struct
{
	TianGanDiZhi	tdYear;		// 年天干
	TianGanDiZhi	tdMonth;	// 月天干
	TianGanDiZhi	tdDay;		// 日天干
}TDDateTime;

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
	DivineInfo(XXInfo* xxInfo, DateTime* dataTime, Sex sex = Man);

	~DivineInfo() {};

	void setDateTime(DateTime& dtTime);
	void setYongGod(SixRelative value);	//  设置用神
	void setYongGod(XXIndex	index);		// 设置用神

	void drawDivineInfo(DivineInfo* pInfo);


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
	XXInfo	m_xxInfo;		// 卦爻信息
	HexagramProperty	m_majorHexProperty;	// 主卦	
	HexagramProperty	m_subHexProperty;	// 变卦

	XXIndex		m_xxShi;			// 世爻
	XXIndex		m_xxYing;			// 应爻
	XXIndex		m_xxMonthBody;		// 月卦身
	YongShenInfo	m_ysInfo;		// 用神

	std::list<EarthlyBranch> m_ebRiKong;	// 旬空
	EarthlyBranch	m_ebYueJian;			// 月建
	EarthlyBranch	m_ebYuePo;				// 月破

	DateTime	m_dateTime;		// 占卦时间（公历）
	Day			m_nlDay;		
	NLDateTime	m_nlDateTime;	// 农历信息
	SixAnimalInfo	m_animalInfo;	// 六兽信息

	Sex	m_sex;
};


// 十天干所属



// 天干地支八卦方位图





// 五行次序

// 八卦次序

// 八卦象例

// 八宫所属

// 六十四卦名（OK）

// 纳甲（OK）

// 安世应（OK）



// 安月卦身（OK）

// 三合会局

// 长生掌诀

// 禄马羊刃歌

// 贵人歌诀



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

