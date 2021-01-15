#include "Covid19.h"
#include "CovidGB.h"
#include "CovidSA.h"
#include "CovidKZ.h"
#include <iostream>

using namespace std;

int main()
{

	CovidKZ kz(1.2, 3, true, "ABCD", 2.3, "gb", 1.7, "sa", "TBCJA");

	kz.print();

	return 0;
}