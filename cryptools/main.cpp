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
	//wstring start = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Donec ipsum dui, dignissim sit amet facilisis eget, aliquet pulvinar est. Morbi suscipit vehicula ultricies. Ut vitae lobortis felis. Aenean eu justo eu nisi blandit lobortis. Mauris venenatis dui in ex lobortis, eu auctor turpis ultricies. Ut sed nibh elementum, rutrum leo commodo, maximus purus. Duis vestibulum sed mauris eu aliquet. Integer ultrices a dolor ac dapibus. Mauris euismod feugiat risus, sed ultricies mauris iaculis at. Nam eleifend placerat lectus, sit amet semper magna finibus nec. Nullam a sollicitudin velit.\n\nCurabitur quam magna, malesuada ut enim id, ullamcorper ultrices ipsum. Vestibulum nec ullamcorper neque. Nunc sed velit congue, tempor magna in, feugiat nisi. Aenean at pretium urna. Integer at nisl sit amet tellus faucibus maximus et sed magna. Cras sodales, orci nec bibendum cursus, odio nisl vulputate est, eu venenatis sapien massa et lacus. In ut rhoncus diam, eu maximus ante. Aliquam ultrices est leo, id lacinia felis auctor ac. Integer tempus nisi non tempus blandit. Phasellus et tortor nisl. Nullam ultricies condimentum nunc, in vestibulum sem congue ut. Nunc pretium vitae libero vel auctor. Mauris bibendum diam libero.";
	
	wstring start = L"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Ut mollis ac risus ac sodales. Quisque rutrum, nisl nec pharetra semper, tortor enim accumsan augue, ac ultricies ex mauris in diam. Proin eget tellus gravida, maximus libero in, commodo odio. Donec mauris lectus, porttitor ac feugiat quis, vulputate id tortor. Aliquam erat volutpat. Aenean commodo augue in nisl euismod consequat. Quisque laoreet nec tortor ut vulputate. Duis posuere rutrum nibh, sit amet commodo massa vehicula vel. Aliquam eleifend convallis est, at feugiat enim ornare porttitor. Sed varius risus posuere nisi aliquam convallis. Ut in laoreet nibh. Proin massa dolor, vestibulum non urna vel, pellentesque commodo nisl. Sed sed leo ultricies, pulvinar dolor a, pellentesque magna. Sed accumsan est ut augue dapibus rutrum. Integer scelerisque lobortis enim, in mollis velit lobortis eget. Aliquam sit amet tortor turpis.\n\nPraesent viverra nibh id elementum dignissim.Suspendisse potenti.Curabitur sit amet eros a ligula auctor cursus ac a tellus.Donec ac dolor vel erat fringilla euismod.Ut lacinia enim sed porttitor dapibus.Lorem ipsum dolor sit amet, consectetur adipiscing elit.Curabitur vulputate tortor ac posuere tempus.In venenatis maximus pretium.Maecenas laoreet sodales ex, eu tincidunt nulla condimentum sit amet.Maecenas ut porta nunc, in tempor felis.Nam rhoncus magna eu pellentesque pretium.\n\nVestibulum eget ante viverra, tincidunt tortor sit amet, iaculis neque.Quisque faucibus risus commodo velit aliquam tincidunt.Pellentesque vestibulum sollicitudin varius.Pellentesque eu elementum dolor, at mattis felis.Morbi mollis leo vitae dui rutrum, eget vulputate leo molestie.Nunc at tellus et sem blandit consequat.Sed erat elit, molestie at elementum vel, porta in ligula.Nunc pharetra molestie magna, vitae sollicitudin mauris aliquet vitae.Quisque sit amet neque in orci gravida sagittis aliquet eget ante.Nam erat nulla, consequat eget viverra non, vestibulum ac neque.Suspendisse feugiat, metus at gravida tristique, neque diam consequat arcu, in dictum turpis ex id mauris.Fusce sollicitudin lacinia quam at semper.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae; Quisque rutrum risus orci, euismod molestie enim blandit eu.Phasellus eu scelerisque justo, id venenatis sapien.Pellentesque ut dui et felis finibus laoreet.\n\nPraesent leo felis, fringilla ac quam non, sagittis ultrices tellus.Proin varius tellus in sem tincidunt, non maximus dolor venenatis.Etiam porttitor urna eros.Sed blandit elit a dolor laoreet, eu dapibus felis cursus.Suspendisse maximus risus sit amet ipsum convallis porttitor.Sed et sagittis ligula.Mauris quis posuere felis.Vestibulum mauris odio, commodo vel lectus ac, tristique tincidunt ex.Sed augue purus, aliquet quis nulla nec, ullamcorper commodo ipsum.Duis a blandit felis.Maecenas finibus nunc at vehicula euismod.In imperdiet in felis et varius.Vestibulum ante ipsum primis in faucibus orci luctus et ultrices posuere cubilia Curae;\n\nCurabitur faucibus mi non nunc luctus ullamcorper.Sed porta dictum volutpat.Aliquam erat volutpat.Proin tempus nibh quis nibh fermentum congue.Vestibulum at leo commodo nisl malesuada efficitur volutpat id nisi.Praesent sem leo, volutpat vitae ullamcorper quis, scelerisque ac eros.Curabitur commodo, sem sed viverra volutpat, massa enim ultrices nisi, a fermentum mi turpis sit amet sem.\n\nInteger neque velit, scelerisque at nisl non, porttitor tempus arcu.Etiam in nibh laoreet, molestie diam sit amet, tempor urna.In hac habitasse platea dictumst.Cras bibendum augue ut nunc elementum malesuada.Donec eu nisl a lorem condimentum convallis eu non felis.Integer sit amet lectus erat.Cras finibus, dolor id mollis pretium, augue augue ullamcorper ex, ut lobortis magna enim nec mauris.Quisque in neque ligula.Nulla porta est orci, non tincidunt urna dignissim sed.Suspendisse fringilla mauris mauris, sit amet tincidunt lectus aliquam non.Aliquam sagittis quam vel elementum sagittis.Quisque rhoncus arcu et justo consequat mattis.Etiam sodales fermentum orci, ac hendrerit erat iaculis iaculis.Proin nec felis sit amet ipsum semper convallis.Aliquam facilisis vel ante id ullamcorper.Nam nec dui nisi.\n\nUt scelerisque nunc lobortis arcu rutrum, a pharetra quam venenatis.Etiam elementum arcu cursus purus volutpat, et ultrices massa dapibus.Nunc dignissim eros eget aliquam scelerisque.Proin quis dui neque.Aliquam molestie est augue, vel maximus neque laoreet ut.Etiam at velit orci.Integer ac ipsum velit.Proin orci diam, egestas at pulvinar tincidunt, fringilla ut sem.\n\nQuisque quis dignissim justo.Curabitur laoreet felis at nisl dapibus, et accumsan sapien euismod.Curabitur malesuada nunc vel risus posuere, eu mollis ex eleifend.Ut varius ex erat, id cursus tellus mattis in.Aliquam id quam tortor.Nunc dapibus egestas ligula non dictum.Mauris facilisis urna ornare suscipit efficitur.Curabitur in nisi nec diam fringilla commodo lacinia in odio.Duis malesuada condimentum felis, vitae auctor ipsum.Ut eleifend, tellus id fermentum tristique, dolor arcu blandit diam, condimentum gravida tellus odio quis felis.Donec quam eros, ullamcorper at pulvinar et, mattis sit amet nulla.In hac habitasse platea dictumst.Nulla sit amet rhoncus lacus.Suspendisse eleifend elit nec velit ultrices, ac malesuada turpis euismod.Vestibulum eget erat ut massa pharetra hendrerit.\n\nOrci varius natoque penatibus et magnis dis parturient montes, nascetur ridiculus mus.Etiam quis condimentum ante.Vestibulum a interdum nunc, ut ultrices lectus.Vestibulum aliquet tortor in quam viverra ultricies.Cras cursus enim in tortor mollis, posuere porta metus ornare.Sed ut fermentum sapien, sed cursus erat.Nunc fermentum consequat sapien, at bibendum orci vestibulum rutrum.Curabitur ornare finibus facilisis.Sed eros diam, sagittis sed nunc eu, molestie pellentesque ante.Donec pretium mauris non dictum molestie.Suspendisse varius elementum arcu.Morbi vitae hendrerit velit, a egestas mauris.Cras nec augue urna.\n\nCurabitur ex augue, consequat ac est placerat, laoreet imperdiet mauris.Quisque lorem odio, bibendum nec lectus nec, finibus fringilla justo.Proin non lacus consequat, feugiat mi ut, dapibus orci.Nullam sed diam at purus porttitor pellentesque.Suspendisse vitae erat at quam lobortis malesuada.Pellentesque nec magna nibh.Praesent ac lectus vel odio blandit pellentesque in vitae nisi.\n\nSed efficitur vitae ipsum sit amet rhoncus.Donec sit amet lacus accumsan, hendrerit quam a, mattis lacus.Fusce scelerisque dui eget odio cursus sodales.Sed lorem mi, congue nec laoreet eget, placerat id ex.Sed vel arcu rutrum, ornare erat nec.";



	DWORD64 time = GetTickCount64();
	wstring key = L"Vincent le génie des mathématiques purs";
	
	wstring __new = Cryptools::Vignere(Cryptools::AtmCongruentialPMS(start, key, currentalphabet, MODE::CRYPT),key, currentalphabet, MODE::CRYPT);
	//wstring __old = Cryptools::Vignere(Cryptools::AtmCongruentialPMS(__new, key, currentalphabet, MODE::UNCRYPT), key, currentalphabet,  MODE::UNCRYPT);
	wcout << L"Original : \n" << start << L"\n\n\n\n" << L"Chiffre : \n" << __new;
	wcout << endl << endl << endl << "Time elapsed : " << (GetTickCount64() - time) << L"ms" << endl << "Char count : " << start.size() << endl << "Key : " << key << endl << L"Seed : " << Cryptools::getSum(key, currentalphabet) << endl;

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




