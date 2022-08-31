#include<iostream>
using namespace std;

class Instrument {
public:
	virtual void MakeSound() = 0;
};

class Accordion:public Instrument {
public:
	void MakeSound() {
		cout << "An accordian playing...\n";
	}
};

class guitar :public Instrument {
public:
	void MakeSound() {
		cout << "A guitar playing...\n";
	}
};


int main() {
	Instrument* i1 = new Accordion();
	Instrument* i2 = new guitar();
	//i1->MakeSound();
	//i2->MakeSound();

	Instrument* instruments[2] = { i1,i2 };
	for (int i = 0; i < 2; i++) {
		instruments[i]->MakeSound();
	}

	return 0;
}