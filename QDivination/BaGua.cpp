#include "BaGua.h"
#include <string>

using namespace std;

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


// 十二地支所属
static EarthlyBranchProperty ebProperty[] =
{
	{ EB_Zi, "子",	WX_Shui,EB_Chou,EB_Wu,	EB_Mao, EB_Wei },
	{ EB_Chou,"丑",	WX_Tu,	EB_Zi,	EB_Wei, EB_Xu,	EB_Wu },
	{ EB_Yin, "寅",	WX_Mu,	EB_Hai,	EB_Shen,EB_Si,	EB_Si },
	{ EB_Mao, "卯",	WX_Mu,	EB_Xu,	EB_You, EB_Zi,	EB_Chen },
	{ EB_Chen, "辰",WX_Tu,	EB_You, EB_Xu,	EB_Chen,EB_Mao },
	{ EB_Si, "巳",	WX_Huo, EB_Shen,EB_Hai,	EB_Shen,EB_Yin },
	{ EB_Wu, "午",	WX_Huo, EB_Wei, EB_Zi,	EB_Wu,	EB_Chou },
	{ EB_Wei, "未",	WX_Tu,	EB_Wu,	EB_Chou,EB_Chou,EB_Wei },
	{ EB_Shen, "申",WX_Jin,	EB_Si,	EB_Yin, EB_Yin, EB_Hai },
	{ EB_You, "酉",	WX_Jin,	EB_Chen,EB_Mao, EB_You, EB_Xu },
	{ EB_Xu, "戌",	WX_Tu,	EB_Mao, EB_Chen,EB_Wei, EB_You },
	{ EB_Hai, "亥",	WX_Shui,EB_Yin, EB_Si,	EB_Hai, EB_Shen }
};

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

static HeavenlySteamProperty	hsProperty[] =
{
	{ HS_Jia, "甲", East, WX_Mu, HS_Ji, QingLong },
	{ HS_Yi, "乙", East, WX_Mu, HS_Geng, QingLong },
	{ HS_Bing, "丙", South, WX_Huo, HS_Xin, ZhuQue },
	{ HS_Ding, "丁", South, WX_Huo, HS_Ren, ZhuQue },
	{ HS_Wu, "戊", Center, WX_Tu, HS_Gui, GouChen },
	{ HS_Ji, "己", Center, WX_Tu, HS_Jia, TengShe },
	{ HS_Geng, "庚", West, WX_Jin, HS_Yi, BaiHu },
	{ HS_Xin, "辛", West, WX_Jin, HS_Bing, BaiHu },
	{ HS_Ren, "壬", North, WX_Shui, HS_Ding, XuanWu },
	{ HS_Gui, "癸", North, WX_Shui, HS_Wu, XuanWu }
};

// 六兽信息
static SixAnimalProperty animalProperty[] =
{
	{ QingLong, "青龙" },
	{ ZhuQue , "朱雀" },
	{ GouChen , "勾陈" },
	{ TengShe , "腾蛇" },
	{ BaiHu , "白虎" },
	{ XuanWu , "玄武" }
};

