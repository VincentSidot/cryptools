/*
This is sample programm to show you how to use Cryptools
*/
#include <iostream>
#include "menu.h"
#include "cryptools.h"
#include <io.h>
#include <fcntl.h>
#include <Windows.h>


#define currentalphabet ALPHABET::SPACEALL

using namespace std;

int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	//menu();
	
	
	//wstring start = L"Vincent le plus grand genie des mathematiques";
	wstring start = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ipsum dui, dignissim sit amet facilisis eget, aliquet pulvinar est. Morbi suscipit vehicula ultricies. Ut vitae lobortis felis. Aenean eu justo eu nisi blandit lobortis. Mauris venenatis dui in ex lobortis, eu auctor turpis ultricies. Ut sed nibh elementum, rutrum leo commodo, maximus purus. Duis vestibulum sed mauris eu aliquet. Integer ultrices a dolor ac dapibus. Mauris euismod feugiat risus, sed ultricies mauris iaculis at. Nam eleifend placerat lectus, sit amet semper magna finibus nec. Nullam a sollicitudin velit.\n\nCurabitur quam magna, malesuada ut enim id, ullamcorper ultrices ipsum.Vestibulum nec ullamcorper neque.Nunc sed velit congue, tempor magna in, feugiat nisi.Aenean at pretium urna.Integer at nisl sit amet tellus faucibus maximus et sed magna.Cras sodales, orci nec bibendum cursus, odio nisl vulputate est, eu venenatis sapien massa et lacus.In ut rhoncus diam, eu maximus ante.Aliquam ultrices est leo, id lacinia felis auctor ac.Integer tempus nisi non tempus blandit.Phasellus et tortor nisl.Nullam ultricies condimentum nunc, in vestibulum sem congue ut.Nunc pretium vitae libero vel auctor.Mauris bibendum diam libero.\n\nCras commodo arcu eget risus placerat, a vestibulum elit pellentesque.Donec euismod mi sit amet tellus ultrices, id tristique ante ornare.In sodales sed lacus eu hendrerit.Morbi interdum augue purus, ut placerat tortor rhoncus efficitur.Etiam interdum dolor et est consequat gravida.Aenean vel pulvinar elit.Praesent laoreet ante nibh, et congue nulla sagittis ut.\n\nAliquam malesuada eu velit vel ultricies.Praesent auctor venenatis ultricies.Curabitur sed feugiat dolor.Orci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.Proin non purus imperdiet, ullamcorper mauris ut, accumsan orci.Ut pretium, nisl sed blandit convallis, risus ex vulputate neque, vel blandit urna quam egestas nibh.Donec vitae pretium diam.Fusce molestie sit amet lorem eu pharetra.Quisque condimentum elementum arcu imperdiet malesuada.\n\nNunc laoreet pretium tortor, quis ultricies leo elementum id.Morbi quis tortor bibendum, egestas magna nec, accumsan ligula.Interdum et malesuada fames ac ante ipsum primis in faucibus.Suspendisse potenti.Nunc at tempus sapien.Praesent placerat, eros sed condimentum mattis, felis nisi laoreet lorem, dignissim bibendum massa urna eu augue.Proin luctus dapibus est, eget gravida ligula fringilla a.Etiam urna libero, sagittis posuere sapien non, venenatis iaculis dolor.Duis sit amet dolor sit amet metus scelerisque scelerisque.Pellentesque habitant morbi tristique senectus et netus et malesuada fames ac turpis egestas.Nam semper malesuada nunc ac porta.In hac habitasse platea dictumst.";
	
	DWORD64 time = GetTickCount64();
	wstring key = L"jetestsansespaces";
	wstring __new = Cryptools::LinearCongruentialGenerator(start,key, currentalphabet, MODE::CRYPT);
	wstring __old = Cryptools::LinearCongruentialGenerator(__new, key, currentalphabet,  MODE::UNCRYPT);
	wcout << L"Original : \n" << start << L"\n\n\n\n" << L"Chiffre : \n" << __new << L"\n\n\n\n" << L"Dechiffre : \n" << __old << endl;
	wcout << endl << endl << endl << "Time elapsed : " << (GetTickCount64() - time) << endl;

//	cout << string("DES RENFORTS ARRIVENT DE VIENNE NE PAS METTRE FIN AUX HOSTILITES").size() << " " << Cryptools::Bazeries("DES RENFORTS ARRIVENT DE VIENNE NE PAS METTRE FIN AUX HOSTILITES", "1789", ALPHABET::UPPER, MODE::CRYPT).size() << endl;
//	cout << Cryptools::Bazeries("DES RENFORTS ARRIVENT DE VIENNE NE PAS METTRE FIN AUX HOSTILITES", "1789", ALPHABET::UPPER, MODE::CRYPT) << endl;
	
	

	cin.ignore().get();
	return 0;
}


/*
int main()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	std::vector<wchar_t> dd;
	for (size_t i = 0;i<sALL.size();i++ )
	{
		bool test = true;
		for (auto &car : dd)
		{
			if (car == sALL[i])
			{
				test = false;
				break;
			}
		}
		if (test)
		{
			dd.push_back(sALL[i]);
		}
		else
		{
			wcout << "Error : " << sALL[i] << " - " << i << endl;
		}
	}
	cin.ignore().get();
	return 0;


}
*/