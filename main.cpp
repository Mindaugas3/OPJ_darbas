#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>

#include "deklaracijos.h"
//#include "deklaracijos.cpp"

using namespace std;

//deklaracijos
//#undef FILEINPUT

int main(int argc, char** argv) {
	//deklaracija
	vector<studentas> studentai;
	int counter = 0;
	string vrd; //laikinas skaitliukas vardui
	studentas S;
	//ivedimas
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
	
	#ifdef FILEINPUT
		ifstream kursiokai ("kursiokai.txt");
	string data; //vardas
	string unused;
	
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
	//isvedimas
			cout << "Vardas: \t Pavarde: \t Galutinis: \t Mediana: "<< endl;
			cout << "---------------------------------------------------------------------------------" << endl;
		
		//visu vektoriu dydziai 10k+1
	for(int H = 0; H < counter; H++){
		try{
			cout << setprecision(2) << fixed << studentai.at(H).vardas << " \t " << studentai.at(H).pavarde << " \t  " << studentai.at(H).vidurkis << " \t " << studentai.at(H).mediana << endl;			
		} catch (exception& e){
			e.what();
			cout << "Programos klaida. Paleiskite is naujo! " << endl;
		}
	}
	#ifdef FILEINPUT
	kursiokai.close();
	#endif
	system("pause");
	return 0;
}


