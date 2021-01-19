#pragma warning(disable : 4996)
#include "WHO.h"
#include "CovidKZ.h"
#include <iostream>

WHO::WHO():
	m_pandemicArray(NULL),
	m_arraySize(0),
	m_workCountry(NULL),
	m_totalPopulation(0),
	m_totalSick(0),
	m_differentViruses(0)
{}

WHO::WHO(const char* workCountry, int totalPop, int totalSick, int DiffViruse,Covid19** panArr,int size) :
	m_pandemicArray(panArr),
	m_arraySize(size),
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
	
	m_workCountry = new char[strlen(other.m_workCountry)+1];
	strcpy(m_workCountry, other.m_workCountry);

	m_arraySize = other.m_arraySize;
	m_differentViruses = other.m_differentViruses;
	m_totalPopulation = other.m_totalPopulation;
	m_totalSick = other.m_totalSick;

}

WHO::~WHO() 
{
	delete[] m_workCountry;
}

int WHO::setCovidArray(Covid19** panArray,int size)
{
	if (size == 0)
	{
		m_pandemicArray = NULL;
		return -1;
	}

	m_pandemicArray = new Covid19 * [size];
	m_arraySize = size;


	for (int i = 0; i < m_arraySize; i++)
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
	return 1;
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

void WHO::operator=(const WHO& other)
{
	if (other.m_pandemicArray == NULL)
		m_pandemicArray = NULL;
	else
	{
		setCovidArray(other.m_pandemicArray, other.m_arraySize);
	}

	setDiffViruses(other.m_differentViruses);
	setTotalPop(other.m_totalPopulation);
	setTotalSick(other.m_totalSick);
	setWorkCountry(m_workCountry);
}


Covid19** WHO::addToArray(Covid19* cov19)
{
	int size = m_arraySize;;
	
	if (typeid(cov19) == typeid(Covid19))
	{
		m_pandemicArray[size] = new Covid19(*cov19);
	}
	if (typeid(cov19) == typeid(CovidGB))
	{
		CovidGB* cov = dynamic_cast<CovidGB*>(cov19);
		m_pandemicArray[size] = new CovidGB(*cov);
	}
	if (typeid(m_pandemicArray[size]) == typeid(CovidSA))
	{
		CovidSA* cov = dynamic_cast<CovidSA*>(cov19);
		m_pandemicArray[size] = new CovidSA(*cov);

	}
	else if (typeid(m_pandemicArray[size]) == typeid(CovidKZ))
	{
		CovidKZ* cov = dynamic_cast<CovidKZ*>(cov19);
		m_pandemicArray[size] = new CovidKZ(*cov);
	}

	m_arraySize++;
	m_pandemicArray[m_arraySize] = NULL;
	return m_pandemicArray;
}


int WHO::changeKZGenSeq(int index, const char* genSeq)
{
	if (typeid(*m_pandemicArray[index]) == typeid(CovidGB))
	{
		cout << "unable to change code CovidSA does not support\n";
		return -1;
	}

	if (typeid(*m_pandemicArray[index]) == typeid(CovidSA))
	{
		cout << "unable to change code CovidSA does not support\n";
		return -1;
	}

	else if (typeid(*m_pandemicArray[index]) == typeid(CovidKZ))
	{
		CovidKZ* Z = dynamic_cast<CovidKZ*>(m_pandemicArray[index]);
		Z->setGenSeq(genSeq);
		m_pandemicArray[index] = new CovidKZ(*Z);
		cout << "Genetic sequance changed succefully\n";
	}
	return 1;
}

void WHO::print()
{
	for (int i = 0; i < m_arraySize; i++)
	{
		if (typeid(*m_pandemicArray[i]) == typeid(Covid19))
		m_pandemicArray[i]->print();

		cout << "\n";

		if (typeid(*m_pandemicArray[i]) == typeid(CovidGB))
		{
			CovidGB* cov = dynamic_cast<CovidGB*>(m_pandemicArray[i]);
			cov->print();
		}

		cout << "\n";

		if (typeid(*m_pandemicArray[i]) == typeid(CovidSA))
		{
			CovidSA* cov = dynamic_cast<CovidSA*>(m_pandemicArray[i]);
			cov->print();
		}

		cout << "\n";

		if (typeid(*m_pandemicArray[i]) == typeid(CovidKZ))
		{
			CovidKZ* cov = dynamic_cast<CovidKZ*>(m_pandemicArray[i]);
			cov->print();
		}

		cout << "\n";
	}

	cout << "Work country: " << getCountry() << ", " <<
		"Different Viruses: " << getDiffViruses() << ", " <<
		"total population: " << getTotalPop() << ", " <<
		"total sick: " << getTotalSick() << endl;
}

ostream& operator<<(ostream& os, WHO& who)
{
	who.print();
	return os;
}

