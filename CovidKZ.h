#pragma once
#include "CovidGB.h"
#include "CovidSA.h"

class CovidKZ : public CovidGB, public CovidSA
{
public:
	CovidKZ();
	CovidKZ(float R, int bio, bool vac, const char* serial, float lungFunction, const char* originGB, float liverFunc, const char* originSA, const char* genSeq);
	~CovidKZ() { delete[] m_geneticSequence; }

	int setGenSeq(const char* geneticSequence);

	char* getGenSeq();

	void print();

private:
	char* m_geneticSequence;
};