std::string GetAnimalName(SixAnimal value)
{
	for (int i = 0; i < sizeof(animalProperty) / sizeof(animalProperty[0]); i++)
	{
		if (animalProperty[i].animal == value)
			return  animalProperty[i].animalName;
	}
	return std::string();
}
static HexagramProperty hexgramProperty[] =
{
	// 卦枚举		卦名	 五行	 世爻	应爻	
	{ QianWeiTian, "乾为天", WX_Jin, SixXX, ThirdXX, {
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },	false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false,  false, RelativeMax, EB_Max } } },	// 六爻

	{ TianFengGou, "天风姤", WX_Jin, FirstXX, FourXX, {
		{ xxYin, FuMu,{ HS_Xin, EB_Chou },		false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Hai },		false,	 true, QiCai,EB_Yin },		// 二爻
		{ xxYang, XiongDi,{ HS_Xin, EB_You },	false,	 false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	true,	 false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },	false,	 false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },		false,	 false, RelativeMax,EB_Max } } },	// 六爻
		
	{ TianShanDun, "天山遁", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	false,   true, ZiSun,EB_Zi },				// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false,  true, QiCai,EB_Yin },			// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ TianDiFou, "天地否", WX_Jin, ThirdXX, SixXX, {
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,   true, ZiSun,EB_Zi },				// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false,  false, RelativeMax,EB_Max },		// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false,  false, RelativeMax,EB_Max },			// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },true,  false, RelativeMax,EB_Max },		// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ FengDiGuan, "风地观", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  true, ZiSun,EB_Zi },			// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },	false,	false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Xin, EB_Wei },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Si },false,  true, XiongDi,EB_Shen },		// 五爻
		{ xxYang, QiCai,{ HS_Xin, EB_Mao },	false,  false, RelativeMax, EB_Max }}},// 六爻

	{ ShanDiBo, "山地剥", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,   false, RelativeMax,EB_Max },		// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false,  false, RelativeMax,EB_Max },		// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },  false,  false, RelativeMax,EB_Max },			// 三爻
		{ xxYin, FuMu,{ HS_Bing, EB_Xu },	true,  false, RelativeMax,EB_Max },		// 四爻
		{ xxYin, ZiSun,{ HS_Bing, EB_Zi },false,  true, XiongDi,EB_Shen },			// 五爻
		{ xxYang, QiCai,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoDiJin, "火地晋", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,   true, ZiSun,EB_Zi },	// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	true,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ji, EB_You },false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },	false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoTianDaYou, "火天大有", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	false,  false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, true,	false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },	false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ji, EB_You },false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },	false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },	false,  false, RelativeMax, EB_Max }}},	// 六爻
	
	{ KanWeiShui, "坎为水", WX_Shui, SixXX, ThirdXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },	false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },	false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },	false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ ShuiZeJie, "水泽节", WX_Shui, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Ding, EB_Si },	false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Mao }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Ding, EB_Chou },false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	true,  false, RelativeMax, EB_Max }}},	// 六爻

	{ ShuiLeiTun, "水雷屯", WX_Shui, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Geng, EB_Zi },	false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Geng, EB_Yin }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Chen },false,  true, QiCai,EB_Wu },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false,  false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShuiHuoJiJi, "水火既济", WX_Shui, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false,  true, QiCai,EB_Wu },			// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false,  false, RelativeMax,EB_Max },		// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeHuoGe, "泽火革", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	true,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ding, EB_Hai },	false,  true, QiCai,EB_Wu },	// 四爻
		{ xxYang, FuMu,{ HS_Ding, EB_You },false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, GuanGui,{ HS_Ding, EB_Wei },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiHuoFeng, "雷火丰", WX_Shui, FiveXX, SecondXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Geng, EB_Wu },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Geng, EB_Shen },false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Xu },	true,  false, RelativeMax, EB_Max }} },	// 六爻

	{ DiHuoMingYi, "地火明夷", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },		false,   false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou },	false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },	false,  true, QiCai,EB_Wu },			// 三爻
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },	false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Gui, EB_You },		true,  false, RelativeMax, EB_Max }} },	// 六爻

	{ DiShuiShi, "地水师", WX_Shui, ThirdXX, SixXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },		false,  false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen },	false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },		false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },	false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Gui, EB_You },		false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ GenWeiShan, "艮为山", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	false,  false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Bing, EB_Wu },		false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },	false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShanHuoBen, "山火贲", WX_Tu, FirstXX, FourXX,{
		{ xxYang, GuanGui,{ HS_Ji, EB_Mao },	false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Ji, EB_Chou },	false, true, FuMu,EB_Wu },			// 二爻
		{ xxYang, QiCai,{ HS_Ji, EB_Hai },		false, true, ZiSun,EB_Shen },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		true,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShanTianDaChu, "山天大畜", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },		false,  false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },	false,  true, FuMu,EB_Wu },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },	false,  true, ZiSun,EB_Shen },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max}} },	// 六爻
	
	{ ShanZeSun, "山泽损", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false,  false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },	false,  false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false,  true, ZiSun,EB_Shen },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		false,  false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoZeKui, "火泽睽", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false,  false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },	true,	false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false,  false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ji, EB_You },		false,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Ji, EB_Wei },		false,  false, QiCai,EB_Zi },	// 五爻
		{ xxYang, FuMu,{ HS_Ji, EB_Si },		false,  false, RelativeMax, EB_Max }}},	// 六爻
	
	{ TianZeLv, "天泽履", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Ren, EB_Wu },		false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Shen },	false, true, QiCai,EB_Zi },	// 五爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Xu },	false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ FengZeZhongFu, "风泽中孚", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false, true, ZiSun,EB_Shen },	// 三爻
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, FuMu,{ HS_Xin, EB_Si },		false, true, QiCai,EB_Zi },	// 五爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ FengShanJian, "风山渐", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Bing, EB_Wu },		false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },	false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, FuMu,{ HS_Xin, EB_Si },		false, true, QiCai,EB_Zi },	// 五爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ZhenWeiLei, "震为雷", WX_Mu, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiDiYu, "雷地豫", WX_Mu, FirstXX, FourXX,{
		{ xxYin, QiCai,{ HS_Yi, EB_Wei },		false, true, FuMu,EB_Zi },	// 初爻
		{ xxYin, ZiSun,{ HS_Yi, EB_Si },		false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Yi, EB_Mao },		false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },		true,  false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },	false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },		false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiShuiJie, "雷水解", WX_Mu, SecondXX, FiveXX,{
		{ xxYin, XiongDi,{ HS_Wu, EB_Yin },	  false, true, FuMu,EB_Zi },	// 初爻
		{ xxYang, QiCai,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Wu },	false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ LeiFengHeng, "雷风恒", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, true, XiongDi,EB_Yin },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ DiFengSheng, "地风升", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },		false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },		false, true, XiongDi,EB_Yin },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },	true, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Gui, EB_Chou },		false, true, ZiSun,EB_Wu },	// 四爻
		{ xxYin, FuMu,{ HS_Gui, EB_Hai },		false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, GuanGui,{ HS_Gui, EB_You },	true, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShuiFengJing, "水风井", WX_Mu, FiveXX, SecondXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },		false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },		false, true, XiongDi,EB_Yin },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },	false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, GuanGui,{ HS_Wu, EB_Shen },	false, true, ZiSun,EB_Wu },	// 四爻
		{ xxYang, QiCai,{ HS_Wu, EB_Xu },		false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Wu, EB_Zi },			false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ ZeFengDaGuo, "泽风大过", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, true, XiongDi,EB_Yin },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	 false, true, ZiSun,EB_Wu },	// 四爻
		{ xxYang, GuanGui,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max}} },	// 六爻

	{ ZeLeiSui, "泽雷随", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	 false, true, ZiSun,EB_Wu },	// 四爻
		{ xxYang, GuanGui,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max}} },	// 六爻

	{ XunWeiFeng, "巽为风", WX_Mu, SixXX, ThirdXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si }, true, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ FengTianXiaoChu, "风天小畜", WX_Mu, FirstXX, FourXX,{
		{ xxYang, FuMu,{ HS_Jia, EB_Zi },	  true, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Jia, EB_Chen }, false, true, GuanGui,EB_You },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ FengHuoJiaRen, "风火家人", WX_Mu, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Ji, EB_Mao },	false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, QiCai,{ HS_Ji, EB_Chou },		false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, FuMu,{ HS_Ji, EB_Hai },		false, true, GuanGui,EB_You },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },		false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },		false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, RelativeMax, EB_Max }}},	// 六爻

	{ FengLeiYi, "风雷益", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, true, GuanGui,EB_You },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ TianLeiWuWang, "天雷无妄", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, QiCai,{ HS_Ren, EB_Xu },	 false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ HuoLeiShiKe, "火雷噬嗑", WX_Mu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Ji, EB_Wei },	false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, ZiSun,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShanLeiYi, "山雷颐", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, true, GuanGui,EB_You },	// 三爻
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Bing, EB_Zi },	false, true, ZiSun,EB_Si },	// 五爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShanFengGu, "山风蛊", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Bing, EB_Zi }, false, true, ZiSun,EB_Si },	// 五爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	 true, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ LiWeiHuo, "离为火", WX_Huo, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 true, false, RelativeMax, EB_Max}} },	// 六爻

	{ HuoShanLv, "火山旅", WX_Huo, FirstXX, FourXX,{
		{ xxYin, ZiSun,{ HS_Bing, EB_Chen },	  false, true, FuMu,EB_Mao },	// 初爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Wu },  true, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Bing, EB_Shen }, false, true, GuanGui,EB_Hai },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoFengDing, "火风鼎", WX_Huo, SecondXX, FiveXX,{
		{ xxYin, ZiSun,{ HS_Xin, EB_Chou },	  true, true, FuMu,EB_Mao },	// 初爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Hai },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ HuoShuiWeiJi, "火水未济", WX_Huo, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu }, false, true, GuanGui,EB_Hai },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ ShanShuiMeng, "山水蒙", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Bing, EB_Xu },	 false, true, QiCai,EB_You },	// 四爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Zi }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Bing, EB_Yin },	 false, false, RelativeMax, EB_Max}} },	// 六爻

	{ FengShuiHuan, "风水涣", WX_Huo, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  true, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu }, false, true, GuanGui,EB_Hai },	// 三爻
		{ xxYin, ZiSun,{ HS_Xin, EB_Wei },	 false, true, QiCai,EB_You },	// 四爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Si }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ TianShuiSong, "天水讼", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu }, false, true, GuanGui,EB_Hai },	// 三爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, QiCai,{ HS_Ren, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ TianHuoTongRen, "天火同人", WX_Huo, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, QiCai,{ HS_Ren, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ KunWeiDi, "坤为地", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Yi, EB_Si },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, true, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ DiLeiFu, "地雷复", WX_Tu, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Geng, EB_Zi },	  true, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Yin },  false, true, FuMu,EB_Si },	// 二爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max}} },	// 六爻

	{ DiZeLin, "地泽临", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou }, true, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 true, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ DiTianTai, "地天泰", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  true, true, FuMu,EB_Si },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiTianDaZhuang, "雷天大壮", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeTianGuai, "泽天夬", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  false, true, FuMu,EB_Si },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, true, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max}} },	// 六爻

	{ ShuiTianXu, "水天需", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  false, true, FuMu,EB_Si },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShuiDiBi, "水地比", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Yi, EB_Si },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	 true, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	 false, false, RelativeMax, EB_Max}}},	// 六爻

	{ DuiWeiZe, "兑为泽", WX_Jin, SixXX, ThirdXX,{
		{ xxYang, GuanGui,{ HS_Ding, EB_Si },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, FuMu,{ HS_Ding, EB_Chou }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 true, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeShuiKun, "泽水困", WX_Jin, FirstXX, FourXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Wu, EB_Wu }, true, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeDiCui, "泽地萃", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	  true, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 true, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeShanXian, "泽山咸", WX_Jin, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShuiShanJian, "水山蹇", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Zi },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ DiShanQian, "地山谦", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiShanXiaoGuo, "雷山小过", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	 false, true, ZiSun,EB_Hai },	// 四爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiZeGuiMei, "雷泽归妹", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ding, EB_Si },	  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, FuMu,{ HS_Ding, EB_Chou }, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	 false, true, ZiSun,EB_Hai },	// 四爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen }, true, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}}	// 六爻
};



