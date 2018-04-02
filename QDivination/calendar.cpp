#include "calendar.h"
#include <vector>
#include <iostream>

//static HeavenlySteam hsInfo[] = { HS_Jia , HS_Yi , HS_Bing , HS_Ding , HS_Wu , HS_Ji , HS_Geng , HS_Xin , HS_Ren , HS_Gui };
static HexagramProperty hexgramProperty[] =
{
	// ��ö��		����	 ����	 ��س	Ӧس	
	{ QianWeiTian, "ǬΪ��", WX_Jin, SixXX, ThirdXX, {
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max } } },	// ��س

	{ TianFengGou, "��犥", WX_Jin, FirstXX, FourXX, {
		{ xxYin, FuMu,{ HS_Xin, EB_Chou },		false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Hai },		false,	false, true, QiCai,EB_Yin },		// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_You },	false,	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	true,	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },	false,	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },		false,	false, false, RelativeMax,EB_Max } } },	// ��س
		
	// ������
	{ TianShanDun, "��ɽ��", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	false,  false, true, ZiSun,EB_Zi },				// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, true, QiCai,EB_Yin },			// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ TianDiFou, "��ط�", WX_Jin, ThirdXX, SixXX, {
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, true, ZiSun,EB_Zi },				// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },		// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },			// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },true, false, false, RelativeMax,EB_Max },		// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	// ������
	{ FengDiGuan, "��ع�", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, true, ZiSun,EB_Zi },			// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Si },false, false, true, XiongDi,EB_Shen },		// ��س
		{ xxYang, QiCai,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},// ��س

	{ ShanDiBo, "ɽ�ذ�", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, false, RelativeMax,EB_Max },		// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },		// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },			// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Xu },	true, false, false, RelativeMax,EB_Max },		// ��س
		{ xxYin, ZiSun,{ HS_Bing, EB_Zi },false, false, true, XiongDi,EB_Shen },			// ��س
		{ xxYang, QiCai,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ HuoDiJin, "��ؽ�", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  false, true, ZiSun,EB_Zi },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	true, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ HuoTianDaYou, "�������", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, true, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ KanWeiShui, "��Ϊˮ", WX_Shui, SixXX, ThirdXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },	false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShuiZeJie, "ˮ���", WX_Shui, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Ding, EB_Si },	false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	true, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShuiLeiTun, "ˮ����", WX_Shui, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Geng, EB_Zi },	false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShuiHuoJiJi, "ˮ��ȼ�", WX_Shui, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeHuoGe, "����", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiHuoFeng, "�׻��", WX_Shui, FiveXX, SecondXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Xu },	true, false, false, RelativeMax, EB_Max }} },	// ��س

	{ DiHuoMingYi, "�ػ�����", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }} },	// ��س

	{ DiShuiShi, "��ˮʦ", WX_Shui, ThirdXX, SixXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ GenWeiShan, "��Ϊɽ", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShanHuoBen, "ɽ����", WX_Tu, FirstXX, FourXX,{
		{ xxYang, GuanGui,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShanTianDaChu, "ɽ�����", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ ShanZeSun, "ɽ����", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ HuoZeKui, "�����", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ TianZeLv, "������", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ FengZeZhongFu, "��������", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ FengShanJian, "��ɽ��", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ZhenWeiLei, "��Ϊ��", WX_Mu, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiDiYu, "�׵�ԥ", WX_Mu, FirstXX, FourXX,{
		{ xxYin, QiCai,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiShuiJie, "��ˮ��", WX_Mu, SecondXX, FiveXX,{
		{ xxYin, XiongDi,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ LeiFengHeng, "�׷��", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ DiFengSheng, "�ط���", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShuiFengJing, "ˮ�羮", WX_Mu, FiveXX, SecondXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ ZeFengDaGuo, "�����", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max}} },	// ��س

	{ ZeLeiSui, "������", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max}} },	// ��س

	{ XunWeiFeng, "��Ϊ��", WX_Mu, SixXX, ThirdXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ FengTianXiaoChu, "����С��", WX_Mu, FirstXX, FourXX,{
		{ xxYang, FuMu,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ FengHuoJiaRen, "������", WX_Mu, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ FengLeiYi, "������", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ TianLeiWuWang, "��������", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ HuoLeiShiKe, "�������", WX_Mu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShanLeiYi, "ɽ����", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShanFengGu, "ɽ���", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ LiWeiHuo, "��Ϊ��", WX_Huo, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max}} },	// ��س

	{ HuoShanLv, "��ɽ��", WX_Huo, FirstXX, FourXX,{
		{ xxYin, ZiSun,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ HuoFengDing, "��綦", WX_Huo, SecondXX, FiveXX,{
		{ xxYin, ZiSun,{ HS_Xin, EB_Chou },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Hai }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Xin, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ HuoShuiWeiJi, "��ˮδ��", WX_Huo, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	false, false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ ShanShuiMeng, "ɽˮ��", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Bing, EB_Xu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Zi },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Bing, EB_Yin },	false, false, false, RelativeMax, EB_Max}} },	// ��س

	{ FengShuiHuan, "��ˮ��", WX_Huo, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Xin, EB_Wei },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Si },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Mao },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ TianShuiSong, "��ˮ��", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ TianHuoTongRen, "���ͬ��", WX_Huo, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ren, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ KunWeiDi, "��Ϊ��", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ DiLeiFu, "���׸�", WX_Tu, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Geng, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max}} },	// ��س

	{ DiZeLin, "������", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ DiTianTai, "����̩", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiTianDaZhuang, "�����׳", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeTianGuai, "�����", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max}} },	// ��س

	{ ShuiTianXu, "ˮ����", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShuiDiBi, "ˮ�ر�", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max}}},	// ��س

	{ DuiWeiZe, "��Ϊ��", WX_Jin, SixXX, ThirdXX,{
		{ xxYang, GuanGui,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeShuiKun, "��ˮ��", WX_Jin, FirstXX, FourXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Wu, EB_Chen }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Wu, EB_Wu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeDiCui, "�����", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeShanXian, "��ɽ��", WX_Jin, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	false, false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShuiShanJian, "ˮɽ�", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Zi },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ DiShanQian, "��ɽǫ", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_Chou },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_Hai },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_You },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiShanXiaoGuo, "��ɽС��", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiZeGuiMei, "�������", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ding, EB_Si },	true,  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ding, EB_Mao }, false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Chou },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen },false, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	false, false, false, RelativeMax, EB_Max }}}	// ��س
};

