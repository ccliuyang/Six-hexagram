#pragma once

class DivineInfo;

/**
 * Ԥ����࣬�ṩ�ƽ�ߵ��㷨
*/
class DivinaBase
{
public:
	DivinaBase(DivineInfo* info);

	virtual ~DivinaBase();

protected:
	DivineInfo*	m_divinaInfo;

};

