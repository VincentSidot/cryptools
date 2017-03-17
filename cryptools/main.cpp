#include <iostream>
#include <string>
#include <sstream>
#include "cryptools.h"
using namespace std;





int main()
{
		char crep = 0;
	do
	{
		crep = 0;
		string input, output, key;
		MODE mode;
		ALPHABET alphabet = ALPHABET::SPACEALL;
		int rep = 0,rep2 = 0, ikey = 0;
		do
			{
				cout << "1-XOR\n2-Cesar\n3-Vignere\n4-PMS\nWich encryption would you use ?\n";
				cin >> rep;
			} while (!(rep <= 4 && rep >= 1));
			do
			{
				cout << "1-Crypt\n2-Uncrypt\nWhat would you want to do ?\n";
				cin >> rep2;
			} while (rep2 != 1 && rep2 != 2);
			mode = (rep2 == 1) ? MODE::CRYPT : MODE::UNCRYPT;
			cout << endl << "Enter string : ";
			cin.ignore();
			getline(cin, input);
			if (rep == 2)
			{
				cout << "Enter the key : ";
				cin >> ikey;
			}
			else
			{
				cout << "Enter passphrase : ";
				cin.ignore();
				getline(cin, key);
			}
			switch (rep)
			{
			case 1:
				output = Cryptools::XOR(input, key, alphabet, mode);
				break;
			case 2:
				output = Cryptools::Cesar(input, ikey, alphabet, mode);
				break;
			case 3:
				output = Cryptools::Vignere(input, key, alphabet, mode);
				break;
			case 4:
				output = Cryptools::PMS(input, key, alphabet, mode);
				break;
			default:
				output = "Error";
				break;
			}
			cout << "Output : " << output << endl;
			cout << "Continue (Y/N)\n";
			cin >> crep;
	} while (crep == 'Y');
	cin.ignore().get();
	return 0;
}