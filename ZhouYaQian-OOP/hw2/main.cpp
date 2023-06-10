/*
* read from file hw2_input.txt
* extract midterm and final term to Student_info
* calculate median and average
* calculate grade
* extract_fails
* output the name of failed students in alphabetical order
*/
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <list>
#include "grade.h"
#include "Student_info.h"
using namespace std;

list<Student_info> extract_fails(list<Student_info>& students)
{
	if (!students.size())
	{
		cerr << "Error: Student list is empty" << endl;
		exit(EXIT_FAILURE);
	}

	list<Student_info> failed_students;
	list<Student_info>::const_iterator iter = students.begin();
	list<Student_info>::const_iterator end = students.end();
	for (; iter != end; iter++)
	{
		if (fgrade(*iter))
		{
			failed_students.push_back(*iter);
			cout << iter->name << " failed" << endl;
		}
	}
	return failed_students;
}


int main(int argc, char* argv[])
{
	if (argc < 2)
	{
		cerr << "Please provide a file name." << endl;
		exit(EXIT_FAILURE);
	}
	for (int a = 1; a < argc; a++)
	{
		string infilename(argv[a]);
		ifstream infile(infilename);

		// extract input file name without extension
		string base_name = infilename.substr(0, infilename.find_last_of("."));
		// create output file name
		string outfilename = base_name + "_result.txt";
		ofstream outfile(outfilename);

		if (!infile.is_open() || !outfile.is_open())
		{
			cerr << "Error: could not open file" << endl;
			exit(EXIT_FAILURE);
		}

		cout << "outfilename: " << outfilename << endl;

		// initialize the list
		list<Student_info> students;
		Student_info stu_temp;

		while (!read(infile, stu_temp).eof())
		{
			students.push_back(stu_temp);
			infile.clear();
		}
		// handle the last line because infile encounters EOF
		// which leaves the stu_temp not pushed to list
		students.push_back(stu_temp);

		// sort before hand so that elements in list:failed will
		// be in order
		// sort by name
		students.sort(compare);

		list<Student_info> failed_students = extract_fails(students);

		list<Student_info>::const_iterator iter = failed_students.begin();
		list<Student_info>::const_iterator end = failed_students.end();
		streamsize prec = cout.precision();
		for (iter = failed_students.begin(); iter != end; iter++)
			outfile << left << setw(10) << iter->name
			<< "    Your final grade is " << fixed << setprecision(1)
			<< grade(*iter) << setprecision(prec) << endl;

		/*specify the width of a column of output so that it is slightly wider
		than the longest element of the column.*/

		cout << "Bye!" << endl;
		infile.close();
		outfile.close();
	}
	return 0;
}
