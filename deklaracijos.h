#pragma once
#include <vector>
#include <string>
#include <chrono>
#include <deque>
#include <list>

#include <vector>
#include <algorithm>
#include <exception>

#define SIZEOF(x) (int) x.size()
#define RANGE(x) range(x, 0, 10)
//#define FILEINPUT 1
#define RANDGEN
using namespace std;

float mediana(vector<float> duom);
float vidurkis(vector <float> coll); 
bool range(float F, int a, int b);

