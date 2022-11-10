#include <iostream>
#include <cassert>
using namespace std;

class CEO {
public:
	CEO() {};
	virtual void a() {};
};

class CPO : public CEO {
public:
	CPO() {};
};

class Manager : public CEO, public CPO {
public:
	Manager() {};
};

class Staff : public Manager  {
public:
	Staff() {};
};

int main() {
	CPO* cpo = new Staff();
	Staff* staff = dynamic_cast<Staff*>(cpo);
	Manager* manager = dynamic_cast<Manager*>(cpo);
	CEO* ceo = dynamic_cast<CEO*>(cpo);
	
	assert(typeid(cpo) == typeid(Staff*));

	delete c;
	return 0;
}