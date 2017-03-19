/*
Cryptools.h made by Vincent vs38190@gmail.com
Programme en acces libre mais priere de me demander si utilisation professionel
Program with free acces but you need to ask me before professional use
*/
#pragma once
#include <string>
#include <vector>

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
//const char uselesscar = 'X';


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
	static inline std::string VignereNumericalKey(std::string const &string, std::string const &numerical_key, ALPHABET const &alphabet = ALPHABET::ALL, MODE const &mode = MODE::CRYPT)
	{
		std::string key = fixkey(numerical_key);
		std::string ret = string; //pour le ret
		std::string *ptr = chooseAlphabet(alphabet); //permet de faire pointé ptr vers le bonne alphabet
		size_t i = 0; //compteur
		for (auto &car : ret)
		{
			car = to(car, alphabet); // permet de mettre les lettre en min/maj selon le choix de l'alphabet
			if (testcharacter(car, ptr)) //si le caractere appartient a l'alphabet
			{
				if (mode == MODE::CRYPT) //si on crypt
					car = (*ptr)[(getpos(car, ptr) + (key[i % key.size()] - '0')) % ptr->size()]; //gl&hf
				else // sinon
					car = (*ptr)[(ptr->size() + (getpos(car, ptr)) - (key[i % key.size()] - '0')) % ptr->size()]; //gl&hf

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
	static inline std::string Bazeries(std::string const &string, std::string const &numerical_key, ALPHABET const &alphabet = ALPHABET::ALL, MODE const &mode = MODE::CRYPT)
	{
		std::string key = fixkey(numerical_key);
		std::string *ptr = chooseAlphabet(alphabet);
		std::vector<std::string> string_reverse_vector;
		std::vector<size_t> fixed_string_space_pos;
		std::string fixed_string = fixstring(string, &fixed_string_space_pos);
		if(mode == MODE::UNCRYPT)
			fixed_string = Cryptools::VignereNumericalKey(fixed_string,key, alphabet, mode);
		{
			int i = 0, gapfixer = 0;
			bool cont = true;
			while (cont)
			{
				string_reverse_vector.push_back(std::string());
				for (int j = 0; j < (key[i%key.size()] - '0'); ++j)
				{

					if ((i + j + gapfixer) < fixed_string.size())
					{
						if (testcharacter(fixed_string[i + j + gapfixer], ptr))
							string_reverse_vector[i] += fixed_string[i + j + gapfixer];
						else
						{
							string_reverse_vector[i] += unknowcar;
						}
					}
					else
					{
						cont = false;	
						break;
					}
				}
				gapfixer += (key[i%key.size()] - '0' - 1 );
				i++;
			}
		}
		if (mode == MODE::CRYPT)
			return Cryptools::VignereNumericalKey(reverse(string_reverse_vector, fixed_string_space_pos), key, alphabet, mode);
		else
			return reverse(string_reverse_vector, fixed_string_space_pos);
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
		return car;
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
	static inline std::string fixkey(std::string const &key)
	{
		std::string rep;
		bool test = false;
		for (auto &i : key)
		{
			if (i <= '9' && i >= '0')
				rep += i;
			if (i != '0')
				test = true;
		}
		if (rep == "" || !test)
			return "1";
		return rep;
	}
	static inline std::string fixstring(std::string const &str, std::vector<size_t> *vector)
	{
		std::string rep;
		for (size_t i = 0; i < str.size(); i++)
		{
			if (str[i] == ' ')
			{
				vector->push_back(i);
			}
			else
			{
				rep += str[i];
			}
		}
		return rep;
	}
	static inline std::string reverse(std::vector<std::string> &vector,std::vector<size_t> space)
	{
		std::string rep;
		for (auto &i : vector)
		{
			rep += reverse_string(i);
		}
		for (auto &i : space)
		{
			rep.insert(rep.begin() + i, ' ');
		}
		return rep;
	}
	static inline std::string reverse_string(std::string const &str)
	{
		std::string rep(str);
		std::reverse(rep.begin(), rep.end());
		return rep;
	}

};