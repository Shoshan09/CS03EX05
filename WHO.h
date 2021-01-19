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
	WHO(const char* workCountry, int totalPop, int totalSick, int DiffViruse, Covid19** panArr, int size);
	WHO(const WHO& other);
	~WHO();
	
	//setters
	int setCovidArray(Covid19** panArray, int size);
	int setWorkCountry(const char* workCountry);
	int setTotalPop(int totalPop);
	int setTotalSick(int totalSick);
	int setDiffViruses(int DiffViruses);

	//getters
	char* getCountry();
	int getTotalPop();
	int getTotalSick();
	int getDiffViruses();
	Covid19** getPandemicArray();

	//different functions
	Covid19** addToArray(Covid19* cov);
	int countViruses(); //functinon to count number of different viruses in the country and change the variable m_differentViruses accordingly
	int changeKZGenSeq(int index, const char* genSeq);

	void print();
	void operator=(const WHO& other);
	friend ostream& operator<<(ostream& os, const WHO& who);


private:
	Covid19** m_pandemicArray;
	int m_arraySize;
	char* m_workCountry;
	int m_totalPopulation;
	int m_totalSick;
	int m_differentViruses;
};
