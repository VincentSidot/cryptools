#pragma once
#include <string>

#define elif else if

typedef enum Alphabet
{
	ALL, NORMAL, NUMUPPER, NUMLOWER,UPPER,LOWER,SPACEALL
}ALPHABET,*PALPHABET;
typedef enum Mode
{
	CRYPT,UNCRYPT
}MODE,*PMODE;

std::string sALL("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345789,?;.:/!*-+\\=()_");
std::string sSPACEALL("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345789,?;.:/!*-+\\=()_ ");
std::string sNORMAL("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
std::string sNUMUPPER("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
std::string sNUMLOWER("abcdefghijklmnopqrstuvwxyz0123456789");
std::string sUPPER("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string sLOWER("abcdefghijklmnopqrstuvwxyz");

const char unknowcar = '?';


class Cryptools
{
public:
	static std::string Vignere(std::string const &string, std::string const &key, ALPHABET const &alphabet = ALPHABET::ALL,MODE const &mode = MODE::CRYPT)
	{
		std::string ret = string;
		std::string *ptr = NULL;
		switch(alphabet)
		{
		case ALPHABET::ALL:
			ptr = &sALL;
			break;
		case ALPHABET::SPACEALL:
			ptr = &sSPACEALL;
			break;
		case ALPHABET::UPPER:
			ptr = &sUPPER;
			break;
		case ALPHABET::LOWER:
			ptr = &sLOWER;
			break;
		case ALPHABET::NORMAL:
			ptr = &sNORMAL;
			break;
		case ALPHABET::NUMLOWER:
			ptr = &sNUMLOWER;
			break;
		case ALPHABET::NUMUPPER:
			ptr = &sNUMUPPER;
			break;
		default:
			ptr = &sALL;
			break;
		}
		size_t i = 0;
		for (auto &car : ret)
		{
			car = to(car, alphabet);
			if (testcharacter(car, ptr))
			{
				if(mode == MODE::CRYPT)
					car =(*ptr)[(getpos(car, ptr) + getpos(to(key[i % key.size()], alphabet), ptr)) % ptr->size()];
				else
					car = (*ptr)[(ptr->size() + (getpos(car, ptr)) - getpos(to(key[i % key.size()], alphabet), ptr)) % ptr->size()];
			}
			elif(car != ' ')
			{
				car = unknowcar;
			}
			i++;
		}
		return ret;
	}
	static std::string PMS(std::string const &string, std::string const &key, ALPHABET const &alphabet = ALPHABET::ALL, MODE const &mode = MODE::CRYPT)
	{
		std::string ret = string;
		std::string *ptr = NULL;
		switch (alphabet)
		{
		case ALPHABET::ALL:
			ptr = &sALL;
			break;
		case ALPHABET::SPACEALL:
			ptr = &sSPACEALL;
			break;
		case ALPHABET::UPPER:
			ptr = &sUPPER;
			break;
		case ALPHABET::LOWER:
			ptr = &sLOWER;
			break;
		case ALPHABET::NORMAL:
			ptr = &sNORMAL;
			break;
		case ALPHABET::NUMLOWER:
			ptr = &sNUMLOWER;
			break;
		case ALPHABET::NUMUPPER:
			ptr = &sNUMUPPER;
			break;
		default:
			ptr = &sALL;
			break;
		}
		size_t i = 0;
		for (auto &car : ret)
		{
			car = to(car, alphabet);
			if (testcharacter(car, ptr))
			{
				if (mode == MODE::CRYPT)
					car = (*ptr)[(getpos(car, ptr) + (getpos(to(key[i % key.size()], alphabet), ptr)*(i+1))) % ptr->size()];
				else
					car = (*ptr)[( (ptr->size() * (i+1)) + (getpos(car, ptr)) - (getpos(to(key[i % key.size()], alphabet), ptr)*(i + 1))) % ptr->size()];
			}
			elif(car != ' ')
			{
				car = unknowcar;
			}
			i++;
		}
		return ret;
	}

private:
	static char to(const char car,ALPHABET type)
	{
		switch (type)
		{
		case ALPHABET::NUMLOWER:
			if (car <= '0' && car >= '9' && car >= 'A' && car <= 'Z')
				return (car - 'A') + 'a';
			else
				return car;
			break;
		case ALPHABET::NUMUPPER:
			if (car <= '0' && car >= '9' && car >= 'a' && car <= 'z')
				return (car - 'a') + 'A';
			else
				return car;
			break;
		case ALPHABET::LOWER:
			if(car >= 'A' && car <= 'Z')
				return (car - 'A') + 'a';
			break;
		case ALPHABET::UPPER:
			if(car >= 'a' && car <= 'z')
				return (car - 'a') + 'A';
			break;
		default:
			return car;
			break;
		}
	}
	static bool testcharacter(char const car,std::string *alphabet)
	{
		for (auto &str : *alphabet)
		{
			if (car == str) return true;
		}
		return false;
	}
	static size_t getpos(char car,std::string *alphabet)
	{
		for (int i = 0; i < alphabet->size(); i++)
		{
			if (car == (*alphabet)[i]) return i;
		}
		return 0;
	}
};