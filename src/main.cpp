
#include <bits/stdc++.h>
#include "headers/Neuron.h"
#include "headers/Memory.h"
#include "headers/Brain.h"
using namespace std;

int main() {
	freopen("memory.in", "r", stdin);
	freopen("memory.out", "w", stdout);

	// se citeste memoria
	Memory memory;
	Brain brain;
	brain.init(memory);
	//brain.print();

	

	//brain.request(std::string("second"));
	cout << "DA";
	return 0;
}

