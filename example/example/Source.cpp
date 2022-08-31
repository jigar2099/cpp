#include<iostream>
using namespace std;

class Smartphone {
public:
	virtual void TakeASelfie()=0;
	virtual void MakeACall() = 0;
};

class Android:public Smartphone {
public:
	void TakeASelfie() {
		cout << "Android selfie \n";
	}
	void MakeACall() {
		cout << "Android calling.... \n";
	}
};

class IPhone :public Smartphone {
public:
	void TakeASelfie() {
		cout << "IPhone is taking selfie \n";
	}
	void MakeACall() {
		cout << "Android calling... \n";
	}
};




int main() {
	Smartphone* s1 = new Android();
	Smartphone* s2 = new IPhone();
	s1->TakeASelfie(); s1->MakeACall();
	s2->TakeASelfie(); s2->MakeACall();


	return 0;
}