static WuXingProperty wxProperty[] = 
{
	{WX_Jin, "金"},
	{WX_Mu, "木"},
	{WX_Shui, "水"},
	{WX_Huo, "火"},
	{WX_Tu, "土"}
};
std::string GetWuXingName(WuXing value)
{
	for (int i = 0; i < sizeof(wxProperty) / sizeof(wxProperty[0]); i++)
	{
		if (wxProperty[i].wx == value)
			return wxProperty[i].wxName;
	}
	return std::string();
}

// 五行相生
WuXing GetWuXingSheng(WuXing value)
{
	switch (value)
	{
	case WX_Jin:
		return WX_Shui;
	case WX_Shui:
		return WX_Mu;
	case WX_Mu:
		return WX_Huo;
	case WX_Huo:
		return WX_Tu;
	case WX_Tu:
		return WX_Jin;
	}
	return WX_Max;
}
// 五行相克
WuXing GetWuXingKe(WuXing value)
{
	switch (value)
	{
	case WX_Jin:
		return WX_Mu;
	case WX_Mu:
		return WX_Tu;
	case WX_Tu:
		return WX_Shui;
	case WX_Shui:
		return WX_Huo;
	case WX_Huo:
		return WX_Jin;
	}
	return WX_Max;
}

static SixRelativeProperty srProperty[] = 
{
	{ FuMu , "父母"},
	{ XiongDi , "兄弟"},
	{ GuanGui , "官鬼"},
	{ QiCai , "妻财"},
	{ ZiSun , "子孙"}
};

