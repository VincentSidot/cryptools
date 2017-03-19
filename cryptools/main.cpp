/*
This is sample programm to show you how to use Cryptools
*/
#include <iostream>
#include "menu.h"
#include "cryptools.h"

using namespace std;

int main()
{
	//menu();

	string start = "VINCENT LE GENIE DES MATHEMATIQUES", key = "9865";
	string __new = Cryptools::Bazeries(start,key, ALPHABET::NORMAL, MODE::CRYPT);
	string __old = Cryptools::Bazeries(__new, key, ALPHABET::NORMAL, MODE::UNCRYPT);
	cout << start << endl << __new << endl << __old << endl;
	

//	cout << string("DES RENFORTS ARRIVENT DE VIENNE NE PAS METTRE FIN AUX HOSTILITES").size() << " " << Cryptools::Bazeries("DES RENFORTS ARRIVENT DE VIENNE NE PAS METTRE FIN AUX HOSTILITES", "1789", ALPHABET::UPPER, MODE::CRYPT).size() << endl;
//	cout << Cryptools::Bazeries("DES RENFORTS ARRIVENT DE VIENNE NE PAS METTRE FIN AUX HOSTILITES", "1789", ALPHABET::UPPER, MODE::CRYPT) << endl;
	
	cin.ignore().get();
	return 0;
}