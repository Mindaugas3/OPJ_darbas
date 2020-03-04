#include <vector>
#include <algorithm>
#include <exception>
using namespace std;

#ifndef SIZEOF
#define SIZEOF(x) (int) x.size()
#endif

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

bool exists(int I, vector<vector<float> > vec){
	return I < vec.size();
}
template<typename T>
T* aterr(int I, vector<T> vec){
	try {
		T t = vec.at(I);
		T *n = &t;
		return n;
	} catch (exception& e){
		return nullptr;
	}
	return nullptr;
}
