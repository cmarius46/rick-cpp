#pragma once
#include <vector>
#include <unordered_map>
#include <cstring>

struct Neuron {
	int pos;
	std::string data;

	std::vector<Neuron*> next;
	std::vector<Neuron*> prev;

	std::unordered_map<int, Neuron*> mappedNext;
	std::unordered_map<int, Neuron*> mappedPrev;

	Neuron();
	Neuron(int , std::string );
	void addPrev(int , Neuron* );
	void addNext(int , Neuron* );
	void process();
	void send();
	void receive(std::string );
	void print();
};