std::string GetSixRelativeName(SixRelative value)
{
	for (int i = 0; i < sizeof(srProperty) / sizeof(srProperty[0]); i++)
	{
		if (value == srProperty[i].sr)
			return srProperty[i].srName;
	}
	return std::string();
}
// 六亲生
SixRelative GetSixRelativeSheng(SixRelative value)
{
	switch (value)
	{
	case FuMu:
		return XiongDi;
	case XiongDi:
		return ZiSun;
	case ZiSun:
		return QiCai;
	case QiCai:
		return GuanGui;
	case GuanGui:
		return FuMu;
	}
	return RelativeMax;
}

// 六亲克
SixRelative GetSixRelativeKe(SixRelative value)
{
	switch (value)
	{
	case FuMu:
		return ZiSun;
	case ZiSun:
		return GuanGui;
	case GuanGui:
		return XiongDi;
	case XiongDi:
		return QiCai;
	case QiCai:
		return FuMu;
	}
	return RelativeMax;
}

// 获取地支相合
EarthlyBranch GetEarthlyBranchHe(EarthlyBranch value)
{
	for (int i = 0; i < sizeof(ebProperty) / sizeof(ebProperty[0]); i++)
	{
		if (value == ebProperty[i].ebName)
		{
			return ebProperty[i].ebHe;
		}
	}
	return EB_Max;
}

