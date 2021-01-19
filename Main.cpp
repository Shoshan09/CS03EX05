#include "WHO.h"
#include <iostream>

using namespace std;

int main()
{

	Covid19 co19(2.2, 4, true, "fkal");
	CovidGB gb(1.5, 4, false, "defg", 3.5, "BUTSWANA");
	CovidSA sa(3.1, 415, false, "ADDQD", 8.1, "Cape Verde");
	CovidKZ kz(1.2, 3, true, "ABCD", 2.3, "PALMA", 1.7, "sa", "DGGD");

	Covid19* cov[4];
	
	cov[0] = new Covid19(co19);
	cov[1] = new CovidGB(gb);
	cov[2] = new CovidKZ(kz);
	cov[3] = new CovidSA(sa);
	
	
	//initilzing WHO class
	WHO w("Butswana", 1500, 400, 2, cov, 4);

	//printing before KZ genetic sequance change
	w.print();

	//tyring to change - not working
	w.changeKZGenSeq(1,"ABABA");

	//trying to change - working
	w.changeKZGenSeq(2, "ABABA");

	//printing after change
	cout << "\n";
	w.print();

	return 0;
}
