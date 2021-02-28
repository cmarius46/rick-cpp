#include <bits/stdc++.h>


using namespace std;

struct Neuron {

	int pos;
	vector<string> data;

	vector<Neuron*> next;
	vector<Neuron*> prev;

	Neuron() {
		this->pos = -1;
		this->data = vector<string>();
	}

	Neuron(int p, vector<string> v) {
		// fiecarui neuron ii este atribuita o pozitie si sunt
		// recapatate datele din memorie

		this->pos = p;
		this->data = v;
	}

	void addPrev(Neuron *n) {
		// adds a neuron n as a predecessor of the current neuron
		this->prev.push_back(n);
		//TODO check if it already exists

		//if(!exists)
		n->addNext(this);
	}

	void addNext(Neuron *n) {
		// adds a neuron n as a successor of the current neuron
		this->next.push_back(n);
		//TODO check if it already exists
	}

	void process();
	// self function to process data;

	void send(){}

	// bool send(old) returns true if sent the message to at least another neuron

	void receive();

	// bool receive(old) returns true if received at least one message 

	void print() {
		// debugs the data of the neuron

		cout << pos << " ";
		for(auto word : data) {
			cout << word << " ";
		}
		cout << "\n\n";
	}

};

struct Memory {

	unordered_map<int, vector<string>> mem; // pozitia (id-ul) neuronului, 
	// respectiv datele acestuia

	Memory() {
		int size;
		vector<string> vec;

		size = 1;//cin >> size
		vec.push_back(string("primele"));
		vec.push_back(string("cuvinte"));
		vec.push_back(string("transmise"));

		this->mem[1] = vec;
		this->mem[2] = vector<string>();
	}
};


int main() {
	freopen("memory.in", "r", stdin);
	freopen("memory.out", "w", stdout);

	// se citeste memoria
	Memory memory;
	Neuron n1(1, memory.mem[1]);
	n1.print();
	Neuron n2(2, memory.mem[2]);
	n2.print();

	n2.addPrev(&n1);

	n1.send();
	n2.print();

	return 0;
}

