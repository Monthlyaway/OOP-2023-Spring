#include <iostream>

using namespace std;

class A
{
public:
	void f() {
		cout << "A::f()" << endl;
	}
protected:
	void g() {
		cout << "A::g()" << endl;

	}
private:
	void h() {
		cout << "A::h()" << endl;

	}
};
class B : protected A
{
public:
	void q()
	{
		f(); //?
		g(); //?
	}
};

int main(void) {
	A a;
	B b;
	a.f();
	b.q();
	
	return 0;
}