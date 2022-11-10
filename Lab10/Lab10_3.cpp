#include <iostream>
using namespace std;

class BaseClass {
public:
	// 다이나믹 캐스팅을 위해 virtual 함수를 하였다.
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
