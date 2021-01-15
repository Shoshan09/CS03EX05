#pragma warning(disable : 4996)
#include "CovidKZ.h"
#include <iostream>

using namespace std;

CovidKZ::CovidKZ() :
	m_geneticSequence(NULL)
{}

CovidKZ::CovidKZ(float R, int bio, bool vac, const char* serial, float lungFunction, const char* originGB, float liverFunc, const char* originSA, const char* genSeq) :
	Covid19(R, bio, vac, serial),
	CovidGB(R, bio, vac, serial, lungFunction, originGB),
	CovidSA(R, bio, vac, serial, liverFunc, originSA)
{
	m_geneticSequence = new char[strlen(genSeq) + 1];
	strcpy(m_geneticSequence, genSeq);
}

int CovidKZ::setGenSeq(const char* geneticSequence)
{
	if (geneticSequence == NULL)
		return -1;

	m_geneticSequence = new char[strlen(geneticSequence) + 1];
	strcpy(m_geneticSequence, geneticSequence);
	return 1;
}

char* CovidKZ::getGenSeq() 
{
	return m_geneticSequence;
}

void CovidKZ::print() 
{
	Covid19::print();
	cout << ", ";
	cout << "Lung Function " << CovidGB::getLungFunction() <<
		", country of origin GB virus: " << CovidGB::getOrigin() <<
		", liver function: " << CovidSA::getLiverFunction() << 
		", Country Of Origin SA Virus: " << CovidSA::getOrigin() <<
		", genetic sequence: " << m_geneticSequence << endl;
}
