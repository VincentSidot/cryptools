#include <iostream>
#include "cryptools.h"
using namespace std;


int main()
{
	string temp = "BITS DE SIGNES";
	string crypt = Cryptools::PMS(temp, "PFS", ALPHABET::UPPER, MODE::CRYPT);
	string uncrypt = Cryptools::PMS(crypt, "PFS", ALPHABET::UPPER, MODE::UNCRYPT);
	cout << crypt << endl << uncrypt << endl;
	

	cin.ignore().get();
	return 0;
}