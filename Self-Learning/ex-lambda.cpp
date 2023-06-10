//#include <iostream>
//#include <string>
//#include <vector>
//#include <algorithm>
//
////#define DEBUG
//#ifdef DEBUG
//#define DEBUG_OUTPUT(x) cout << "Debug output: " << x << endl;
//#else
//#define DEBUG_OUTPUT(x)
//#endif // DEBUG
//
//
//using namespace std;
//
//void ex1(void)
//{
//	/*Write a lambda function that takes a string as input and returns the number of vowels in the string.*/
//
//	string str("AeiOu");
//	int vowels_count = 0;
//
//	auto count_vowels_in_string = [&vowels_count](string str) {
//		// count_vowels_in_string is a funtion object that stores the lambda function
//		for (auto ch : str)
//			// each element in a string is a c char
//		{
//			ch = tolower(ch);
//			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
//				vowels_count++;
//			//cout << "str: " << str << endl;
//		}
//		return vowels_count;
//	};
//
//	cout << "Number of vowels in \"" << str << "\" is: " << count_vowels_in_string(str) << endl;
//}
//
//void ex2(void)
//{
//	/*Given a vector of integers, write a lambda function that returns the sum of all even integers in the vector.*/
//	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
//	int sum_of_even = 0;
//
//	auto calculate_sum_of_even = [](vector<int> vec) {
//		int sum_of_even = 0;
//		for (auto i : vec)
//		{
//			if (i % 2 == 0)
//				sum_of_even += i;
//		}
//		return sum_of_even;
//	};
//
//	cout << "sum of even integers: " << calculate_sum_of_even(ivec) << endl;
//	
//}
//
//void ex3(void)
//{
//	/*Write a lambda function that takes two vectors of integers and returns a new vector containing the intersection of the two input vectors (i.e., the elements that are common to both vectors).*/
//
//	vector<int> v1{ 1,2,3,4,5,6,7 }, v2{ 2,5,6,9,7,3 };
//	auto intersect_vectors = [](vector<int> v1, vector<int> v2) {
//
//		vector<int> new_vec;
//
//		sort(v1.begin(), v1.end());
//		sort(v2.begin(), v2.end());
//
//
//		set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(new_vec));
//
//		return new_vec;
//	};
//
//	vector<int> new_vec = intersect_vectors(v1, v2);
//
//	cout << "v1: ";
//	for (auto u : v1)
//		cout << u << " ";
//	cout << endl;
//	cout << "v2: ";
//	for (auto u : v2)
//		cout << u << " ";
//	cout << endl;
//	cout << "new_vec: ";
//	for (auto u : new_vec)
//		cout << u << " ";
//	cout << endl;
//}
//
//int main(void)
//{
//	//ex1();
//	//ex2();
//	ex3();
//
//	return 0;
//}