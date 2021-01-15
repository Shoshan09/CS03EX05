#pragma warning(disable : 4996)
#include "Covid19.h"
#include <iostream>
#include <string>

using namespace std;

Covid19::Covid19() 
{
	m_R = 0;
	m_bioMoleculeNum = 0;
	m_vaccine = false;
	m_serial = NULL;
}

Covid19::Covid19(float R, int bio, bool vac, const char* serial)
{
	m_R = R;
	m_bioMoleculeNum = bio;
	m_vaccine = vac;
	m_serial = new char[strlen(serial) + 1];
	strcpy(m_serial, serial);
}

float Covid19::setR(float R)
{
	if (R == 0)
		return -1;
	m_R = R;
	return 1;
}

int Covid19::setMoleculeNum(int bioMoleculeNum)
{
	if (bioMoleculeNum == 0)
		return -1;
	m_bioMoleculeNum = bioMoleculeNum;
	return 1;
}

int Covid19::setVaccine(bool vaccine)
{
	m_vaccine = vaccine;
	return 1;
}

int Covid19::setSerial(const char* serial)
{
	if (serial == NULL)
		return -1;
	m_serial = new char[strlen(serial + 1)];
	strcpy(m_serial, serial);
	return 1;
}

float Covid19::getR() 
{
	return m_R;
}

int Covid19::getMoleculeNum()
{
	return m_bioMoleculeNum;
}

bool Covid19::getVaccine()
{
	return m_vaccine;
}

char* Covid19::getSerial()
{
	return m_serial;
}

void Covid19::print()
{
	cout << "R is: " << m_R << ", " << "serial is:" << m_serial << ", " << "vaccine?: " << m_vaccine << ", " << "Molecule Number: " << m_bioMoleculeNum;
}