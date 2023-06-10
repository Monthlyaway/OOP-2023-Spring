#pragma warning(disable: 4786)
#include <iostream>
#include <stdio.h>
#include <string>
#include <iomanip>
#include <stdexcept>
#include <algorithm>
#include <map>
#include "grade.h"
#include "Student_info.h"
#include "Vec.h"
using namespace std;

void extract_levels(Vec<Student_info>& students, map<string, int>& levels)
{
	//for (Vec<Student_info>::iterator iter = students.begin(); iter != students.end(); iter++) {
	//	string lv = iter->level();
	//	auto it = levels.find(lv);
	//	if (it == levels.end()) {
	//		levels.insert(pair<string, int>(lv, 1));
	//		// in case level type is changed in the future
	//	}
	//	else {
	//		it->second++;
	//	}
	//}
	for (auto u : students) {
		levels[u.level()]++;
	}
}

int main()
{
	map<string, int> levels;
	Vec<Student_info> students, fails;
	Student_info record;
	string::size_type maxlen = 0;

	while (record.read(cin)) {
		if (record.name().size() > maxlen)
			maxlen = record.name().size();
		students.push_back(record);
	}
	//sort(students.begin(),students.end(),compare);
	try {
		extract_levels(students, levels);
		for (map<string, int>::const_iterator i = levels.begin(); i != levels.end(); i++) {
			cout << i->first << "\t"
				<< i->second << endl;
		}
	}
	catch (domain_error e) {
		cout << e.what();
	}
	return 0;
}
