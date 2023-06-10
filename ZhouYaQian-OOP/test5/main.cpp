#include<iostream>
//#include<stack>
#include"stack.h"
using namespace std;


void homework(void) {
	myStack<int> s;
	int num;

	cout << "------Test for Stack-------" << endl;
	cout << "Input number:" << endl;

	while (cin >> num)
	{
		s.push(num);
	}

	cout << "The Stack has " << s.size() << " numbers.\nThey are:" << endl;
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << "\nNow the size is " << s.size() << endl;
}

void test_copy_constructor(void) {
	myStack<int> stack;

	// Push some values onto the stack
	stack.push(10);
	stack.push(20);
	stack.push(30);

	// Test random access using operator[]
	std::cout << "stack[0]: " << stack[0] << std::endl;
	std::cout << "stack[1]: " << stack[1] << std::endl;
	std::cout << "stack[2]: " << stack[2] << std::endl;

	// Modify a value using operator[]
	stack[1] = 25;
	std::cout << "stack[1] after modification: " << stack[1] << std::endl;

	stack.clear();
	cout << "stack.clear()" << endl;
	for (int ix = 0; ix < 10; ix++)
		stack.push(ix);
	cout << "stack[5]: " << stack[5] << endl;
}


int main()
{
	//这是作业
	homework();

	//这是我自己写的
	//test_copy_constructor();
	return 0;
}
