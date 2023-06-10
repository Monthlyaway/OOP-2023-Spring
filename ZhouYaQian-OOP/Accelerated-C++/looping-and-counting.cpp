#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

void prog2_1() {
	const string::size_type cols = 0;
}

void prog2_2() {
	// ask for the person¡¯s name 
	cout << "Please enter your first name: ";
	// read the name 
	string name;
	cin >> name;
	// build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	// the number of blanks surrounding the greeting 
	const int pad = 1;
	// the number of rows and columns to write 
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	// write a blank line to separate the output from the input 
	cout << endl;
	// write rows rows of output 
	// invariant: we have written r rows so far 
	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		// invariant: we have written c characters so far in the current row 
		while (c != cols) {
			// is it time to write the greeting? 
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				// are we on the border? 
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
}

void ex2_1() {
	// ask for the person¡¯s name 
	cout << "Please enter your first name: ";
	// read the name 
	string name;
	cin >> name;
	// build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	// the number of blanks surrounding the greeting 
	const int pad = 0;
	// the number of rows and columns to write 
	const int rows = pad * 2 + 3;
	const string::size_type cols = greeting.size() + pad * 2 + 2;
	// write a blank line to separate the output from the input 
	cout << endl;
	// write rows rows of output 
	// invariant: we have written r rows so far 
	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		// invariant: we have written c characters so far in the current row 
		while (c != cols) {
			// is it time to write the greeting? 
			if (r == pad + 1 && c == pad + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				// are we on the border? 
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
}

void ex2_2() {
	// ask for the person¡¯s name 
	cout << "Please enter your first name: ";
	// read the name 
	string name;
	cin >> name;
	// build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	// the number of blanks surrounding the greeting 
	const int pad_vertic = 1;
	const int pad_horizt = 5;

	// the number of rows and columns to write 
	const int rows = pad_vertic * 2 + 3;
	const string::size_type cols = greeting.size() + pad_horizt * 2 + 2;

	// write a blank line to separate the output from the input 
	cout << endl;
	// write rows rows of output 
	// invariant: we have written r rows so far 
	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		// invariant: we have written c characters so far in the current row 
		while (c != cols) {
			// is it time to write the greeting? 
			if (r == pad_vertic + 1 && c == pad_horizt + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				// are we on the border? 
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
}

void ex2_4() {
	// ask for the person¡¯s name 
	cout << "Please enter your first name: ";
	// read the name 
	string name;
	cin >> name;
	// build the message that we intend to write 
	const string greeting = "Hello, " + name + "!";
	// the number of blanks surrounding the greeting 
	const int pad_vertic = 1;
	const int pad_horizt = 5;

	// the number of rows and columns to write 
	const int rows = pad_vertic * 2 + 3;
	const string::size_type cols = greeting.size() + pad_horizt * 2 + 2;
	const string spaces_all_in_one(cols - 2, ' ');

	// write a blank line to separate the output from the input 
	cout << endl;
	// write rows rows of output 
	// invariant: we have written r rows so far 
	for (int r = 0; r != rows; ++r)
	{
		string::size_type c = 0;
		// invariant: we have written c characters so far in the current row 
		while (c != cols) {
			// is it time to write the greeting? 
			if (r == pad_vertic + 1 && c == pad_horizt + 1)
			{
				cout << greeting;
				c += greeting.size();
			}
			else
			{
				// are we on the border? 
				if (r == 0 || r == rows - 1 || c == 0 || c == cols - 1)
					cout << "*";
				else
					cout << " ";
				++c;
			}
		}
		cout << endl;
	}
}

void draw(int size, string str) {
	for (int ix = 0; ix < size; ix++) {
		cout << str;
	}
}

void draw(string shape, char ch, int a = 5, int b = 5) {
	transform(shape.begin(), shape.end(), shape.begin(), std::tolower);
	int pad = 2;
	string padd(pad, ' ');
	if (shape == "square") {
		string length;
		string token(1, ch);
		token += " ";
		for (int ix = 0; ix < a; ix++)
			length += token;
		const string spaces(2 * a - 3, ' ');
		cout << endl << padd << length << '\n';
		for (int ix = 2; ix < a; ix++)
		{
			cout << padd << ch << spaces << ch << '\n';
		}
		cout << padd << length << endl;
	}
	else if (shape == "triangle") {
		string token(1, ch), spaces(1, ' ');
		cout << endl;
		cout << padd;
		draw(a - 1, spaces);
		draw(1, token);
		cout << endl;
		for (int row = 2; row < a; row++) {
			cout << padd;
			draw(a - row, spaces);
			draw(1, token);
			draw(2 * row - 3, spaces);
			draw(1, token);
			cout << endl;
		}
		token += " ";
		cout << padd;
		draw(a, token);
		cout << endl;

	}
	else if (shape == "rectangle") {

		string width, token(1, ch);
		token += " ";
		for (int ix = 0; ix < b; ix++)
			width += token;
		const string spaces(2 * b - 3, ' ');
		cout << "\n" << width << "\n";
		for (int row = 2; row < a; row++) {
			cout << ch << spaces << ch << "\n";
		}
		cout << width << "\n";

	}
	else {
		cerr << "Error: Can not draw " << shape << endl;
	}
}

void ex2_5() {
	// Write a set of ¡®¡®*¡¯¡¯ characters so that 
	// they form a square, a rectangle, and a triangle.
	draw("square", '*');
	draw("triangle", '*', 6);
	draw("triangle", '*', 7);
	draw("rectangle", '^', 5, 10);
}

int main(void)
{
	//prog2_1();
	//prog2_2();
	//ex2_1();
	//ex2_2();
	//ex2_4();
	ex2_5();

	return 0;
}