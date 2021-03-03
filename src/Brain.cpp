
#include "headers/Brain.h"
#include "headers/Memory.h"
#include <bits/stdc++.h>
using namespace std;


Brain::Brain(int n) {
	// initialises the brain with a number of undeclared neurons

	this->size = n;
}

Brain::Brain() {
	// empty brain, just like yours
}

void Brain::init(Memory memory) {
	// initialises brain from memory

	this->size = memory.size;

    Neuron n1(1, memory.mem[1]);
	// n1.print();
	Neuron n2(2, memory.mem[2]);
	// n2.print();

	n2.addPrev(1, &n1);

	n1.send();
	n2.print();
	n1.next[0]->print();

}


string Brain::response() {
	// responds to a previous-sent request
}

void Brain::request(string req) {
	// queries the brain for something
}

