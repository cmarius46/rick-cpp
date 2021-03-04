#pragma once
#include "Neuron.h"
#include "Memory.h"
#include <unordered_map>
#include <cstring>

struct Brain {

	int size; // nr of neurons;
	std::unordered_map<int, Neuron*> neurons;

	Brain(); // declare an empty brain, just like yours
	Brain(int ); // declare an empty brain with a certain number of neurons
	void init(Memory ); // initialises brain from a memory
	void respond(Neuron* ); // brain responds to a previous request
	void request(std::string ); // requests the brain to respond to a certain query
	void request(std::vector<std::string> ); // requests the brain to respons to a multi-word query
	void print(); // prints ALL the content of the brain
};