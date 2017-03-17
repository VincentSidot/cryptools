/*
Cryptools.h made by Vincent vs38190@gmail.com
Programme en acces libre mais priere de me demander si utilisation professionel
Program with free acces but you need to ask me before professional use
*/
#pragma once
#include <string>

#define elif else if

typedef enum Alphabet //type permettant de choisir quel alphabet utilisé
{
	ALL, NORMAL, NUMUPPER, NUMLOWER,UPPER,LOWER,SPACEALL
}ALPHABET,*PALPHABET;
typedef enum Mode //type permettant de choisir les mode
{
	CRYPT,UNCRYPT
}MODE,*PMODE;

//differents alphabet;
std::string sALL("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345789,?;\'\".:/!*-+\\=()_");
std::string sSPACEALL("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz012345789,\'\"?;.:/!*-+\\=()_ "); //pareil que celui d'avant sauf que les espaces sont eu aussi chiffré
std::string sNORMAL("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789");
std::string sNUMUPPER("ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789");
std::string sNUMLOWER("abcdefghijklmnopqrstuvwxyz0123456789");
std::string sUPPER("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
std::string sLOWER("abcdefghijklmnopqrstuvwxyz");

//si le caractere n'appartient pas a l'alphabet utilisé
const char unknowcar = 1;


class Cryptools
{
public:
	static inline std::string Vignere(std::string const &string, std::string const &key, ALPHABET const &alphabet = ALPHABET::ALL,MODE const &mode = MODE::CRYPT)
	{
		std::string ret = string; //pour le ret
		std::string *ptr = chooseAlphabet(alphabet); //permet de faire pointé ptr vers le bonne alphabet
		size_t i = 0; //compteur
		for (auto &car : ret)
		{
			car = to(car, alphabet); // permet de mettre les lettre en min/maj selon le choix de l'alphabet
			if (testcharacter(car, ptr)) //si le caractere appartient a l'alphabet
			{
				if(mode == MODE::CRYPT) //si on crypt
					car =(*ptr)[(getpos(car, ptr) + getpos(to(key[i % key.size()], alphabet), ptr)) % ptr->size()]; //gl&hf
				else // sinon
					car = (*ptr)[(ptr->size() + (getpos(car, ptr)) - getpos(to(key[i % key.size()], alphabet), ptr)) % ptr->size()]; //gl&hf

				i++; // on incremente i
			}
			elif(car != ' ') //sinon si le caratcere n'appartient pas mais n'est pas un escpace
			{
				car = unknowcar; //on le change
				i++; // on incremente i
			}
		}
		return ret; // on retourn la string
	}

	//POUR LES AUTRE MEME FONCTIONEMENT MAIS IL Y A JUSTE LA LIGNE PERMETTANT D'APPLIQUER L'ALGO QUI CHANGE correspond aux gl&hf d'au dessus
	static inline std::string PMS(std::string const &string, std::string const &key, ALPHABET const &alphabet = ALPHABET::ALL, MODE const &mode = MODE::CRYPT)
	{
		std::string ret = string;
		std::string *ptr = chooseAlphabet(alphabet);
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

				i++;
			}
			elif(car != ' ')
			{
				car = unknowcar;
				i++;
			}
		}
		return ret;
	}
	static inline std::string Cesar(std::string const &string, size_t key, ALPHABET const &alphabet = ALPHABET::ALL, MODE const &mode = MODE::CRYPT)
	{
		std::string ret = string;
		std::string *ptr = chooseAlphabet(alphabet);
		size_t i = 0;
		for (auto &car : ret)
		{
			car = to(car, alphabet);
			if (testcharacter(car, ptr))
			{
				if (mode == MODE::CRYPT)
					car = (*ptr)[(getpos(car, ptr) + key) % ptr->size()];
				else
					car = (*ptr)[(ptr->size() + (getpos(car, ptr)) - key ) % ptr->size()];
			}
			elif(car != ' ')
			{
				car = unknowcar;
			}
			i++;
		}
		return ret;
	}
	static inline std::string XOR(std::string const &string, std::string const &key, ALPHABET const &alphabet = ALPHABET::ALL, MODE const &mode = MODE::CRYPT)
	{
		std::string ret = string;
		std::string *ptr = chooseAlphabet(alphabet);
		size_t i = 0;
		for (auto &car : ret)
		{
			car = to(car, alphabet);
			if (testcharacter(car, ptr))
			{
				car = (*ptr)[(getpos(car, ptr) ^ getpos(to(key[i % key.size()], alphabet), ptr)) % ptr->size()];
				i++;
			}
			elif(car != ' ')
			{
				car = unknowcar;
				i++;
			}
		}
		return ret;
	}

private:
	static inline std::string* chooseAlphabet(ALPHABET const &alphabet)
	{
		switch (alphabet)
		{
		case ALPHABET::ALL:
			return &sALL;
			break;
		case ALPHABET::SPACEALL:
			return &sSPACEALL;
			break;
		case ALPHABET::UPPER:
			return &sUPPER;
			break;
		case ALPHABET::LOWER:
			return &sLOWER;
			break;
		case ALPHABET::NORMAL:
			return &sNORMAL;
			break;
		case ALPHABET::NUMLOWER:
			return &sNUMLOWER;
			break;
		case ALPHABET::NUMUPPER:
			return &sNUMUPPER;
			break;
		default:
			return &sALL;
			break;
		}
	}//permet de faire pointé ptr vers le bonne alphabet
	static inline char to(const char car,ALPHABET type)
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
	}// permet de mettre les lettre en min/maj selon le choix de l'alphabet
	static inline bool testcharacter(char const car,std::string *alphabet) //test le caratctere
	{
		//on boucle dans l'alphabet et on regarde si le caractere appartient a celui ci alors on retourne true
		for (auto &str : *alphabet)
		{
			if (car == str) return true; 
		}
		return false;
	}
	static inline size_t getpos(char car,std::string *alphabet) //permet de chopper la position du caractere dans l'alphabet
	{
		for (int i = 0; i < alphabet->size(); i++)
		{
			if (car == (*alphabet)[i]) return i;
		}
		return 0;
	}
};