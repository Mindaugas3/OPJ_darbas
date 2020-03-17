#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>
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


void rusiuoti(vector<studentas>* stud, vector<studentas>* vec1, vector<studentas>* vec2);
void generuoti(int size, string suffix);
void isvesti(vector<studentas>* cool, vector<studentas>* notcool);
void avardas(string* vrd, string*pvrd);
void rastiFailus(string* fpav);
