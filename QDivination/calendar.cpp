#include "calendar.h"
#include <vector>
#include <iostream>

//static HeavenlySteam hsInfo[] = { HS_Jia , HS_Yi , HS_Bing , HS_Ding , HS_Wu , HS_Ji , HS_Geng , HS_Xin , HS_Ren , HS_Gui };
static HexagramProperty hexgramProperty[] =
{
	// 卦枚举		卦名	 五行	 世爻	应爻	
	{ QianWeiTian, "乾为天", WX_Jin, SixXX, ThirdXX, {
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },	false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max } } },	// 六爻

	{ TianFengGou, "天风姤", WX_Jin, FirstXX, FourXX, {
		{ xxYin, FuMu,{ HS_Xin, EB_Chou },		false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Hai },		false,	false, true, QiCai,EB_Yin },		// 二爻
		{ xxYang, XiongDi,{ HS_Xin, EB_You },	false,	false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	true,	false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },	false,	false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },		false,	false, false, RelativeMax,EB_Max } } },	// 六爻
		
	// 无卦身
	{ TianShanDun, "天山遁", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	false,  false, true, ZiSun,EB_Zi },				// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, true, QiCai,EB_Yin },			// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ TianDiFou, "天地否", WX_Jin, ThirdXX, SixXX, {
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, true, ZiSun,EB_Zi },				// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },		// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },			// 三爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },true, false, false, RelativeMax,EB_Max },		// 五爻
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	// 无卦身
	{ FengDiGuan, "风地观", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, true, ZiSun,EB_Zi },			// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Si },false, false, true, XiongDi,EB_Shen },		// 五爻
		{ xxYang, QiCai,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},// 六爻

	{ ShanDiBo, "山地剥", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, false, RelativeMax,EB_Max },		// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },		// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },			// 三爻
		{ xxYin, FuMu,{ HS_Bing, EB_Xu },	true, false, false, RelativeMax,EB_Max },		// 四爻
		{ xxYin, ZiSun,{ HS_Bing, EB_Zi },false, false, true, XiongDi,EB_Shen },			// 五爻
		{ xxYang, QiCai,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoDiJin, "火地晋", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, true, ZiSun,EB_Zi },	// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	true, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ji, EB_You },false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoTianDaYou, "火天大有", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, true, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ KanWeiShui, "坎为水", WX_Shui, SixXX, ThirdXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },	false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShuiZeJie, "水泽节", WX_Shui, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Ding, EB_Si },	false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	true, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShuiLeiTun, "水雷屯", WX_Shui, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Geng, EB_Zi },	false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShuiHuoJiJi, "水火既济", WX_Shui, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeHuoGe, "泽火革", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, FuMu,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, GuanGui,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiHuoFeng, "雷火丰", WX_Shui, FiveXX, SecondXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Xu },	true, false, false, RelativeMax, EB_Max }} },	// 六爻

	{ DiHuoMingYi, "地火明夷", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }} },	// 六爻

	{ DiShuiShi, "地水师", WX_Shui, ThirdXX, SixXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ GenWeiShan, "艮为山", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShanHuoBen, "山火贲", WX_Tu, FirstXX, FourXX,{
		{ xxYang, GuanGui,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShanTianDaChu, "山天大畜", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ ShanZeSun, "山泽损", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoZeKui, "火泽睽", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ TianZeLv, "天泽履", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ FengZeZhongFu, "风泽中孚", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, FuMu,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ FengShanJian, "风山渐", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, FuMu,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ZhenWeiLei, "震为雷", WX_Mu, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiDiYu, "雷地豫", WX_Mu, FirstXX, FourXX,{
		{ xxYin, QiCai,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiShuiJie, "雷水解", WX_Mu, SecondXX, FiveXX,{
		{ xxYin, XiongDi,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ LeiFengHeng, "雷风恒", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ DiFengSheng, "地风升", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, GuanGui,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShuiFengJing, "水风井", WX_Mu, FiveXX, SecondXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, GuanGui,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, QiCai,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ ZeFengDaGuo, "泽风大过", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max}} },	// 六爻

	{ ZeLeiSui, "泽雷随", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max}} },	// 六爻

	{ XunWeiFeng, "巽为风", WX_Mu, SixXX, ThirdXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ FengTianXiaoChu, "风天小畜", WX_Mu, FirstXX, FourXX,{
		{ xxYang, FuMu,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ FengHuoJiaRen, "风火家人", WX_Mu, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, QiCai,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, FuMu,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ FengLeiYi, "风雷益", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ TianLeiWuWang, "天雷无妄", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, GuanGui,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, QiCai,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ HuoLeiShiKe, "火雷噬嗑", WX_Mu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, ZiSun,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShanLeiYi, "山雷颐", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShanFengGu, "山风蛊", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, FuMu,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ LiWeiHuo, "离为火", WX_Huo, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max}} },	// 六爻

	{ HuoShanLv, "火山旅", WX_Huo, FirstXX, FourXX,{
		{ xxYin, ZiSun,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, XiongDi,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ HuoFengDing, "火风鼎", WX_Huo, SecondXX, FiveXX,{
		{ xxYin, ZiSun,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, QiCai,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ HuoShuiWeiJi, "火水未济", WX_Huo, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max}} },	// 六爻
	
	{ ShanShuiMeng, "山水蒙", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max}} },	// 六爻

	{ FengShuiHuan, "风水涣", WX_Huo, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, FuMu,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ TianShuiSong, "天水讼", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, QiCai,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ TianHuoTongRen, "天火同人", WX_Huo, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, QiCai,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ KunWeiDi, "坤为地", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ DiLeiFu, "地雷复", WX_Tu, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max}} },	// 六爻

	{ DiZeLin, "地泽临", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ DiTianTai, "地天泰", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiTianDaZhuang, "雷天大壮", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, FuMu,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeTianGuai, "泽天夬", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, QiCai,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, ZiSun,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max}} },	// 六爻

	{ ShuiTianXu, "水天需", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ShuiDiBi, "水地比", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, FuMu,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max}}},	// 六爻

	{ DuiWeiZe, "兑为泽", WX_Jin, SixXX, ThirdXX,{
		{ xxYang, GuanGui,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, FuMu,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeShuiKun, "泽水困", WX_Jin, FirstXX, FourXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, GuanGui,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeDiCui, "泽地萃", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ ZeShanXian, "泽山咸", WX_Jin, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// 六爻
	
	{ ShuiShanJian, "水山蹇", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, ZiSun,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ DiShanQian, "地山谦", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYin, FuMu,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, ZiSun,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, XiongDi,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiShanXiaoGuo, "雷山小过", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// 六爻

	{ LeiZeGuiMei, "雷泽归妹", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// 初爻
		{ xxYang, QiCai,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// 二爻
		{ xxYin, FuMu,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// 三爻
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// 四爻
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// 五爻
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}}	// 六爻
};

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

// 六兽信息
static SixAnimalProperty animalProperty[] = 
{
	{QingLong, "青龙"},
	{ ZhuQue , "朱雀"},
	{ GouChen , "勾陈"},
	{ TengShe , "腾蛇"},
	{ BaiHu , "白虎"},
	{ XuanWu , "玄武"}
};

DivineInfo::DivineInfo(XXInfo * xxInfo, DataTime* dataTime, Sex sex)
{

	for (int i = 0; i < 6; i++)
	{
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	}
	CalcHexagram();	// 计算主卦、副卦
	CalcShiYing();	// 计算世应
	setDataTime(*dataTime);
	CalcYueJian();	// 月建
	CalcYuePo();	// 月破
	CalcXunKong();	// 旬空
	CalcAnimal();	// 计算六兽
	m_sex = sex;
}

void DivineInfo::setDataTime(DataTime & dtTime)
{
	m_dataTime = dtTime;
	Lunar lunar;
	Month month = lunar.yueLiCalc(m_dataTime.year, m_dataTime.month);
	std::vector<Day> & days = month.days;
	for (auto it = days.begin(); it != days.end(); ++it)
	{
		Day& day = (*it);
		if (day.d != m_dataTime.day)
		{
			continue;
		}
		else
		{
			m_nlDay = day;
			m_nlDataTime.dataTime.year = m_nlDay.Lyear;
			if (m_nlDay.Lmc == 0 || m_nlDay.Lmc == 1)
			{
				m_nlDataTime.dataTime.month = 11 + m_nlDay.Lmc;
			}
			else
			{
				m_nlDataTime.dataTime.month = m_nlDay.Lmc - 1;
			}
			m_nlDataTime.dataTime.day = (m_nlDay.Ldi + 1);
			m_nlDataTime.dataTime.hour = dtTime.hour;
			m_nlDataTime.dataTime.minute = dtTime.minute;
			m_nlDataTime.dataTime.second = dtTime.second;
			m_nlDataTime.isRun = day.Lleap;
			m_nlDataTime.tdYear.hsInfo = hsProperty[day.Lyear2.tg].hsName;
			m_nlDataTime.tdYear.ebInfo = ebProperty[day.Lyear2.dz].ebName;
			m_nlDataTime.tdMonth.hsInfo = hsProperty[day.Lmonth2.tg].hsName;
			m_nlDataTime.tdMonth.ebInfo = ebProperty[day.Lmonth2.dz].ebName;
			m_nlDataTime.tdDay.hsInfo = hsProperty[day.Lday2.tg].hsName;
			m_nlDataTime.tdDay.ebInfo = ebProperty[day.Lday2.dz].ebName;
			if (day.qk == -1)
			{
				// 如果当天不是节气
			}
			else
			{
				// 当天是节气，判断当前时间在节气前还是后,在前为前一天天干地支，在后为后一天天干地支
				std::string jqTime = day.jqsj;
				int hour = atoi(jqTime.substr(0, 2).c_str());
				int minute = atoi(jqTime.substr(3, 2).c_str());
				int second = atoi(jqTime.substr(6, 2).c_str());
				if ((hour > dtTime.hour) || (hour == dtTime.hour && minute > dtTime.minute) || (hour == dtTime.hour && minute == dtTime.minute && second > dtTime.second))
				{
					// 当前时间未到节气时间
					int yTg = (day.Lyear2.tg - 1) < 0 ? 9 : day.Lyear2.tg - 1;
					int yDz = (day.Lyear2.dz - 1) < 0 ? 11 : day.Lyear2.dz - 1;
					int mTg = (day.Lmonth2.tg - 1) < 0 ? 9 : day.Lmonth2.tg - 1;
					int mDz = (day.Lmonth2.dz - 1) < 0 ? 11 : day.Lmonth2.dz - 1;

					m_nlDataTime.tdYear.hsInfo = hsProperty[yTg].hsName;
					m_nlDataTime.tdYear.ebInfo = ebProperty[yDz].ebName;
					m_nlDataTime.tdMonth.hsInfo = hsProperty[mTg].hsName;
					m_nlDataTime.tdMonth.ebInfo = ebProperty[mDz].ebName;
				}
				else
				{

				}
			}
			return;
		}

	}
	
}

// 设置用神
void DivineInfo::setYongGod(SixRelative value)
{
	int count = 0;

	for (int i = 0; i < 6; i++)
	{
		if (m_majorHexProperty.xxSymbolInfo[i].xxRelative == value)
			count++;
	}
	if (count == 0)
	{
		// 没找到所须六亲,找伏六亲
		for (int i = 0; i < 6; i++)
		{
			if (m_majorHexProperty.xxSymbolInfo[i].hasF == true)
			{
				if (m_majorHexProperty.xxSymbolInfo[i].f_xxRelative == value)
				{
					m_ysInfo.isFu = true;
					m_ysInfo.ebInfo = m_majorHexProperty.xxSymbolInfo[i].f_eb;
					m_ysInfo.relativeInfo = value;
					m_ysInfo.xxIndex = (XXIndex)i;
				}
			}
		}
	}
	else if (count == 1)
	{
		// 找到一个
		m_ysInfo.isFu = false;
		for (int i = 0; i < 6; i++)
		{
			if (m_majorHexProperty.xxSymbolInfo[i].xxRelative == value)
			{
				m_ysInfo.ebInfo = m_majorHexProperty.xxSymbolInfo[i].tgdz.ebInfo;
				m_ysInfo.relativeInfo = value;
				m_ysInfo.xxIndex = (XXIndex)i;
			}
		}	
	}
	else
	{
		// 舍其闲爻而用持世，舍其无权而用月日，舍其不破而用月破，舍用不空而用旬空，天机尽泄
		// 于有病之间，断法总在医药之处
		std::cout << "暂未实现" << std::endl;
	}
	
}

void DivineInfo::setYongGod(XXIndex index)
{
	// 指定第几爻为用神
	m_ysInfo.xxIndex = (XXIndex)index;
	m_ysInfo.ebInfo = m_majorHexProperty.xxSymbolInfo[(int)index].tgdz.ebInfo;
	m_ysInfo.relativeInfo = m_majorHexProperty.xxSymbolInfo[(int)index].xxRelative;

}


void DivineInfo::GetYongGod()
{
}

void DivineInfo::GetYuanGod()
{
}

void DivineInfo::GetJiGod()
{
}

void DivineInfo::GetChouGod()
{
}


void DivineInfo::CalcHexagram()
{
	bool hasSubHex = false;
	for (int i = 0; i < 6; i++)
	{
		if (m_xxInfo.xxSymbol[i] == LaoYang || m_xxInfo.xxSymbol[i] == LaoYin)
		{
			hasSubHex = true;
			break;
		}
	}
	HexagramSymbol s[6], sup_s[6];

	for (int i = 0; i < 6; i++)
	{
		if (m_xxInfo.xxSymbol[i] == ShaoYang || m_xxInfo.xxSymbol[i] == LaoYang)
		{
			s[i] = sup_s[i] = xxYang;
		}
		else
		{
			s[i] = sup_s[i] = xxYin;
		}
		if (m_xxInfo.xxSymbol[i] == LaoYang)
			sup_s[i] = xxYin;
		else if(m_xxInfo.xxSymbol[i] == LaoYin)
			sup_s[i] = xxYang;
	}


	for (int i = 0; i < sizeof(hexgramProperty) / sizeof(hexgramProperty[0]); i++)
	{
		if (hexgramProperty[i].xxSymbolInfo[0].xxSymbol == s[0] && hexgramProperty[i].xxSymbolInfo[1].xxSymbol == s[1] &&
			hexgramProperty[i].xxSymbolInfo[2].xxSymbol == s[2] && hexgramProperty[i].xxSymbolInfo[3].xxSymbol == s[3] &&
			hexgramProperty[i].xxSymbolInfo[4].xxSymbol == s[4] && hexgramProperty[i].xxSymbolInfo[5].xxSymbol == s[5])
		{
			m_majorHexagram = hexgramProperty[i].hexagram;
			m_majorHexProperty = hexgramProperty[i];
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
				m_subHexagram = hexgramProperty[i].hexagram;
				m_subHexProperty = hexgramProperty[i];
				break;
			}
		}
	}
	else
		m_subHexagram = HEX_Max;
}

void DivineInfo::CalcYueJian()
{
	m_ebYueJian = m_nlDataTime.tdMonth.ebInfo;
}

void DivineInfo::CalcYuePo()
{
	m_ebYuePo = GetEarthlyBranchChong(m_nlDataTime.tdMonth.ebInfo);
}

void DivineInfo::CalcXunKong()
{
	// 获取当前所在旬
	int index = 0;
	EarthlyBranch value;

	for (int i = 0; i < 10; i++)
	{
		if (hsProperty[i].hsName != m_nlDataTime.tdDay.hsInfo)
			continue;
		for (int j = 0; j < 12; j++)
		{
			if (ebProperty[j].ebName == m_nlDataTime.tdDay.ebInfo)
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
		m_ebRiKong.push_back(EB_Xu);
		m_ebRiKong.push_back(EB_Hai);
		break;
	case EB_Yin:
		m_ebRiKong.push_back(EB_Zi);
		m_ebRiKong.push_back(EB_Chou);
		break;
	case EB_Chen:
		m_ebRiKong.push_back(EB_Yin);
		m_ebRiKong.push_back(EB_Mao);
		break;
	case EB_Wu:
		m_ebRiKong.push_back(EB_Chen);
		m_ebRiKong.push_back(EB_Si);
		break;
	case EB_Shen:
		m_ebRiKong.push_back(EB_Wu);
		m_ebRiKong.push_back(EB_Wei);
		break;
	case EB_Xu:
		m_ebRiKong.push_back(EB_Shen);
		m_ebRiKong.push_back(EB_You);
		break;
	}
}

void DivineInfo::CalcAnimal()
{
	int index = 0;

	SixAnimal aniInfo = GetSixAnimalByHeavenlySteam(m_nlDataTime.tdDay.hsInfo);
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
		m_animalInfo.xxAnimalInfo[i] = animalProperty[(index + i) % 6].animal;
	}
	
}

void DivineInfo::CalcShiYing()
{
	for (int i = 0; i < sizeof(hexgramProperty) / sizeof(hexgramProperty[0]); i++)
	{
		if (hexgramProperty[i].hexagram == m_majorHexagram)
		{
			m_xxShi = hexgramProperty[i].xxShi;
			m_xxYing = hexgramProperty[i].xxYing;
			break;
		}
	}
}

void DivineInfo::CalcYuanShen()
{

}

bool DivineInfo::isWang(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (xxWuxing == yueWuxing)
		return true;
	return false;
}

bool DivineInfo::isXiang(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (GetWuXingSheng(yueWuxing) == xxWuxing)
		return true;
	return false;
}

bool DivineInfo::isXiu(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (GetWuXingKe(yueWuxing) == xxWuxing)
		return true;
	return false;
}

bool DivineInfo::isQiu(XXSymbolInfo * info)
{
	WuXing xxWuxing = GetEarthlyBranchWuXing(info->tgdz.ebInfo);
	WuXing yueWuxing = GetEarthlyBranchWuXing(m_ebYueJian);
	if (GetWuXingKe(GetWuXingSheng(yueWuxing)) == xxWuxing)
		return true;
	return false;
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


