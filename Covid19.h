#pragma once
#include <string>

class Covid19
{
public:
	Covid19();
	Covid19(float R, int bio, bool vac, const char* serial);
	~Covid19() { delete[] m_serial; }

	float setR(float R);
	int setMoleculeNum(int bioMoleculeNum);
	int setVaccine(bool Vaccine = false);
	int setSerial(const char* serial);

	float getR();
	int getMoleculeNum();
	bool getVaccine();
	char* getSerial();

	void print();

private:
	float m_R;
	int m_bioMoleculeNum;
	bool m_vaccine;
	char* m_serial[20];
};
