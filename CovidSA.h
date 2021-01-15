#pragma once
#include "Covid19.h"

class CovidSA : public Covid19
{
public:
	CovidSA();
	CovidSA(float liverFunc, const char* origin);
	~CovidSA() { delete[] m_origin; }

	int setLiverFunction(float liverFunction);
	int setOrigin(const char* origin);

	float getLiverFunction();
	char* getOrigin();

	void print();

private:
	float m_liverFunction;
	char* m_origin
};
