//#include <iostream>
//#include <vector>
//#include <random>
//#include <algorithm>
//
//using namespace std;
//
//vector<int> initialize_vector(int size) {
//	vector<int> v(size);
//	random_device rd;
//	mt19937 gen(rd());
//	uniform_int_distribution<int> dis(1, 100);
//	for (int i = 0; i < size; ++i) {
//		v[i] = dis(gen);
//	}
//	return v;
//}
//
//void ex1(void)
//{
//	vector<int> ivec;
//	for (int i = 0; i < 10; i++)
//	{
//		ivec.push_back(i);
//	}
//	for (int i = 0; i < 10; i++)
//	{
//		cout << ivec[i] << " ";
//	}
//	cout << endl;
//}
//
//void ex2(void)
//{
//	vector<int> ivec1{ 1,2,3,4,5,6,7,8,9 };
//	vector<int> ivec2{ 10,11,12,13,14,15,16,17 };
//
//	cout << "original\nivec1: " << endl;
//	for (auto i : ivec1)
//		cout << i << " ";
//	cout << endl;
//	cout << "ivec2: " << endl;
//	for (auto i : ivec2)
//		cout << i << " ";
//	cout << endl;
//
//	// swap
//	auto tp = ivec1.at(0);
//	ivec1.at(0) = ivec2.at(0);
//	ivec2.at(0) = tp;
//
//	cout << "\n\nswapped\nivec1: " << endl;
//	for (auto i : ivec1)
//		cout << i << " ";
//	cout << endl;
//	cout << "ivec2: " << endl;
//	for (auto i : ivec2)
//		cout << i << " ";
//	cout << endl;
//
//
//}
//
//void ex3(void)
//{
//	vector<int> ivec1{ 1,2,3,4,5,6,7,8,9,10 };
//	for (auto i : ivec1)
//		cout << i << " ";
//	cout << endl;
//	ivec1.erase(ivec1.begin());
//	ivec1.pop_back();
//	for (auto i : ivec1)
//		cout << i << " ";
//	cout << endl;
//}
//
//void ex4(void)
//{
//	vector<int> ivec1{ 1,2,3,4,5,6,7,8,9 };
//	vector<int> ivec2{ 10,11,12,13,14,15,16,17 };
//
//	ivec1.insert(ivec1.end(), ivec2.begin(), ivec2.end());
//	for (auto i : ivec1)
//		cout << i << " ";
//	cout << endl;
//}
//
//void ex5(void)
//{
//	vector<int> ivec = initialize_vector(10);
//	sort(ivec.begin(), ivec.end());
//	for (auto i : ivec)
//		cout << i << " ";
//	cout << endl;
//}
//
//int main(void)
//{
//	//ex1();
//	//ex2();
//	//ex3();
//	//ex4();
//	ex5();
//
//	return 0;
//}