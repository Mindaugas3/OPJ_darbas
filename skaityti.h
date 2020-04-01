#pragma once
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
#include <memory>

#include "deklaracijos.h"

#include "filegen.h"

#define RANGE(x) range(x, 0, 10)

using namespace std;

//template<class T, std::allocator<T> >
template<template <typename, typename> class Container>
void skaityti(bool input);

