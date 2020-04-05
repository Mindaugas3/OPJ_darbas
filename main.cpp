#include <iostream>
#include <string>
#include <iomanip>

#include <vector>
#include <deque>
#include <list>

#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

#include "deklaracijos.h"
//#include "filegen.h"
//#include "skaityti.h"

using namespace std;
	
//deklaracijos
#define FILEINPUT
#define MAXGEN 20


struct studentas {
	//ivedami duomenys
	string vardas;
	string pavarde;
	vector<float> namudarbai;
	float egzaminas;
	//isvedami duomenys
	float vidurkis;
	float mediana;
};

bool gavoSkola(const studentas& st);

bool palyginti(const studentas& s1, const studentas& s2);

template<template <typename, typename> class Container>
void rusiuoti(Container<studentas, allocator<studentas> >& stud, Container<studentas, allocator<studentas> >& vec1, Container<studentas, allocator<studentas> >& vec2);

void generuoti(int size, string suffix);

template<template <typename, typename> class Container>
void isvesti(Container<studentas, allocator<studentas> >& cool, Container<studentas, allocator<studentas> >& notcool);

void avardas(string* vrd, string* pvrd);
void rastiFailus(string* fpav);

template<template <typename, typename> class Container>
void skaityti(bool input, int num);


int main(int argc, char** argv) {
	srand(time(NULL));

 	bool input;
 	setlocale(LC_ALL, "Lithuanian");
	cout << "Ar norite generuoti naujus failus? [T]aip, [N]e " << endl;
	char AA = cin.get();
	if(AA == 'T' || AA == 't'){
		generuoti(1000, to_string(1000));
		generuoti(10000, to_string(10000));
		generuoti(100000, to_string(100000));
		generuoti(1000000, to_string(1000000));
	} else {
		fflush(stdin);
		cout << "Tuo atvëju, ar norësite vesti duomenis ranka? [T]aip, [N]e" << endl;
		char Q;
		Q = cin.get();
		if(Q == 'T' || Q == 't'){
			input = true;
		} else {
			input = false;
		}
	}

	fflush(stdin);
	//atskiros funkcijos
	int suf[] = {1000, 10000, 100000, 1000000};
	for(int I = 0; I < 4; I++){
		cout << "===================================" << endl;
		cout << setw(7) << suf[I] << ": | Skaitymas |" << " Rûðiavimas |" << endl;
		cout << setw(10) << "Vector: |";
		skaityti<vector>(input, suf[I]); 
		cout << setw(10) << "Deque: |";
		skaityti<deque>(input, suf[I]);
		cout << setw(10) << "List: |";
		skaityti<list>(input, suf[I]);
	}
	
	system("pause");
	return 0;
}


