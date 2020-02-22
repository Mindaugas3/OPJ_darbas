#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>

#define SIZEOF(x) (int) x.size()
#define RANGE(x) range(x, 0, 10)
#define FILEINPUT 1

//VEIKIA

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

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//deklaracijos
float mediana(vector<float> duom);
float vidurkis(vector <float> coll); 
bool range(float F, int a, int b);

int main(int argc, char** argv) {
	//deklaracija
	vector<string> vardas;
	vector<string> pavarde;
	vector<vector<float> > ND; //iki 100 ND vienam asmeniui. :)
	vector<float> egzas;
	vector<float> vid;
	vector<float> med;
	int counter = 0;
	string vrd; //laikinas skaitliukas vardui
	
	//ivedimas
	cout << "Iveskite varda - tarpas kaip pirmas simbolis sustabdys ivesti: " << endl;
	while(getline(cin, vrd)){
	if(vrd[0] == ' '){
	 break;
	} else {
		vardas.push_back(vrd);
		vrd = "";
	}
	//enter turi sustabdyti ivesties cikla
	//string traktuojamas kaip char[] masyvas
	string Q;
	cout << endl << "Iveskite pavarde: " << endl;
	cin >> Q;
	
	pavarde.push_back(Q);
	//-------------------------------
	int ndsk = 0; //namu darbu skaicius kiekvienam zmogui.
	while(true){
		ND:
			cout << endl << "Iveskite namu darbu rezultata arba taska jei viskas " << endl;
			float I;
			vector<float> fvec;
			cin >> I;
		if(!RANGE(I)){
			cout << "Namu darbu rezultatas turi buti tarp 0 ir 10!" << endl;
			goto ND;	
		}
	if(!cin.good()){
		break;
	}
	ND.push_back(fvec);
	ND.at(counter).push_back(I);
		
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
			egzas.push_back(I);
		} else {
			cout << "Egzamino rezultatas turi buti skaicius!" << endl;
			fflush(stdin);
			cin.clear();
			goto ivestis;
		}
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
		string vardasf;
		eilute >> vardasf;
		vardas.push_back(vardasf);
		//------------------------------
		string pavardef;
		eilute >> pavardef;
		pavarde.push_back(pavardef);		
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
		ND.push_back(ndzmogui);
		egzas.push_back(egzaminas);
		//------------------------------
		counter++;
	}
	#endif
	
	//apdorojimas
	for(int I = 0; I < counter; I++){
		//vidurkis
		int J = 0;
		float tempvid = 0;
		float tempmed = 0;
		while(J < ND.at(I).size()){
			tempvid += ND.at(I).at(J) * 0.4;
			J++;
		}
		med.push_back(0.0);

		tempvid /= J;
		
		tempvid += egzas.at(I) * 0.6;
		vid.push_back(tempvid);
		//mediana
		med.at(I) = mediana(ND.at(I)); //ND[I] rodo i savo vidini vektoriu
		
	}
	//isvedimas
			cout << "Vardas: \t Pavarde: \t Galutinis: \t Mediana: "<< endl;
			cout << "---------------------------------------------------------------------------------" << endl;
		
		//visu vektoriu dydziai 10k+1
	for(int H = 0; H < counter; H++){
		try{
			cout << setprecision(2) << fixed << vardas.at(H) << " \t " << pavarde.at(H) << " \t  " << vid.at(H) << " \t " << med.at(H) << endl;			
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

float mediana(vector<float> duom){ //X balu is N.D ir 1 is egzamino
	//suzinomas dydis ir deklaruojami kintamieji 
	int H = SIZEOF(duom);
	float med;
	//apdorojimas
	sort(duom.begin(), duom.end());
	//tada graziname vidurini elementa;
	if(H % 2 == 1){
		med = duom.at(H/2);
	} else {
		med = (duom.at(H/2 - 1) + duom.at(H/2)) / 2;
	}
	//isvedimas ir pabaiga
	return med;
}

bool range(float F, int a, int b){
	//jeigu a < F < b, true, priesingai false
	if(a <= F && F <= b) return true;
	return false;
}

