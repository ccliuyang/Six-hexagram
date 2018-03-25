#pragma once

class DivineInfo;

/**
 * 预测基类，提供黄金策的算法
*/
class DivinaBase
{
public:
	DivinaBase(DivineInfo* info);

	virtual ~DivinaBase();

protected:
	DivineInfo*	m_divinaInfo;

};

