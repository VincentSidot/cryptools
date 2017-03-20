#pragma once
/*
This is sample menu programm to show you how to use Cryptools
Write by Vincent
*/
#include <iostream>
#include <string>
#include "cryptools.h"

//using namespace std;
void menu()
{
	char crep = 0;
	do
	{
		crep = 0;
		std::wstring input, output, key;
		MODE mode;
		ALPHABET alphabet = ALPHABET::SPACEALL;
		int rep = 0, rep2 = 0, ikey = 0;
		do
		{
			std::wcout << L"1-XOR\n2-Cesar\n3-Vignere\n4-PMS\nWich encryption would you use ?\n";
			std::cin >> rep;
		} while (!(rep <= 4 && rep >= 1));
		do
		{
			std::wcout << L"1-Crypt\n2-Uncrypt\nWhat would you want to do ?\n";
			std::cin >> rep2;
		} while (rep2 != 1 && rep2 != 2);
		mode = (rep2 == 1) ? MODE::CRYPT : MODE::UNCRYPT;
		std::wcout << std::endl << "Enter wstring : ";
		std::cin.ignore();
		std::getline(std::wcin, input);
		if (rep == 2)
		{
			std::wcout << L"Enter the key : ";
			std::cin >> ikey;
		}
		else
		{
			std::wcout << L"Enter passphrase : ";
			std::cin.ignore();
			std::getline(std::wcin, key);
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
			output = L"Error";
			break;
		}
		std::wcout << L"Output : " << output << std::endl;
		std::wcout << L"Continue (Y/N)\n";
		std::cin >> crep;
	} while (crep == 'Y');
}
