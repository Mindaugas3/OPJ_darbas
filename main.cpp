#include <iostream>
#include <string>
#include <iomanip>
//#include <array>
#include <cstdlib>
#include <cmath>

#define Z 1000
#define SIZEOF(x) nullLen(x)

//kiek max ivesim vardu ar namu darbu vienam asmeniui

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//deklaracijos
float mediana(float *duom, float egzas);
void bubbleSort(float *arr, int n);
void swap(float *xp, float *yp);
void cpy(float *pirmas, float *antras, int targetsize);
template<typename T>
void resize(T *arr);
bool range(float F);

int nullLen(float *mas);

int main(int argc, char** argv) {
	//deklaracija
	string *vardas = new string[Z];
	string *pavarde = new string[Z];
	float *ndv = new float[Z];
	float **ND = new float*[Z]; 
	float *egzas = new float[Z];
	float *vid = new float[Z];
	float *med = new float[Z];
	int counter = 0;
	string vrd; //laikinas skaitliukas vardui
	
	//ivedimas
	cout << "Iveskite varda - tarpas kaip pirmas simbolis sustabdys ivesti: " << endl;
	while(getline(cin, vrd)){
	if(vrd[0] == ' '){
	 break;
	} else {
		
	vardas[counter] = vrd;
		
		vrd = "";
	}
	//enter turi sustabdyti ivesties cikla
	//string traktuojamas kaip char[] masyvas
	
	cout << endl << "Iveskite pavarde: " << endl;
	cin >> pavarde[counter];
	//-------------------------------
	int ndsk = 0; //namu darbu skaicius kiekvienam zmogui.
	ND[counter] = new float[Z];
	while(true){
		ND:
			cout << endl << "Iveskite namu darbu rezultata arba bet koki neskaitini simboli jei viskas " << endl;
			float I;
			cin >> I;
			if(!range(I) && cin.good()){
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
	ND[counter][ndsk] = I;
	ndsk++;
	}
	cin.clear();
	fflush(stdin);
	
	//egzaminas
	float I = 0;
	ivestis:
		cout << endl << "Iveskite egzamino rezultata" << endl;
		cin >> I;
		if(!range(I) && cin.good()){
			cout << "Egzamino rezultatas turi buti tarp 0 ir 10!" << endl;
			goto ivestis;
		}
		if(cin.good()){
			egzas[counter] = I;
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
	
	//apdorojimas
	for(int I = 0; I < counter; I++){
		//vidurkis
		float tempvid = 0;
		int J = 0;
		while(ND[I][J] != NULL && range(ND[I][J]) ){
			if(vid[I] != 0  && !isnan(ND[I][J])){
				tempvid += ND[I][J]*0.4;
				cout << "J: " << ND[I][J] << endl;				
			}
			J++;
		}
		tempvid /= J;
		vid[I] = tempvid;
		vid[I] += egzas[I]*0.6;
		//mediana
		med[I] = mediana(ND[I], egzas[I]); //ND[I] rodo i savo masyva
		
	}
	//isvedimas
			cout << "Vardas: \t Pavarde: \t Vidurkis: \t Mediana: "<< endl;
			cout << "------------------------------------------" << endl;
	for(int H = 0; H < counter; H++){

		cout << setprecision(2) << fixed << vardas[H] << " \t " << pavarde[H] << " \t  " << vid[H] << " \t " << med[H] << endl;
	}
	delete[] vardas;
	delete[] pavarde;
	for(int H = 0; H < counter; H++){
		delete[] ND[H];
	}
	delete[] ND;
	delete[] egzas;
	delete[] vid;
	delete[] med;
	system("pause");
	return 0;
}

float mediana(float *duom, float egzas){ //X balu is N.D ir 1 is egzamino
	//suzinomas dydis ir deklaruojami kintamieji 
	float med;
	int H = SIZEOF(duom) + 1;
	float masFinal[H]; 
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

void bubbleSort(float *arr, int n)  
{  
	//cout << "Bubble size: " << n << endl;
    int i, j;  
    for (i = 0; i < n-1; i++)      
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)  
        if (arr[j] > arr[j+1])  
            swap(&arr[j], &arr[j+1]);  
}  

void cpy(float *pirmas, float *antras, int targetsize){
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

int nullLen(float *mas){ 
	//kadangi sizeof'as neveiks nes as priskyriau 100 elementu riba masyvams, reikia naujos funkcijos dydziui
	int K = 0;
	while(mas[K] != NULL){
		K++;
	}
	return K;
}

template<typename T>
void resize(T *arr){
	int size_arr = sizeof(arr) / sizeof(*arr);
	arr = (T*) realloc(arr, size_arr + 1);
}

bool range(float F){
	if(F <= 10 && F > 0) return true;
	return false;
}
