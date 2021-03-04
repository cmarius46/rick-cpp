#pragma once
#include <unordered_map>
#include <vector>
#include <cstring>

struct Memory {

	int size;
	std::unordered_map<int, std::string> mem; // pozitia (id-ul) neuronului, 
	// respectiv datele acestuia

	Memory();
};