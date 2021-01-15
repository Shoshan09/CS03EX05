#pragma once
#include "Covid19.h"

class CovidGB : public Covid19
{
public:
	CovidGB();
	CovidGB(float lungFunction, const char* origin);
	~CovidGB() { delete[] m_origin }

	int setLungFunction(float lungFunction);
	int setOrigin(const char* origin);

	float getLungFunction();
	char* getOrigin();

	void print();

private:
	float m_lungFunction;
	char* m_origin;
};