#include <vector>
#include <string>

#define SIZEOF(x) (int) x.size()
#define RANGE(x) range(x, 0, 10)
//#define FILEINPUT 1

using namespace std;

float mediana(vector<float> duom);
float vidurkis(vector <float> coll); 
bool range(float F, int a, int b);
bool exists(int I, vector<vector<float> > vec);

template<typename T>
T* aterr(int I, vector<T> vec);

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


