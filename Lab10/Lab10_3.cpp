#include <iostream>
using namespace std;

class BaseClass {
public:
	BaseClass() {};
	virtual void a() {};
};

class DerivedClass : public BaseClass {
public:
	DerivedClass() {};
};

int main() {
	BaseClass bc;
	DerivedClass dc;

	BaseClass* base = &dc;
	DerivedClass* derived = dynamic_cast<DerivedClass*>(base);

	if (derived == nullptr) {
		cout << "Something not OKAY" << endl;
	}
	else {
		cout << "Everything is OKAY" << endl;
	}

	return 0;
}