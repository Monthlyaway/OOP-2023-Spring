/* **************************************************************
 * TIP1: How to use the debug.h:
 * **************************************************************
 * 
 * 1. Include the debug.h header file in your source code using the following line:
 *    #include "debug.h"
 *
 * 2. Use the DEBUG_OUTPUT macro to print debug messages to the console. For example:
 *    int x = 5;
 *    DEBUG_OUTPUT("The value of x is " << x);
 *    This will print "Debug output: The value of x is 5" to the console.
 *
 * 3. If you want to temporarily disable debug messages, you can comment out the #define DEBUG line
 *    in the source code file by adding // at the beginning of the line.
 *
 * 4. If you want to enable debug messages again, just remove the // from the #define DEBUG line.
 *
 * 5. If you want to disable all debug messages at the same time, comment out the #define DEBUG_OUTPUT(x) std::cout << "Debug output: " << x << std::endl line in debug.h and write #define DEBUG_OUTPUT(x) on the next line
 * 
 * For more information, see debug.h and https://stackoverflow.com/questions/14251038/debug-macros-in-c
 * 
 * That's it! The debug.h header file provides a simple way to add and remove debug messages from your code.
 * 
 * **************************************************************
 * TIP2: How to input from Clipboard
 * **************************************************************
 * 
 * 1. After the console says: Input students' information, copy the students' information into the console
 * 
 * 2. Press Ctrl^z on a new line to simulate eof
 */



#pragma warning(disable: 4786)
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <stdexcept>
#include <map>
#include "algorithm.h"
#include "grade.h"
#include "Student_info.h"
#include "analysis.h"
using namespace std;

void write_analysis(ostream & out,  const string & name, 
			double analysis(const vector<Student_info>&),  			const vector<Student_info> & did, 
			const vector<Student_info> & didnt)
{
	out << name << ": median(did) =" << analysis(did) <<
		", median(didnt) = " << analysis(didnt) << endl;
}

int main() 
{ 
	ifstream infile(".\\ZhouYaQian-OOP\\hw3\\hw3_input.txt");
	vector<Student_info> did, didnt;
	Student_info record;
	cout << "\033[1;36m----------------------------------------\n"
		<< "\033[1;36m      Input students' information:\n"
		<< "\033[1;36m----------------------------------------\n"
		<< "\033[0m" << endl;


	if (infile) {
		cout << "\033[1;31mhw3_input.txt is opened successfully. File operation recommended.\n" << "replace while(read(cin, record)) with while(read(infile, record)) to read from hw3_input.txt directly." << "\033[0m" << endl;
	}


	while(read(infile, record)){
		if(did_all_hw(record))
			did.push_back(record);
		else
			didnt.push_back(record);
	}
	write_analysis(cout,"median",median_analysis,did,didnt);
	write_analysis(cout,"average",average_analysis,did,didnt);
	write_analysis(cout,"median of homework turned in",optimistic_median_analysis,did,didnt);

	infile.close();
	return 0; 
}
