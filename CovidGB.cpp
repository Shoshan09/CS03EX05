#pragma warning(disable : 4996)
#include "CovidGB.h"
#include <iostream>

using namespace std;

CovidGB::CovidGB() 
{
	m_lungFunction = 0;
	m_origin = NULL;
}

CovidGB::CovidGB(float R, int bio, bool vac, const char* serial, float lungFunction, const char* origin) :
	Covid19(R,bio,vac,serial),
	m_lungFunction(lungFunction)
{
	m_origin = new char[strlen(origin) + 1];
	strcpy(m_origin, origin);
}

int CovidGB::setLungFunction(float lungFunction)
{
	if (lungFunction < 0)
		return -1;

	m_lungFunction = lungFunction;
	return 1;
}

int CovidGB::setOrigin(const char* origin)
{
	if (origin == NULL)
		return -1;

	m_origin = new char[strlen(origin) + 1];
	strcpy(m_origin, origin);
	return 1;
}

float CovidGB::getLungFunction()
{
	return m_lungFunction;
}

char* CovidGB::getOrigin()
{
	return m_origin;
}

void CovidGB::print()
{
	Covid19::print();
	cout << " ";
	cout << "lung functions: " << m_lungFunction << ", " << "country of origin: " << m_origin;
}