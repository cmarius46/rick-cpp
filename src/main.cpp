#include <bits/stdc++.h>


using namespace std;


void show(int a) {
	cout << a << "async !" << '\n';
}

struct Neuron {
	int pos;
	vector<string> data;

	vector<Neuron*> next;
	vector<Neuron*> prev;

	unordered_map<int, Neuron*> mappedNext;
	unordered_map<int, Neuron*> mappedPrev;

	Neuron();
	Neuron(int , vector<string> );
	void addPrev(int , Neuron* );
	void addNext(int , Neuron* );
	void process();
	void send();
	void receive(vector<string>);
	void print();


};

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

}
// self function to process data;

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

	n2.addPrev(1, &n1);

	n1.send();
	n2.print();
	n1.next[0]->print();

	return 0;
}

