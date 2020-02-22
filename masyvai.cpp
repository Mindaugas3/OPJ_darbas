#include <iostream>
#include <string>
#include <iomanip>

#define Z 100
#define SIZEOF(x) nullLen(x)

//kiek max ivesim vardu ar namu darbu vienam asmeniui

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//deklaracijos
float mediana(float *duom, float egzas);
void bubbleSort(float *arr, int n);
void swap(float *xp, float *yp);
void cpy(float *pirmas, float *antras, int targetsize);

int nullLen(float *mas);

int main(int argc, char** argv) {
	//deklaracija
	string vardas[Z];
	string pavarde[Z];
	float ND[Z][Z]; //iki 100 ND vienam asmeniui. :)
	float egzas[Z];
	float vid[Z];
	float med[Z];
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
	while(true){
	cout << endl << "Iveskite namu darbu rezultata arba taska jei viskas " << endl;
	cin >> ND[counter][ndsk];
		if(!cin.good()){
			break;
		}
	ndsk++;
	}
	cin.clear();
	fflush(stdin);
	
	cout << endl << "Iveskite egzamino rezultata" << endl;
	cin >> egzas[counter];
	counter++;
	cout << "Iveskite varda - tarpas kaip pirmas simbolis sustabdys ivesti: " << endl;
	cin.ignore();
	}
	
	//apdorojimas
	for(int I = 0; I < counter; I++){
		//vidurkis
		int J = 0;
		while(ND[I][J] != NULL){
			vid[I] += ND[I][J];
			J++;
		}
		vid[I] += egzas[I];
		vid[I] /= J+1;
		//mediana
		med[I] = mediana(ND[I], egzas[I]); //ND[I] rodo i savo masyva
		
	}
	//isvedimas
			cout << "Vardas: \t Pavarde: \t Vidurkis: \t Mediana: "<< endl;
			cout << "------------------------------------------" << endl;
	for(int H = 0; H < counter; H++){

		cout << setprecision(2) << fixed << vardas[H] << " \t " << pavarde[H] << " \t  " << vid[H] << " \t " << med[H] << endl;
	}
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
