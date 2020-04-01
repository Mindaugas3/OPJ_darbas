#pragma once
#include <vector>
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>
#define MAXGEN 20

using namespace std;


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


template<template <typename, typename> class Container>
void rusiuoti(Container<studentas, allocator<studentas> >* stud, Container<studentas, allocator<studentas> >* vec1, Container<studentas, allocator<studentas> >* vec2);

void generuoti(int size, string suffix);

template<template <typename, typename> class Container>
void isvesti(Container<studentas, allocator<studentas> >* cool, Container<studentas, allocator<studentas> >* notcool);

void avardas(string* vrd, string*pvrd);
void rastiFailus(string* fpav);
