
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

void Brain::print() {
	// prints ALL the content of the brain

	for(auto i : neurons) {
		//TODO repair
		Neuron* n = i.second;
		cout << i.first << " ";
		n->print();

		cout << i.second->data << " ";
		cout << '\n';
	}
}

void Brain::init(Memory memory) {
	// initialises brain from memory

	this->size = memory.size;

    Neuron n1(1, memory.mem[1]);
	Neuron n2(2, memory.mem[2]);
	Neuron n3(3, memory.mem[3]);
	Neuron n4(4, memory.mem[4]);

	this->neurons[1] = &n1;
	this->neurons[2] = &n2;
	this->neurons[3] = &n3;
	this->neurons[4] = &n4;

	n2.addPrev(1, &n1);
	n3.addPrev(2, &n2);
	n4.addPrev(2, &n2);

	//n1.send();
	//n2.print();
	//n1.next[0]->print();

}


void Brain::respond(Neuron* n) {
	// responds to a previous-sent request

	cout << "Query: " << n->data << '\n';
	cout << "Response: {";
	for(auto neuron : n->next) {
		neuron->print();
	}
	for(auto neuron : n->prev) {
		neuron->print();
	}
	cout << "}" << "\n\n";
}

void Brain::request(string req) {
	// queries the brain for something

	for(auto obj : neurons) {
		Neuron* n = obj.second;
		if(n->data == req) {
			cout << "found !" << '\n';
			respond(n);
			break;
		}
	}
}