// 获取地支相冲
EarthlyBranch GetEarthlyBranchChong(EarthlyBranch value)
{
	for (int i = 0; i < sizeof(ebProperty) / sizeof(ebProperty[0]); i++)
	{
		if (value == ebProperty[i].ebName)
		{
			return ebProperty[i].ebChong;
		}
	}
	return EB_Max;
}

// 获取十二地支五行
WuXing GetEarthlyBranchWuXing(EarthlyBranch value)
{
	for (int i = 0; i < sizeof(ebProperty) / sizeof(ebProperty[0]); i++)
	{
		if (value == ebProperty[i].ebName)
		{
			return ebProperty[i].wxProperty;
		}
	}
	return WX_Max;
}

// 获取地支三刑
EarthlyBranch GetEarthlyBranchXing(EarthlyBranch value)
{
	for (int i = 0; i < sizeof(ebProperty) / sizeof(ebProperty[0]); i++)
	{
		if (value == ebProperty[i].ebName)
		{
			return ebProperty[i].ebXing;
		}
	}
	return EB_Max;
}

// 获取地支六害
EarthlyBranch GetEarthlyBranchHai(EarthlyBranch value)
{
	for (int i = 0; i < sizeof(ebProperty) / sizeof(ebProperty[0]); i++)
	{
		if (value == ebProperty[i].ebName)
		{
			return ebProperty[i].ebHai;
		}
	}
	return EB_Max;
}

// 获取天干相合
HeavenlySteam GetHeavenlySteamHe(HeavenlySteam value)
{
	for (int i = 0; i < sizeof(hsProperty) / sizeof(hsProperty[0]); i++)
	{
		if (value == hsProperty[i].hsName)
		{
			return hsProperty[i].hsHe;
		}
	}
	return HS_Max;
}

EarthlyBranch GetYueJian(TianGanDiZhi tdMonth)
{
	return tdMonth.ebInfo;
}

SixAnimalInfo GetSixAnimalInfo(TianGanDiZhi tdDay)
{
	int index = 0;
	SixAnimalInfo info;

	SixAnimal aniInfo = GetSixAnimalByHeavenlySteam(tdDay.hsInfo);
	for (int i = 0; i < sizeof(animalProperty); i++)
	{
		if (animalProperty[i].animal == aniInfo)
		{
			index = i;
			break;
		}
	}
	for (int i = 0; i < 6; i++)
	{
		info.xxAnimalInfo[i] = animalProperty[(index + i) % 6].animal;
	}
	return info;
}

