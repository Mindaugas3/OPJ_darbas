#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "deklaracijos.h"
#include "filegen.h"

using namespace std;

//deklaracijos
#define FILEINPUT

int main(int argc, char** argv) {
	srand(time(NULL));
	bool input;
	cout << "Ar norite generuoti naujus failus? [T]aip, [N]e " << endl;
	char AA = cin.get();
	if(AA == 'T' || AA == 't'){
		generuoti(1000, to_string(1000));
		generuoti(10000, to_string(10000));
		generuoti(100000, to_string(100000));
		generuoti(1000000, to_string(1000000));
	} else {
		fflush(stdin);
		cout << "Tuo atveju, ar noresite vesti duomenis ranka? [T]aip, [N]e" << endl;
		char Q;
		Q = cin.get();
		if(Q == 'T' || Q == 't'){
			input = true;
		} else {
			input = false;
		}
	}
	fflush(stdin);
	auto start = chrono::high_resolution_clock::now();
	//deklaracija
	vector<studentas> studentai;
	vector<studentas> cool;
	vector<studentas> notcool;
	int counter = 0;
	string vrd; //laikinas skaitliukas vardui
	studentas S;
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
	//==================================================================================
	
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
	}
	#endif
	kursiokai.close();
	}
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> diff = end - start;
	cout << "Failu skaitymas uztruko: " << diff.count() << " s." << endl;
	//apdorojimas
	for(int I = 0; I < counter; I++){
		//vidurkis
		int J = 0;
		float tempvid = 0;
		float tempmed = 0;
		while(J < studentai.at(I).namudarbai.size()){
			tempvid += studentai.at(I).namudarbai.at(J) * 0.4;
			J++;
		}
		tempvid /= J;
		
		tempvid += studentai.at(I).egzaminas * 0.6;
		studentai.at(I).vidurkis = tempvid;
		//mediana
		studentai.at(I).mediana = mediana(studentai.at(I).namudarbai); //ND[I] rodo i savo vidini vektoriu
		
	}
	rusiuoti(&studentai, &cool, &notcool);
	isvesti(&cool, &notcool);
	//isvedimas
			//cout << "Vardas: \t Pavarde: \t Galutinis: \t Mediana: "<< endl;
			//cout << "---------------------------------------------------------------------------------" << endl;
		
		//visu vektoriu dydziai 10k+1
	if(input){
		
	for(int H = 0; H < counter; H++){
		try{
			cout << setprecision(2) << fixed << studentai.at(H).vardas << " \t " << studentai.at(H).pavarde << " \t  " << studentai.at(H).vidurkis << " \t " << studentai.at(H).mediana << endl;			
		} catch (exception& e){
			e.what();
			cout << "Programos klaida. Paleiskite is naujo! " << endl;
		}
	}
	}
	system("pause");
	return 0;
}


