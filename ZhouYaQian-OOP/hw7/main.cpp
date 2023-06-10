#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable: 4786)
#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <map>
#include "Student_info.h"
#include "Vec.h"
using namespace std;

int main()
{
	/*freopen("hw7_input.txt", "r", stdin);
	freopen("hw7_output.txt", "w", stdout);*/
	
	Vec<Student_info> students;
	Student_info record;
	char ch;
	string::size_type maxlen = 0;
	while (record.read(cin)) {
		if (record.name().size() > maxlen) 
			maxlen = record.name().size();
		students.push_back(record);
	}
	sort(students.begin(), students.end(), Student_info::compare);
	for (Vec<Student_info>::iterator iter = students.begin(); 
		iter != students.end(); iter++) 
	{
		cout << iter->name() 
			<< string(maxlen + 1 - iter->name().size(), ' ');
		try {
			double final_grade = iter->grade();
			streamsize prec = cout.precision(3);
			cout << "Your final grade is " << setprecision(3)
				<< final_grade << setprecision(prec) << endl;
		}
		catch (domain_error e) {
			cout << e.what();
		}
	}
	return 0;
}
