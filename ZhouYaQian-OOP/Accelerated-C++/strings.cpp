#include <iostream>
#include <string>

using namespace std;
void prog1()
{
	// ask for a person’s name, and generate a framed greeting

	std::cout << "Please enter your first name: ";
	std::string name;
	std::cin >> name;
	// build the message that we intend to write
	const std::string greeting = "Hello, " + name + "!";
	// build the second and fourth lines of the output
	const std::string spaces(greeting.size(), ' ');
	const std::string second = "* " + spaces + " *";
	// build the first and fifth lines of the output
	const std::string first(second.size(), '*');
	// write it all
	std::cout << std::endl;
	std::cout << first << std::endl;
	std::cout << second << std::endl;
	std::cout << "* " << greeting << " *" << std::endl;
	std::cout << second << std::endl;
	std::cout << first << std::endl;
}

void ex2()
{
	const string hello = "Hello";
	const string message = hello + ", World" + "!";
	cout << message;
}

void ex3()
{
	// different scope
	{
		const std::string s = "a string";
		std::cout << s << std::endl;
	}
	{
		const std::string s = "another string";
		std::cout << s << std::endl;
	}
}

void ex4()
{
	// hiding
	{ const std::string s = "a string"; std::cout << s << std::endl; { const std::string s = "another string"; std::cout << s << std::endl; }}
}

void ex5()
{
	{ std::string s = "a string"; { std::string x = s + ", really"; std::cout << s << std::endl;  std::cout << x << std::endl; }}
}

void ex6()
{
	std::cout << "What is your name? ";
	std::string name;
	std::cin >> name;
	std::cout << "Hello, " << name
		<< std::endl << "And what is yours? ";
	std::cin >> name;
	std::cout << "Hello, " << name
		<< "; nice to meet you too!" << std::endl;
}

int main(void)
{
	//prog1();
	//ex2();
	//ex3();
	//ex4();
	//ex5();
	//ex6();


	return 0;
}