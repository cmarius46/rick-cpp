
#include "headers/Neuron.h"
#include <bits/stdc++.h>
using namespace std;


Neuron::Neuron() {
	this->pos = -1;
	this->data = vector<string>();
}

Neuron::Neuron(int p, vector<string> v) {
	// fiecarui neuron ii este atribuita o pozitie si sunt
	// recapatate datele din memorie

	this->pos = p;
	this->data = v;
}

void Neuron::addPrev(int pos, Neuron *pn) {

	// adds a neuron n as a predecessor of the current neuron
	// pos is the position of n, pn is a pointer to n

	this->prev.push_back(pn);
	mappedPrev[pos] = pn;
	//TODO check if it already exists

	//if(!exists)
	pn->addNext(this->pos, this);
}

void Neuron::addNext(int pos, Neuron *pn) {
	// adds a neuron n as a successor of the current neuron
	// pos is the position of n, pn is a pointer to n

	this->next.push_back(pn);
	mappedNext[pos] = pn;
	//TODO check if it already exists
}

void Neuron::process() {
    // self function to process data;
}

void show(int n) {
    cout << n << "async!" << '\n';
}


void Neuron::send() {

	//future<void> var = async(mappedNext[2]->receive, this->data);
	// future<void> var = async(show, 17);

	mappedNext[2]->receive(this->data);
	// TODO should be done asynchronous

	cout << "sent" << '\n';
}

// bool send(old) returns true if sent the message to at least another neuron

void Neuron::receive(vector<string> v) {
	this->data = v;
	cout << "received" << '\n';
}

// bool receive(old) returns true if received at least one message 

void Neuron::print() {
	// debugs the data of the neuron

	cout << pos << " ";
	for(auto word : data) {
		cout << word << " ";
	}
	cout << "\n\n";
}