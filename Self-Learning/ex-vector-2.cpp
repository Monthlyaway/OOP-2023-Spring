//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//
//using namespace std;
//
//// Exercise 1
//void ex1() {
//    vector<int> v = { 1, 2, 3, 4, 5 };
//    vector<int>::iterator it;
//
//    // using the begin() and end() member functions
//    cout << "Elements of the vector: ";
//    for (it = v.begin(); it != v.end(); ++it) {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    // using the empty() member function
//    if (v.empty()) {
//        cout << "The vector is empty" << endl;
//    }
//    else {
//        cout << "The vector is not empty" << endl;
//    }
//
//    // using the size() member function
//    cout << "The size of the vector is: " << v.size() << endl;
//
//    // using the max_size() member function
//    cout << "The maximum number of elements the vector can hold is: " << v.max_size() << endl;
//
//    // using the reserve() member function
//    v.reserve(10);
//    cout << "The capacity of the vector after reserving space for 10 elements is: " << v.capacity() << endl;
//
//    // using the shrink_to_fit() member function
//    v.shrink_to_fit();
//    cout << "The capacity of the vector after calling shrink_to_fit() is: " << v.capacity() << endl;
//}
//
//// Exercise 2
//void ex2() {
//    vector<int> v = { 1, 2, 3, 4, 5 };
//
//    // using the push_back() member function
//    v.push_back(6);
//
//    // using the emplace_back() member function
//    v.emplace_back(7);
//
//    // using the insert() member function
//    v.insert(v.begin() + 2, 10);
//
//    // using the erase() member function
//    v.erase(v.begin() + 4);
//
//    // using the clear() member function
//    v.clear();
//
//    // using the assign() member function
//    v.assign(5, 0);
//
//    // using the emplace() member function
//    v.emplace(v.begin(), 1);
//
//    // using the emplace_back() member function
//    v.emplace_back(2);
//
//    // using the pop_back() member function
//    v.pop_back();
//
//    // using the resize() member function
//    v.resize(8, 1);
//
//    // using the swap() member function
//    vector<int> v2 = { 10, 20, 30 };
//    v.swap(v2);
//
//    // using the emplace_back() member function
//    v.emplace_back(3);
//
//    // using the unique() member function
//    v.erase(unique(v.begin(), v.end()), v.end());
//
//    // printing the final vector
//    cout << "The elements of the final vector are: ";
//    for (int i = 0; i < v.size(); i++) {
//        cout << v[i] << " ";
//    }
//    cout << endl;
//}
//
//// Exercise 3
//void ex3() {
//    vector<int> v1 = { 1, 2, 3, 4, 5 };
//    vector<int> v2 = { 4, 5, 6, 7, 8 };
//    vector<int>::iterator it;
//    vector<int>::iterator it2;
//
//    // using the assign() member function
//    v1.assign({ 10, 20, 30 });
//
//    // using the operator[] member function
//    cout << "The element at index 2 of vector
