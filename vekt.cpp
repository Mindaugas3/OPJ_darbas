#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#define Z 100
#define SIZEOF(x) (int) x.size()

//kiek max ivesim vardu ar namu darbu vienam asmeniui

//NEVEIKIA

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//deklaracijos
float mediana(vector<float> duom, float egzas);
void bubbleSort(vector<float> arr, int n);
void swap(float *xp, float *yp);
void cpy(vector<float> pirmas, vector<float> antras, int targetsize);

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
	cout << endl << "Iveskite namu darbu rezultata arba taska jei viskas " << endl;
	float I;
	cin >> I;
	if(!cin.good()){
		break;
	}
	ND.at(counter).push_back(I);
		
	ndsk++;
	}
	cin.clear();
	fflush(stdin);
	float I = 0;
	cout << endl << "Iveskite egzamino rezultata" << endl;
	cin >> I;
	egzas.push_back(I);
	counter++;
	cout << "Iveskite varda - tarpas kaip pirmas simbolis sustabdys ivesti: " << endl;
	cin.ignore();
	}
	
	//apdorojimas
	for(int I = 0; I < counter; I++){
		//vidurkis
		int J = 0;
		while(J < ND.at(I).size()){
			vid.at(I) += ND.at(I).at(J);
			J++;
		}
		vid.at(I) += egzas.at(I);
		vid.at(I) /= J+1;
		//mediana
		med.at(I) = 0.0;//mediana(ND.at(I), egzas.at(I); //ND[I] rodo i savo vidini vektoriu
		
	}
	//isvedimas
			cout << "Vardas: \t Pavarde: \t Vidurkis: \t Mediana: "<< endl;
			cout << "------------------------------------------" << endl;
	for(int H = 0; H < counter; H++){

		cout << setprecision(2) << fixed << vardas.at(H) << " \t " << pavarde.at(H) << " \t  " << vid.at(H) << " \t " << med.at(H) << endl;
	}
	system("pause");
	return 0;
}

float mediana(vector<float> duom, float egzas){ //X balu is N.D ir 1 is egzamino
	//suzinomas dydis ir deklaruojami kintamieji 
	float med;
	int H = SIZEOF(duom) + 1;
	vector<float> masFinal; 
	cpy(duom, masFinal, H - 1);
	masFinal[H - 1] = egzas;

	//apdorojimas
	bubbleSort(masFinal, H); //bubblesort'as visa programa crashina
	//for(int I = 0; I < H; I++) cout << masFinal[I] << endl;
	//tada graziname vidurini elementa;
	//data sample

	if(H % 2 == 1){
		med = masFinal[H / 2];
	} else {
		med = (masFinal[H/2 -1] + masFinal[H/2] ) / 2;
	}
	//isvedimas ir pabaiga
	return med;
}

void swap(float *xp, float *yp)  
{  
    float temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  

void bubbleSort(vector<float> arr, int n)  
{  
	//cout << "Bubble size: " << n << endl;
    int i, j;  
    for (i = 0; i < n-1; i++)      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  

void cpy(vector<float> pirmas, vector<float> antras, int targetsize){
	//pirmas niekada nebus didesnis uz antra
	int size_1 = SIZEOF(pirmas);
	int size_2 = targetsize;
	if(size_1 > size_2 ){
		cout << "Kopijavimo funkcija nebus vykdoma" << endl;
		return;
	} else {
		for(int I = 0; I < size_1; I++){
			antras[I] = pirmas[I];
		}
	}
}