static HeavenlySteamProperty	hsProperty[] =
{
	{ HS_Jia, "��", East, WX_Mu, HS_Ji, QingLong },
	{ HS_Yi, "��", East, WX_Mu, HS_Geng, QingLong },
	{ HS_Bing, "��", South, WX_Huo, HS_Xin, ZhuQue },
	{ HS_Ding, "��", South, WX_Huo, HS_Ren, ZhuQue },
	{ HS_Wu, "��", Center, WX_Tu, HS_Gui, GouChen },
	{ HS_Ji, "��", Center, WX_Tu, HS_Jia, TengShe },
	{ HS_Geng, "��", West, WX_Jin, HS_Yi, BaiHu },
	{ HS_Xin, "��", West, WX_Jin, HS_Bing, BaiHu },
	{ HS_Ren, "��", North, WX_Shui, HS_Ding, XuanWu },
	{ HS_Gui, "��", North, WX_Shui, HS_Wu, XuanWu }
};

// ʮ����֧����
static EarthlyBranchProperty ebProperty[] =
{
	{ EB_Zi, "��",	WX_Shui,EB_Chou,EB_Wu,	EB_Mao, EB_Wei },
	{ EB_Chou,"��",	WX_Tu,	EB_Zi,	EB_Wei, EB_Xu,	EB_Wu },
	{ EB_Yin, "��",	WX_Mu,	EB_Hai,	EB_Shen,EB_Si,	EB_Si },
	{ EB_Mao, "î",	WX_Mu,	EB_Xu,	EB_You, EB_Zi,	EB_Chen },
	{ EB_Chen, "��",WX_Tu,	EB_You, EB_Xu,	EB_Chen,EB_Mao },
	{ EB_Si, "��",	WX_Huo, EB_Shen,EB_Hai,	EB_Shen,EB_Yin },
	{ EB_Wu, "��",	WX_Huo, EB_Wei, EB_Zi,	EB_Wu,	EB_Chou },
	{ EB_Wei, "δ",	WX_Tu,	EB_Wu,	EB_Chou,EB_Chou,EB_Wei },
	{ EB_Shen, "��",WX_Jin,	EB_Si,	EB_Yin, EB_Yin, EB_Hai },
	{ EB_You, "��",	WX_Jin,	EB_Chen,EB_Mao, EB_You, EB_Xu },
	{ EB_Xu, "��",	WX_Tu,	EB_Mao, EB_Chen,EB_Wei, EB_You },
	{ EB_Hai, "��",	WX_Shui,EB_Yin, EB_Si,	EB_Hai, EB_Shen }
};

// ������Ϣ
static SixAnimalProperty animalProperty[] = 
{
	{QingLong, "����"},
	{ ZhuQue , "��ȸ"},
	{ GouChen , "����"},
	{ TengShe , "����"},
	{ BaiHu , "�׻�"},
	{ XuanWu , "����"}
};

DivineInfo::DivineInfo(XXInfo * xxInfo, DataTime* dataTime, Sex sex)
{

	for (int i = 0; i < 6; i++)
	{
		m_xxInfo.xxSymbol[i] = xxInfo->xxSymbol[i];
	}
	CalcHexagram();	// �������ԡ�����
	CalcShiYing();	// ������Ӧ
	setDataTime(*dataTime);
	CalcYueJian();	// �½�
	CalcYuePo();	// ����
	CalcXunKong();	// Ѯ��
	CalcAnimal();	// ��������
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
				// ������첻�ǽ���
			}
			else
			{
				// �����ǽ������жϵ�ǰʱ���ڽ���ǰ���Ǻ�,��ǰΪǰһ����ɵ�֧���ں�Ϊ��һ����ɵ�֧
				std::string jqTime = day.jqsj;
				int hour = atoi(jqTime.substr(0, 2).c_str());
				int minute = atoi(jqTime.substr(3, 2).c_str());
				int second = atoi(jqTime.substr(6, 2).c_str());
				if ((hour > dtTime.hour) || (hour == dtTime.hour && minute > dtTime.minute) || (hour == dtTime.hour && minute == dtTime.minute && second > dtTime.second))
				{
					// ��ǰʱ��δ������ʱ��
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

// ��������
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
		// û�ҵ���������,�ҷ�����
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
		// �ҵ�һ��
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
		// ������س���ó�����������Ȩ�������գ����䲻�ƶ������ƣ����ò��ն���Ѯ�գ������й
		// ���в�֮�䣬�Ϸ�����ҽҩ֮��
		std::cout << "��δʵ��" << std::endl;
	}
	
}

void DivineInfo::setYongGod(XXIndex index)
{
	// ָ���ڼ�سΪ����
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
	// ��ȡ��ǰ����Ѯ
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



// ��������
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
// �������
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



// ��ȡ������
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

// ����
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



// ��ȡʮ����֧����
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

// ��ȡ��֧���
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

// ��ȡ��֧���
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

// ��ȡ��֧����
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

// ��ȡ��֧����
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

// ������
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

// ���׿�
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


