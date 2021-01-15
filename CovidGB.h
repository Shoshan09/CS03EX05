#pragma once
#include "Covid19.h"

class CovidGB : virtual public Covid19
{
public:
	CovidGB();
	CovidGB(float R, int bio, bool vac, const char* serial, float lungFunction, const char* origin);
	~CovidGB() { delete[] m_origin; }

	int setLungFunction(float lungFunction);
	int setOrigin(const char* origin);

	float getLungFunction();
	char* getOrigin();

	void print();

private:
	float m_lungFunction;
	char* m_origin;
};
