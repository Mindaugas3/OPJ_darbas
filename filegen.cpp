
#include "filegen.h"

using namespace std;


template<template <typename, typename> class Container>
void rusiuoti(Container<studentas, allocator<studentas> >* stud, Container<studentas, allocator<studentas> >* vec1, Container<studentas, allocator<studentas> >* vec2){
	typedef typename Container<studentas, allocator<studentas> >::iterator elementas;
	auto start = chrono::high_resolution_clock::now();
	elementas el = (*stud).begin();
	//pats rusiavimas
	//cout << stud->size() << endl;
	for(int I = 0; I < stud->size(); I++){
		advance(el, I);
		
		if(el->vidurkis < 5){
			vec2->push_back(*el); //ne cool
		} else {
			vec1->push_back(*el);
		}
		
	}
	//matavimas
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> dif = end - start;
	cout << "Studentu isskirstymas uztruko: " << dif.count() << " s." << endl;
}

template<template <typename, typename> class Container>
void isvesti(Container<studentas, allocator<studentas> >* cool, Container<studentas, allocator<studentas> >* notcool){
	typedef typename Container<studentas, allocator<studentas> >::iterator elementas;
	auto start = chrono::high_resolution_clock::now();	
	ofstream m("Linksmuciai.txt");
	ofstream n("Sadbois.txt");
	elementas geri = (*cool).begin();
	elementas blogi = (*notcool).begin();
	
	for(int I = 0; I < cool->size(); I++){
		advance(geri, I);
		
		m << geri->vardas << " " << geri->pavarde << " ";
		for(int J = 0; J < geri->namudarbai.size(); J++){
			m << geri->namudarbai.at(J) << " ";
		}
		m << geri->egzaminas << endl;
		//cout << "Linksmuciai " << endl;
	}
	for(int H = 0; H < notcool->size(); H++){
		advance(blogi, H);
		
		n << blogi->vardas << " " << blogi->pavarde << " ";
		for(int K = 0; K < blogi->namudarbai.size(); K++){
			n << blogi->namudarbai.at(K) << " ";
		}
		n << blogi->egzaminas << endl;
		//cout << "Sadbois " << endl;
	}
	m.close();
	n.close();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> dif = end - start;
	//cout << "Sugrupuotu failu sukurimas uztruko: " << dif.count() << " s." << endl;
}

void avardas(string* vrd, string* pvrd){ //atsitiktinai generuojama rodykle i pora eiluciu, vardo ir pavardes
	string vardai[14] = {"Giedrius", "Mantas", "Karolis", "Darius", "Simas", "Simona", "Gabija", "Laura", "Ieva", "Migle", "Justas", "Tadas", "Austeja", "Auguste"};
	string pavardes[14];
	for(int H = 0; H < 14; H++){ 
		if(vardai[H].back() == 's'){
			pavardes[H] = "Pavardenis";// + to_string(H);
		} else {
			pavardes[H] = "Pavardaite";// + to_string(H);
		}
	}

	int rint = rand() % 14;
	*vrd = vardai[rint];
	*pvrd = pavardes[rint];
}

void generuoti(int size, string suffix){
	auto start = chrono::high_resolution_clock::now();
	ofstream h("Studentai" + suffix + ".txt");
	//h << setw(20);
	h << "vardas" << "pavarde" << "Namu darbai " << " Egzaminas" << endl;
			srand(time(NULL));
	for(int I = 0; I < size; I++){
		string vardas, pavarde;
		avardas(&vardas, &pavarde);
		//cout << vardas << " \t " << pavarde << endl;
		h << vardas << " " << pavarde << " ";
		int ndsk = rand() % MAXGEN + 1;
		for(int I = 0; I < ndsk; I++){
			h << rand()%10+1 << " ";
		}
		h << rand()%7+4 << " " << endl; //egzaminas ir baigia generuoti failo eilute.
	}
	h.close();
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	//std::cout << size << " elementu generavimas uztruko: " << diff.count() << " s." << endl;
}
