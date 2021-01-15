#pragma once
#include <iostream>
#include "CovidGB.h"
#include "CovidSA.h"
#include "CovidKZ.h"

using namespace std;

class WHO
{
public:
	WHO();
	WHO(Covid19** panArray, const char* workCountry, int totalPop, int totalSick, int DiffViruse);
	WHO(const WHO& other);
	~WHO();
	
	int setCovidArray(Covid** panArray);
	int setWorkCountry(const char* workCountry);
	int setTotalPop(int totalPop);
	int setTotalSick(int totalSick);
	int setDiffViruses(int DiffViruses);

	char* getCountry();
	int getTotalPop();
	int getTotalSick();
	int getDiffViruses();

	int countViruses(); //functinon to count number of different viruses in the country and change the variable m_differentViruses accordingly
	int changeKZGenSeq(const char* genSeq);

	void operator=(const WHO& other);
	friend ostream& operator<<(ostream& os, const WHO& who);


private:
	Covid19** m_pandemicArray;
	char* m_workCountry;
	int m_totalPopulation;
	int m_totalSick;
	int m_differentViruses;
};