#include "BaGua.h"
#include <string>

using namespace std;

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

// ������Ϣ
static SixAnimalProperty animalProperty[] =
{
	{ QingLong, "����" },
	{ ZhuQue , "��ȸ" },
	{ GouChen , "����" },
	{ TengShe , "����" },
	{ BaiHu , "�׻�" },
	{ XuanWu , "����" }
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
	// ��ö��		����	 ����	 ��س	Ӧس	
	{ QianWeiTian, "ǬΪ��", WX_Jin, SixXX, ThirdXX, {
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false,  false, RelativeMax, EB_Max } } },	// ��س

	{ TianFengGou, "��犥", WX_Jin, FirstXX, FourXX, {
		{ xxYin, FuMu,{ HS_Xin, EB_Chou },		false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Hai },		false,	 true, QiCai,EB_Yin },		// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_You },	false,	 false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	true,	 false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },	false,	 false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },		false,	 false, RelativeMax,EB_Max } } },	// ��س
		
	{ TianShanDun, "��ɽ��", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	false,   true, ZiSun,EB_Zi },				// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu }, false,  true, QiCai,EB_Yin },			// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ TianDiFou, "��ط�", WX_Jin, ThirdXX, SixXX, {
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,   true, ZiSun,EB_Zi },				// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false,  false, RelativeMax,EB_Max },		// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },false,  false, RelativeMax,EB_Max },			// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Wu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Shen },true,  false, RelativeMax,EB_Max },		// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Xu },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ FengDiGuan, "��ع�", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,  true, ZiSun,EB_Zi },			// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },	false,	false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Xin, EB_Wei },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Si },false,  true, XiongDi,EB_Shen },		// ��س
		{ xxYang, QiCai,{ HS_Xin, EB_Mao },	false,  false, RelativeMax, EB_Max }}},// ��س

	{ ShanDiBo, "ɽ�ذ�", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,   false, RelativeMax,EB_Max },		// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si }, false,  false, RelativeMax,EB_Max },		// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },  false,  false, RelativeMax,EB_Max },			// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Xu },	true,  false, RelativeMax,EB_Max },		// ��س
		{ xxYin, ZiSun,{ HS_Bing, EB_Zi },false,  true, XiongDi,EB_Shen },			// ��س
		{ xxYang, QiCai,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ HuoDiJin, "��ؽ�", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	false,   true, ZiSun,EB_Zi },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao },	true,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_You },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },false,  false, RelativeMax, EB_Max }}},	// ��س

	{ HuoTianDaYou, "�������", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Jia, EB_Zi },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Jia, EB_Yin }, true,	false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Jia, EB_Chen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_You },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ji, EB_Wei },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Si },	false,  false, RelativeMax, EB_Max }}},	// ��س
	
	{ KanWeiShui, "��Ϊˮ", WX_Shui, SixXX, ThirdXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },	false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ ShuiZeJie, "ˮ���", WX_Shui, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Ding, EB_Si },	false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Mao }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ding, EB_Chou },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	true,  false, RelativeMax, EB_Max }}},	// ��س

	{ ShuiLeiTun, "ˮ����", WX_Shui, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Geng, EB_Zi },	false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Geng, EB_Yin }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Chen },false,  true, QiCai,EB_Wu },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false,  false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShuiHuoJiJi, "ˮ��ȼ�", WX_Shui, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false,  true, QiCai,EB_Wu },			// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Xu },false,  false, RelativeMax,EB_Max },		// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Zi },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ ZeHuoGe, "����", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	true,   false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_Hai },	false,  true, QiCai,EB_Wu },	// ��س
		{ xxYang, FuMu,{ HS_Ding, EB_You },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ding, EB_Wei },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ LeiHuoFeng, "�׻��", WX_Shui, FiveXX, SecondXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },	false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou }, false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Geng, EB_Wu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Geng, EB_Shen },false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Xu },	true,  false, RelativeMax, EB_Max }} },	// ��س

	{ DiHuoMingYi, "�ػ�����", WX_Shui, FourXX, FirstXX,{
		{ xxYang, ZiSun,{ HS_Ji, EB_Mao },		false,   false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Ji, EB_Chou },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Hai },	false,  true, QiCai,EB_Wu },			// ��س
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_You },		true,  false, RelativeMax, EB_Max }} },	// ��س

	{ DiShuiShi, "��ˮʦ", WX_Shui, ThirdXX, SixXX,{
		{ xxYin, ZiSun,{ HS_Wu, EB_Yin },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Wu, EB_Chen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Wu },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Gui, EB_Chou },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Hai },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_You },		false,  false, RelativeMax, EB_Max }}},	// ��س

	{ GenWeiShan, "��Ϊɽ", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Wu },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShanHuoBen, "ɽ����", WX_Tu, FirstXX, FourXX,{
		{ xxYang, GuanGui,{ HS_Ji, EB_Mao },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ji, EB_Chou },	false, true, FuMu,EB_Wu },			// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_Hai },		false, true, ZiSun,EB_Shen },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		true,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShanTianDaChu, "ɽ�����", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },	false,  true, FuMu,EB_Wu },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen },	false,  true, ZiSun,EB_Shen },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max}} },	// ��س
	
	{ ShanZeSun, "ɽ����", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false,  true, ZiSun,EB_Shen },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Xu },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Zi },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Bing, EB_Yin },	false,  false, RelativeMax, EB_Max }}},	// ��س

	{ HuoZeKui, "�����", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },	true,	false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ji, EB_You },		false,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ji, EB_Wei },		false,  false, QiCai,EB_Zi },	// ��س
		{ xxYang, FuMu,{ HS_Ji, EB_Si },		false,  false, RelativeMax, EB_Max }}},	// ��س
	
	{ TianZeLv, "������", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ren, EB_Wu },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Shen },	false, true, QiCai,EB_Zi },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Xu },	false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ FengZeZhongFu, "��������", WX_Tu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou },	false, true, ZiSun,EB_Shen },	// ��س
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Si },		false, true, QiCai,EB_Zi },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ FengShanJian, "��ɽ��", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Bing, EB_Chen },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Wu },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Bing, EB_Shen },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Xin, EB_Wei },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Si },		false, true, QiCai,EB_Zi },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Mao },	false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ZhenWeiLei, "��Ϊ��", WX_Mu, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiDiYu, "�׵�ԥ", WX_Mu, FirstXX, FourXX,{
		{ xxYin, QiCai,{ HS_Yi, EB_Wei },		false, true, FuMu,EB_Zi },	// ��س
		{ xxYin, ZiSun,{ HS_Yi, EB_Si },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Yi, EB_Mao },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },		true,  false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },		false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiShuiJie, "��ˮ��", WX_Mu, SecondXX, FiveXX,{
		{ xxYin, XiongDi,{ HS_Wu, EB_Yin },	  false, true, FuMu,EB_Zi },	// ��س
		{ xxYang, QiCai,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Wu },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ LeiFengHeng, "�׷��", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, true, XiongDi,EB_Yin },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ DiFengSheng, "�ط���", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },		false, true, XiongDi,EB_Yin },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },	true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Chou },		false, true, ZiSun,EB_Wu },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_Hai },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Gui, EB_You },	true, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShuiFengJing, "ˮ�羮", WX_Mu, FiveXX, SecondXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },		false, true, XiongDi,EB_Yin },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Wu, EB_Shen },	false, true, ZiSun,EB_Wu },	// ��س
		{ xxYang, QiCai,{ HS_Wu, EB_Xu },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Zi },			false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ ZeFengDaGuo, "�����", WX_Mu, FourXX, FirstXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, true, XiongDi,EB_Yin },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	 false, true, ZiSun,EB_Wu },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max}} },	// ��س

	{ ZeLeiSui, "������", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ding, EB_Hai },	 false, true, ZiSun,EB_Wu },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max}} },	// ��س

	{ XunWeiFeng, "��Ϊ��", WX_Mu, SixXX, ThirdXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si }, true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ FengTianXiaoChu, "����С��", WX_Mu, FirstXX, FourXX,{
		{ xxYang, FuMu,{ HS_Jia, EB_Zi },	  true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Jia, EB_Chen }, false, true, GuanGui,EB_You },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ FengHuoJiaRen, "������", WX_Mu, SecondXX, FiveXX,{
		{ xxYang, XiongDi,{ HS_Ji, EB_Mao },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ji, EB_Chou },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Ji, EB_Hai },		false, true, GuanGui,EB_You },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si },		false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	false, false, RelativeMax, EB_Max }}},	// ��س

	{ FengLeiYi, "������", WX_Mu, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, true, GuanGui,EB_You },	// ��س
		{ xxYin, QiCai,{ HS_Xin, EB_Wei },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Xin, EB_Si }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ TianLeiWuWang, "��������", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ren, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ren, EB_Xu },	 false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ HuoLeiShiKe, "�������", WX_Mu, FiveXX, SecondXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Ji, EB_Wei },	false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShanLeiYi, "ɽ����", WX_Mu, FourXX, FirstXX,{
		{ xxYang, FuMu,{ HS_Geng, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Geng, EB_Chen }, false, true, GuanGui,EB_You },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Zi },	false, true, ZiSun,EB_Si },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShanFengGu, "ɽ���", WX_Mu, ThirdXX, SixXX,{
		{ xxYin, QiCai,{ HS_Xin, EB_Chou },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Hai },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Bing, EB_Xu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Bing, EB_Zi }, false, true, ZiSun,EB_Si },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Yin },	 true, false, RelativeMax, EB_Max }}},	// ��س
	
	{ LiWeiHuo, "��Ϊ��", WX_Huo, SixXX, ThirdXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 true, false, RelativeMax, EB_Max}} },	// ��س

	{ HuoShanLv, "��ɽ��", WX_Huo, FirstXX, FourXX,{
		{ xxYin, ZiSun,{ HS_Bing, EB_Chen },	  false, true, FuMu,EB_Mao },	// ��س
		{ xxYin, XiongDi,{ HS_Bing, EB_Wu },  true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Bing, EB_Shen }, false, true, GuanGui,EB_Hai },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ HuoFengDing, "��綦", WX_Huo, SecondXX, FiveXX,{
		{ xxYin, ZiSun,{ HS_Xin, EB_Chou },	  true, true, FuMu,EB_Mao },	// ��س
		{ xxYang, GuanGui,{ HS_Xin, EB_Hai },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Xin, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ HuoShuiWeiJi, "��ˮδ��", WX_Huo, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu }, false, true, GuanGui,EB_Hai },	// ��س
		{ xxYang, QiCai,{ HS_Ji, EB_You },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Wei }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ji, EB_Si },	 false, false, RelativeMax, EB_Max}} },	// ��س
	
	{ ShanShuiMeng, "ɽˮ��", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Bing, EB_Xu },	 false, true, QiCai,EB_You },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Zi }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Bing, EB_Yin },	 false, false, RelativeMax, EB_Max}} },	// ��س

	{ FengShuiHuan, "��ˮ��", WX_Huo, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu }, false, true, GuanGui,EB_Hai },	// ��س
		{ xxYin, ZiSun,{ HS_Xin, EB_Wei },	 false, true, QiCai,EB_You },	// ��س
		{ xxYang, XiongDi,{ HS_Xin, EB_Si }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Xin, EB_Mao },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ TianShuiSong, "��ˮ��", WX_Huo, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Wu, EB_Wu }, false, true, GuanGui,EB_Hai },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ren, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ TianHuoTongRen, "���ͬ��", WX_Huo, ThirdXX, SixXX,{
		{ xxYang, FuMu,{ HS_Ji, EB_Mao },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Ji, EB_Chou },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ji, EB_Hai }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ren, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ren, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ren, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ KunWeiDi, "��Ϊ��", WX_Tu, SixXX, ThirdXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Yi, EB_Si },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ DiLeiFu, "���׸�", WX_Tu, FirstXX, FourXX,{
		{ xxYang, QiCai,{ HS_Geng, EB_Zi },	  true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Geng, EB_Yin },  false, true, FuMu,EB_Si },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max}} },	// ��س

	{ DiZeLin, "������", WX_Tu, SecondXX, FiveXX,{
		{ xxYang, FuMu,{ HS_Ding, EB_Si },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Chou }, true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ DiTianTai, "����̩", WX_Tu, ThirdXX, SixXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  true, true, FuMu,EB_Si },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiTianDaZhuang, "�����׳", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, FuMu,{ HS_Geng, EB_Wu },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeTianGuai, "�����", WX_Tu, FiveXX, SecondXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  false, true, FuMu,EB_Si },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max}} },	// ��س

	{ ShuiTianXu, "ˮ����", WX_Tu, FourXX, FirstXX,{
		{ xxYang, QiCai,{ HS_Jia, EB_Zi },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Jia, EB_Yin },  false, true, FuMu,EB_Si },	// ��س
		{ xxYang, XiongDi,{ HS_Jia, EB_Chen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ ShuiDiBi, "ˮ�ر�", WX_Tu, ThirdXX, SixXX,{
		{ xxYin, XiongDi,{ HS_Yi, EB_Wei },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Yi, EB_Si },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Mao }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Shen },	 true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Wu, EB_Zi },	 false, false, RelativeMax, EB_Max}}},	// ��س

	{ DuiWeiZe, "��Ϊ��", WX_Jin, SixXX, ThirdXX,{
		{ xxYang, GuanGui,{ HS_Ding, EB_Si },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Chou }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeShuiKun, "��ˮ��", WX_Jin, FirstXX, FourXX,{
		{ xxYin, FuMu,{ HS_Wu, EB_Yin },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Wu, EB_Chen },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Wu, EB_Wu }, true, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeDiCui, "�����", WX_Jin, SecondXX, FiveXX,{
		{ xxYin, FuMu,{ HS_Yi, EB_Wei },	  true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Yi, EB_Si },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, QiCai,{ HS_Yi, EB_Mao }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 true, false, RelativeMax, EB_Max }}},	// ��س

	{ ZeShanXian, "��ɽ��", WX_Jin, ThirdXX, SixXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, ZiSun,{ HS_Ding, EB_Hai },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Ding, EB_You }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Wei },	 false, false, RelativeMax, EB_Max }}},	// ��س
	
	{ ShuiShanJian, "ˮɽ�", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Wu, EB_Shen },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, XiongDi,{ HS_Wu, EB_Xu }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Wu, EB_Zi },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ DiShanQian, "��ɽǫ", WX_Jin, FiveXX, SecondXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Gui, EB_Chou },	 false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, ZiSun,{ HS_Gui, EB_Hai }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, XiongDi,{ HS_Gui, EB_You },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiShanXiaoGuo, "��ɽС��", WX_Jin, FourXX, FirstXX,{
		{ xxYin, FuMu,{ HS_Bing, EB_Chen },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, GuanGui,{ HS_Bing, EB_Wu },  false, true, QiCai,EB_Mao },	// ��س
		{ xxYang, XiongDi,{ HS_Bing, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	 false, true, ZiSun,EB_Hai },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}},	// ��س

	{ LeiZeGuiMei, "�������", WX_Jin, ThirdXX, SixXX,{
		{ xxYang, ZiSun,{ HS_Ding, EB_Si },	  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, QiCai,{ HS_Ding, EB_Mao },  false, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Ding, EB_Chou }, false, false, RelativeMax,EB_Max },	// ��س
		{ xxYang, GuanGui,{ HS_Geng, EB_Wu },	 false, true, ZiSun,EB_Hai },	// ��س
		{ xxYin, XiongDi,{ HS_Geng, EB_Shen }, true, false, RelativeMax,EB_Max },	// ��س
		{ xxYin, FuMu,{ HS_Geng, EB_Xu },	 false, false, RelativeMax, EB_Max }}}	// ��س
};



static WuXingProperty wxProperty[] = 
{
	{WX_Jin, "��"},
	{WX_Mu, "ľ"},
	{WX_Shui, "ˮ"},
	{WX_Huo, "��"},
	{WX_Tu, "��"}
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

static SixRelativeProperty srProperty[] = 
{
	{ FuMu , "��ĸ"},
	{ XiongDi , "�ֵ�"},
	{ GuanGui , "�ٹ�"},
	{ QiCai , "�޲�"},
	{ ZiSun , "����"}
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
	// ��ȡ��ǰ����Ѯ
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

