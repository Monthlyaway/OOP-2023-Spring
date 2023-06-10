#include "Student_info.h"
using namespace std;

bool compare(const Student_info& x, const Student_info& y)
{
	return x.name < y.name;
}

ifstream& read(ifstream& infile, Student_info& student)
{
	infile >> student.name >> student.midterm >> student.final;
	cout << "Reading " << student.name << " Info..." << endl;
	student.homework.clear();
	read_hw(infile, student.homework);
	return infile;
}

ifstream& read_hw(ifstream& infile, vector<double>& homework)
{
	double dtp;
	/*for (int i = 0; i < 6; i++)
	{
		infile >> dtp;
		homework.push_back(dtp);
	}*/
	while (infile >> dtp)
		homework.push_back(dtp);
	
	return infile;
}