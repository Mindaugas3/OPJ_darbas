#include <iostream>
#include <string>
#include <iomanip>

#include <vector>
#include <deque>
#include <list>

#include <exception>
#include <stdexcept>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <chrono>

#pragma once
#include "skaityti.h"
#pragma once
#include "filegen.h"

using namespace std;
static bool input;
	
//deklaracijos
#define FILEINPUT

int main(int argc, char** argv) {
	srand(time(NULL));

	cout << "Ar norite generuoti naujus failus? [T]aip, [N]e " << endl;
	char AA = cin.get();
	if(AA == 'T' || AA == 't'){
		generuoti(1000, to_string(1000));
		generuoti(10000, to_string(10000));
		generuoti(100000, to_string(100000));
		generuoti(1000000, to_string(1000000));
	} else {
		fflush(stdin);
		cout << "Tuo atveju, ar noresite vesti duomenis ranka? [T]aip, [N]e" << endl;
		char Q;
		Q = cin.get();
		if(Q == 'T' || Q == 't'){
			input = true;
		} else {
			input = false;
		}
	}
	fflush(stdin);
	//atskiros funkcijos
	
	skaityti("vector", input);
	skaityti("deque", input);
	skaityti("list", input);
	
	system("pause");
	return 0;
}