void GetHexagramProperty(XXInfo * pxxInfo, HexagramProperty * majorHex, HexagramProperty * subHex)
{
	bool hasSubHex = false;
	for (int i = 0; i < 6; i++)
	{
		if (pxxInfo->xxSymbol[i] == LaoYang || pxxInfo->xxSymbol[i] == LaoYin)
		{
			hasSubHex = true;
			break;
		}
	}
	HexagramSymbol s[6], sup_s[6];

	for (int i = 0; i < 6; i++)
	{
		if (pxxInfo->xxSymbol[i] == ShaoYang || pxxInfo->xxSymbol[i] == LaoYang)
		{
			s[i] = sup_s[i] = xxYang;
		}
		else
		{
			s[i] = sup_s[i] = xxYin;
		}
		if (pxxInfo->xxSymbol[i] == LaoYang)
			sup_s[i] = xxYin;
		else if (pxxInfo->xxSymbol[i] == LaoYin)
			sup_s[i] = xxYang;
	}


	for (int i = 0; i < sizeof(hexgramProperty) / sizeof(hexgramProperty[0]); i++)
	{
		if (hexgramProperty[i].xxSymbolInfo[0].xxSymbol == s[0] && hexgramProperty[i].xxSymbolInfo[1].xxSymbol == s[1] &&
			hexgramProperty[i].xxSymbolInfo[2].xxSymbol == s[2] && hexgramProperty[i].xxSymbolInfo[3].xxSymbol == s[3] &&
			hexgramProperty[i].xxSymbolInfo[4].xxSymbol == s[4] && hexgramProperty[i].xxSymbolInfo[5].xxSymbol == s[5])
		{
			*majorHex = hexgramProperty[i];
			break;
		}
	}
	if (hasSubHex)
	{
		for (int i = 0; i < sizeof(hexgramProperty) / sizeof(hexgramProperty[0]); i++)
		{
			if (hexgramProperty[i].xxSymbolInfo[0].xxSymbol == sup_s[0] && hexgramProperty[i].xxSymbolInfo[1].xxSymbol == sup_s[1] &&
				hexgramProperty[i].xxSymbolInfo[2].xxSymbol == sup_s[2] && hexgramProperty[i].xxSymbolInfo[3].xxSymbol == sup_s[3] &&
				hexgramProperty[i].xxSymbolInfo[4].xxSymbol == sup_s[4] && hexgramProperty[i].xxSymbolInfo[5].xxSymbol == sup_s[5])
			{
				*subHex = hexgramProperty[i];
				break;
			}
		}
	}
	else
		subHex->hexagram = HEX_Max;
}

// 六兽
SixAnimal GetSixAnimalByHeavenlySteam(HeavenlySteam value)
{
	for (int i = 0; i < sizeof(hsProperty) / sizeof(hsProperty[0]); i++)
	{
		if (value == hsProperty[i].hsName)
		{
			return hsProperty[i].animal;
		}
	}
	return AnimalMax;
}

HeavenlySteam GetHeavenlySteam(unsigned char index)
{
	return hsProperty[index].hsName;
}

string GetHeavenlyName(HeavenlySteam value)
{
	for (int i = 0; i < sizeof(hsProperty) / sizeof(hsProperty[0]); i++)
	{
		if (value == hsProperty[i].hsName)
		{
			return hsProperty[i].hsNameStr;
		}
	}
	return string();
}

EarthlyBranch GetEarthlyBranch(unsigned char index)
{
	return ebProperty[index].ebName;
}

string GetEarthlyName(EarthlyBranch value)
{
	for (int i = 0; i < sizeof(ebProperty) / sizeof(ebProperty[0]); i++)
	{
		if (value == ebProperty[i].ebName)
		{
			return ebProperty[i].ebNameStr;
		}
	}
	return string();
}
void GetXunKong(TianGanDiZhi tdDay, EarthlyBranch * k1, EarthlyBranch * k2)
{
	// 获取当前所在旬
	int index = 0;
	EarthlyBranch value;

	for (int i = 0; i < 10; i++)
	{
		if (hsProperty[i].hsName != tdDay.hsInfo)
			continue;
		for (int j = 0; j < 12; j++)
		{
			if (ebProperty[j].ebName == tdDay.ebInfo)
			{
				if (j - i < 0)
				{
					index = j + 12 - i;
				}
				else
					index = j - i;
				value = ebProperty[index].ebName;
				break;
			}
		}
	}
	switch (value)
	{
	case EB_Zi:
		*k1 = EB_Xu;
		*k2 = EB_Hai;
		break;
	case EB_Yin:
		*k1 = EB_Zi;
		*k2 = EB_Chou;
		break;
	case EB_Chen:
		*k1 = EB_Yin;
		*k2 = EB_Mao;
		break;
	case EB_Wu:
		*k1 = EB_Chen;
		*k2 = EB_Si;
		break;
	case EB_Shen:
		*k1 = EB_Wu;
		*k2 = EB_Wei;
		break;
	case EB_Xu:
		*k1 = EB_Shen;
		*k2 = EB_You;
		break;
	}
}

