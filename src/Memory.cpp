
#include "headers/Memory.h"
#include <bits/stdc++.h>
using namespace std;

Memory::Memory() {
		int siz;
		vector<string> vec;

		siz = 1;//cin >> size

		this->size = siz;

		vec.push_back(string("primele"));
		vec.push_back(string("cuvinte"));
		vec.push_back(string("transmise"));

		this->mem[1] = vec;
		this->mem[2] = vector<string>();
	}