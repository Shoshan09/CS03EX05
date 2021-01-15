#pragma once
#include "CovidGB.h"
#include "CovidSA.h"

class CovidKZ : public virtual CovidGB, public virtual CovidSA
{
public:
	CovidKZ();
	CovidKZ(const char* genSeq);
	~CovidKZ() { delete[] m_geneticSequence; }

	int setGenSeq(const char* geneticSequence);

	char* getGenSeq();

	void print();

private:
	char* m_geneticSequence[20];
};
