#pragma warning(disable : 4996)
#include "WHO.h"
#include "CovidKZ.h"
#include <iostream>

WHO::WHO():
	m_pandemicArray(NULL),
	m_workCountry(NULL),
	m_totalPopulation(0),
	m_totalSick(0),
	m_differentViruses(0)
{}

WHO::WHO(const char* workCountry, int totalPop, int totalSick, int DiffViruse) :
	m_totalPopulation(totalPop),
	m_totalSick(totalSick),
	m_differentViruses(DiffViruse)
{
	if (workCountry == NULL)
		m_workCountry = NULL;
	else
	{
		m_workCountry = new char[strlen(workCountry) + 1];
		strcpy(m_workCountry, workCountry);
	}
}

WHO::WHO(const WHO& other)
{
	if (other.m_pandemicArray == NULL)
		m_pandemicArray = NULL;
	else
	{
		setCovidArray(other.m_pandemicArray, other.m_arraySize);
	}

	m_differentViruses = other.m_differentViruses;
	m_totalPopulation = other.m_totalPopulation;
	m_totalSick = other.m_totalSick;
}

WHO::~WHO() {}

int WHO::setCovidArray(Covid19** panArray,int size)
{
	m_pandemicArray = new Covid19 * [size];
	m_arraySize = size;


	for (int i = 0; i < size; i++)
	{
		if (typeid(*panArray[i]) == typeid(Covid19))
		{
			Covid19* cov = dynamic_cast<Covid19*>(panArray[i]);
			m_pandemicArray[i] = new Covid19(*cov);
		}

		if (typeid(*panArray[i]) == typeid(CovidGB))
		{
			CovidGB* cov = dynamic_cast<CovidGB*>(panArray[i]);
			m_pandemicArray[i] = new CovidGB(*cov);
		}

		if (typeid(*panArray[i]) == typeid(CovidSA))
		{
			CovidSA* cov = dynamic_cast<CovidSA*>(panArray[i]);
			m_pandemicArray[i] = new CovidSA(*cov);
		}

		if (typeid(*panArray[i]) == typeid(CovidKZ))
		{
			CovidKZ* cov = dynamic_cast<CovidKZ*>(panArray[i]);
			m_pandemicArray[i] = new CovidKZ(*cov);
		}
	}
}


int WHO::setWorkCountry(const char* workCountry) 
{
	if (workCountry == NULL)
		return -1;

	m_workCountry = new char[strlen(workCountry) + 1];
	strcpy(m_workCountry, workCountry);
	return 1;
}

int WHO::setTotalPop(int totalPop)
{
	m_totalPopulation = totalPop;
	return 1;
}

int WHO::setTotalSick(int totalSick)
{
	m_totalSick = totalSick;
	return 1;
}
int WHO::setDiffViruses(int DiffViruses)
{
	m_differentViruses = DiffViruses;
	return 1;
}

char* WHO::getCountry()
{
	return m_workCountry;
}
int WHO::getTotalPop() 
{
	return m_totalPopulation;
}

int WHO::getTotalSick() 
{
	return m_totalSick;
}
int WHO::getDiffViruses()
{
	return m_differentViruses;
}

Covid19** WHO::getPandemicArray()
{
	return m_pandemicArray;
}

//functinon to count number of different viruses in the country and change the variable m_differentViruses accordingly
int WHO::countViruses() 
{
	if (m_arraySize == 0)
		return -1;

	int count = 0;
	for (int i = 0; i < m_arraySize; i++)
	{
		//strcmp return 0 if both string are equal, if not equal than we count them
		if (strcmp(m_pandemicArray[i]->getSerial(), m_pandemicArray[i + 1]->getSerial()) != 0)
			count++;
	}
	this->setDiffViruses(count);
	return 1;
} 

Covid19** WHO::addToArray(Covid19 cov)
{}


int WHO::changeKZGenSeq(int index, const char* genSeq)
{
	if (typeid(m_pandemicArray[index]) == typeid(CovidGB))
	{
		cout << "unable to change code CovidGB does not support";
		return -1;
	}

	if (typeid(m_pandemicArray[index]) == typeid(CovidSA))
	{
		cout << "unable to change code CovidSA does not support";
		return -1;
	}

	if (typeid(m_pandemicArray[index]) == typeid(CovidKZ))
	{
		CovidKZ cov = dynamic_cast<Covid19*>(m_pandemicArray[index]);
	}
}

void WHO::operator=(const WHO& other)
{

}

void WHO::print()
{
	for (int i = 0; i <= sizeof(m_pandemicArray); i++)
	{
		if (typeid(m_pandemicArray[i]) == typeid(Covid19))
		{
			m_pandemicArray[i]->print();
		}

		if (typeid(m_pandemicArray[i]) == typeid(CovidGB))
		{
			
		}
	}
}

ostream& operator<<(ostream& os, WHO& who)
{
	who.print();
	return os;
}

