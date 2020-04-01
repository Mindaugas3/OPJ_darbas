#define FILEINPUT

#include "skaityti.h"
using namespace std;



template<template <typename, typename> class Container>
void skaityti(bool input) {
	
	
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
	
	int suf[] = {1000, 10000, 100000, 1000000};
	for(int I = 0; I < 4; I++){
	string fname = "Studentai";
	fname += to_string(suf[I]);
	fname +=  + ".txt";
	
	ifstream kursiokai(fname);
	#ifdef FILEINPUT
	string data; //vardas
	string unused;
	auto start = chrono::high_resolution_clock::now();
	if(!getline(kursiokai, unused)){ //klaidu patikra ir kategoriju praleidimas;
		cout << "Failas nerastas arba tuscias!" << endl;
	}
	//failo ivedimas
	while(getline(kursiokai, data)){
		auto start = chrono::high_resolution_clock::now();
		cout << "Skaitoma su " << suf[I] << " irasu" << endl;
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
		auto end = chrono::high_resolution_clock::now();
		chrono::duration<double> diff = end - start;
		cout << "Failu skaitymas uztruko: " << diff.count() << " s." << endl;
	}
	#endif
	kursiokai.close();
	}
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
	rusiuoti(&studentai, &cool, &notcool);
	isvesti(&cool, &notcool);
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
			cout << "Programos klaida. Paleiskite is naujo! " << endl;
		}
	}
	}

	system("pause");
}