template<template <typename, typename> class Container>
void skaityti(bool input, int num) {
	
	
	auto start = chrono::high_resolution_clock::now();
	//deklaracija
	Container<studentas, allocator<studentas> > studentai; //std::allocator privalomas!
	Container<studentas, allocator<studentas> > cool;
	Container<studentas, allocator<studentas> > notcool;
	int counter = 0;
	string vrd; //laikinas skaitliukas vardui
	studentas S;

	typedef typename Container<studentas, allocator<studentas> >::iterator elementas;

	//ivedimas
	if(input){
	cout << "Iveskite varda - tarpas kaip pirmas simbolis sustabdys ivesti: " << endl;
	while(getline(cin, vrd)){
	if(vrd[0] == ' '){
	 break;
	} else {
		S.vardas = vrd;
		
		vrd = "";
	}
	//enter turi sustabdyti ivesties cikla
	//string traktuojamas kaip char[] masyvas
	string Q;
	cout << endl << "Iveskite pavarde: " << endl;
	cin >> Q;
	
	S.pavarde = Q;
	//-------------------------------
	int ndsk = 0; //namu darbu skaicius kiekvienam zmogui.
	while(true){
		
		ND:
			cout << endl << "Iveskite namu darbu rezultata arba bet koki neskaitini simboli jei viskas " << endl;
			float I;
			vector<float> fvec;
			cin >> I;
			if(!RANGE(I)){
				cout << "Namu darbu rezultatas turi buti tarp 0 ir 10!" << endl;
				goto ND;	
			}
	if(!cin.good()){
		if(ndsk == 0){
				cout << "Iveskite bent viena namu darbo bala!" << endl;
				cin.clear();
				fflush(stdin);
				goto ND;
		}

		cin.clear();
		fflush(stdin);
		break;
	}
	S.namudarbai = fvec;
	S.namudarbai.push_back(I);
	ndsk++;
	}
	cin.clear();
	fflush(stdin);
	float I = 0;
	
	//etiketes naudojimas su goto
	ivestis:
		cout << endl << "Iveskite egzamino rezultata" << endl;
		cin >> I;
		if(!RANGE(I)){
			cout << "Egzamino rezultatas turi buti tarp 0 ir 10!" << endl;
			goto ivestis;
		}
		if(cin.good()){
			S.egzaminas = I;
		} else {
			cout << "Egzamino rezultatas turi buti skaicius!" << endl;
			fflush(stdin);
			cin.clear();
			goto ivestis;
		}
	studentai.push_back(S);
	counter++;
	cout << "Iveskite varda - tarpas kaip pirmas simbolis sustabdys ivesti: " << endl;
	cin.ignore();
	}
	}
	//===============================DARBAS SU FAILAIS==================================
	
	
	
	string fname = "Studentai";
	fname += to_string(num);
	fname +=  + ".txt";
	
	ifstream kursiokai(fname);
	#ifdef FILEINPUT
	string data; //vardas
	string unused;
	if(!getline(kursiokai, unused)){ //klaidu patikra ir kategoriju praleidimas;
		cout << "Failas nerastas arba tuðèias!" << endl;
	}
	stringstream buferis;
	buferis << kursiokai.rdbuf();
	kursiokai.close();
	//failo ivedimas
	while(getline(buferis, data)){
		
		stringstream eilute(data);
		studentas SV;
		string vardasf;
		eilute >> vardasf;
		SV.vardas = vardasf;
		//------------------------------
		string pavardef;
		eilute >> pavardef;
		SV.pavarde = pavardef;		
		//------------------------------
		float ndbalas;
		vector<float> ndzmogui;
		while(eilute >> ndbalas){
			//namu darbai - vektorius.
			ndzmogui.push_back(ndbalas);			
		}
		int J = (int) ndzmogui.size();
		float egzaminas = ndzmogui.at(J - 1);
		ndzmogui.pop_back();
		SV.namudarbai = ndzmogui;
		SV.egzaminas = egzaminas;
		//------------------------------
		studentai.push_back(SV);
		counter++;
		//------------------------------
		
	}
	#endif

	auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << setw(8) << fixed << setprecision(5) << diff.count() << "s. | ";
	
	//apdorojimas
	for(int I = 0; I < counter; I++){
		//vidurkis
		int J = 0;
		float tempvid = 0;
		float tempmed = 0;
		elementas el = studentai.begin();
		advance(el, I);
		
		while(J < el->namudarbai.size()){
			tempvid += el->namudarbai.at(J) * 0.4;
			J++;
		}
		tempvid /= J;
		
		tempvid += el->egzaminas * 0.6;
		el->vidurkis = tempvid;
		//mediana
		el->mediana = mediana(el->namudarbai); //ND[I] rodo i savo vidini vektoriu
		
	}
	rusiuoti(studentai, cool, notcool);
	isvesti(cool, notcool);
	//isvedimas
			//cout << "Vardas: \t Pavarde: \t Galutinis: \t Mediana: "<< endl;
			//cout << "---------------------------------------------------------------------------------" << endl;
		
		//visu vektoriu dydziai 10k+1
	if(input){
		
	for(int H = 0; H < counter; H++){
		elementas el = studentai.begin();
		advance(el, H);
		try{
			cout << setprecision(2) << fixed << el->vardas << " \t " << el->pavarde << " \t  " << el->vidurkis << " \t " << el->mediana << endl;			
		} catch (exception& e){
			e.what();
			cout << "Programos klaida. Paleiskite ið naujo! " << endl;
		}
	}
	}
}

bool gavoSkola(const studentas& st){
	if(st.vidurkis < 5) return true;
	else return false;
}

bool palyginti(const studentas& s1, const studentas& s2){
	if(s1.vidurkis == s2.vidurkis) return s1.pavarde > s2.pavarde;
	return (s1.vidurkis > s2.vidurkis);
}

template<template <typename, typename> class Container>
void rusiuoti(Container<studentas, allocator<studentas> >& stud, Container<studentas, allocator<studentas> >& vec1, Container<studentas, allocator<studentas> >& vec2){
	typedef typename Container<studentas, allocator<studentas> >::iterator elementas;
	auto start = chrono::high_resolution_clock::now();
	//pats rusiavimas
	//cout << stud->size() << endl;
	elementas el = stable_partition(stud.begin(), stud.end(), gavoSkola);
	Container<studentas, allocator<studentas> > geri(el, stud.end());
	vec1 = geri;
	//matavimas
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> dif = end - start;
	cout <<  fixed << setprecision(6) << dif.count() << "s. |" << endl;
}

template<template <typename, typename> class Container>
void isvesti(Container<studentas, allocator<studentas> >& cool, Container<studentas, allocator<studentas> >& notcool){
	typedef typename Container<studentas, allocator<studentas> >::iterator elementas;
	auto start = chrono::high_resolution_clock::now();
	ofstream m("Linksmuciai.txt");
	ofstream n("Sadbois.txt");
	//buferis
	stringstream good;
	stringstream bad;
	
	for(auto &B : cool){
		
		good << B.vardas << " " << B.pavarde << " ";
		for(int J = 0; J < B.namudarbai.size(); J++){
			good << B.namudarbai.at(J) << " ";
		}
		good << B.egzaminas << endl;
		//cout << "Linksmuciai " << endl;
	}
	m << good;
	
	for(auto &W : notcool){
		
		bad << W.vardas << " " << W.pavarde << " ";
		for(int K = 0; K < W.namudarbai.size(); K++){
			bad << W.namudarbai.at(K) << " ";
		}
		bad << W.egzaminas << endl;
		//cout << "Sadbois " << endl;
	}
	n << bad;
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
		int ndsk = 8;
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

