#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>

#define MAXGEN 20

using namespace std;
#pragma once
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


void rusiuoti(vector<studentas>* stud, vector<studentas>* vec1, vector<studentas>* vec2){
	auto start = chrono::high_resolution_clock::now();
	//pats rusiavimas
	//cout << stud->size() << endl;
	for(int I = 0; I < stud->size(); I++){
		if(stud->at(I).vidurkis < 5){
			vec2->push_back(stud->at(I)); //ne cool
		} else {
			vec1->push_back(stud->at(I));
		}
		
	}
	//matavimas
	auto end = chrono::high_resolution_clock::now();
	chrono::duration<double> dif = end - start;
	cout << "Studentu isskirstymas uztruko: " << dif.count() << " s." << endl;
}

void isvesti(vector<studentas>* cool, vector<studentas>* notcool){
	auto start = chrono::high_resolution_clock::now();	
	ofstream m("Linksmuciai.txt");
	ofstream n("Sadbois.txt");
	for(int I = 0; I < cool->size(); I++){
		m << cool->at(I).vardas << " " << cool->at(I).pavarde << " ";
		for(int J = 0; J < cool->at(I).namudarbai.size(); J++){
			m << cool->at(I).namudarbai.at(J) << " ";
		}
		m << cool->at(I).egzaminas << endl;
		//cout << "Linksmuciai " << endl;
	}
	for(int H = 0; H < notcool->size(); H++){
		n << cool->at(H).vardas << " " << cool->at(H).pavarde << " ";
		for(int K = 0; K < cool->at(H).namudarbai.size(); K++){
			n << cool->at(H).namudarbai.at(K) << " ";
		}
		n << cool->at(H).egzaminas << endl;
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
	h << "vardas \t pavarde \t Namu darbai \t \t\t\t\t\t\t Egzaminas" << endl;
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
