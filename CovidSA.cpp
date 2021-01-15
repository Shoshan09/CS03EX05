#pragma warning(disable : 4996)
#include "CovidSA.h"
#include <iostream>

using namespace std;

CovidSA::CovidSA()
{
	m_liverFunction = 0;
	m_origin = NULL;
}

CovidSA::CovidSA(float R, int bio, bool vac, const char* serial, float liverFunc, const char* origin) :
	Covid19(R,bio,vac,serial),
	m_liverFunction(liverFunc)
{
	m_origin = new char[strlen(origin) + 1];
	strcpy(m_origin, origin);
}


int CovidSA::setLiverFunction(float liverFunction)
{
	if (liverFunction < 0)
		return -1;

	m_liverFunction = liverFunction;
	return 1;
}

int CovidSA::setOrigin(const char* origin) 
{
	if (origin == NULL)
		return -1;

	m_origin = new char[strlen(origin) + 1];
	strcpy(m_origin, origin);
	return 1;
}

float CovidSA::getLiverFunction()
{
	return m_liverFunction;
}
char* CovidSA::getOrigin() 
{
	return m_origin;
}

void CovidSA::print()
{
	Covid19::print();
	cout << " ";
	cout << "liver functions: " << m_liverFunction << ", " << "country of origin: " << m_origin;
}