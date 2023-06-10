//#include <iostream>
//#include <list>
//#include <forward_list>
//
//template<typename T>
//void display(const T& container) {
//	/*  for (auto it = container.begin(); it != container.end(); it = std::next(it)) {
//		  std::cout << *it << " ";
//	  }
//	  std::cout << std::endl;*/
//
//	for (auto u : container)
//		std::cout << u << " ";
//	std::cout << std::endl;
//}
//
//int main()
//{
//	// create a list of integers
//	std::list<int> mylist = { 1, 2, 3, 4, 5 };
//
//	// insert an element at the beginning
//	mylist.insert(mylist.begin(), 0);
//	display(mylist);
//
//	// insert an element at position 3
//	mylist.insert(std::next(mylist.begin(), 3), 10);
//	display(mylist);
//
//	// insert three elements with the value 7 at the beginning
//	mylist.insert(mylist.begin(), 3, 7);
//	display(mylist);
//
//	// insert elements from another list
//	std::list<int> otherlist = { 6, 7, 8 };
//	mylist.insert(std::next(mylist.begin(), 2), otherlist.begin(), otherlist.end());
//	display(mylist);
//
//	// erase an element at position 2
//	mylist.erase(std::next(mylist.begin(), 2));
//	display(mylist);
//
//	// erase elements in the range [3,5)
//	mylist.erase(std::next(mylist.begin(), 3), std::next(mylist.begin(), 5));
//	display(mylist);
//
//	// swap the contents of two lists
//	std::list<int> anotherlist = { 9, 10, 11 };
//	mylist.swap(anotherlist);
//	display(mylist);
//
//	// resize the list to contain 10 elements set new element to 0
//	mylist.resize(10);
//	display(mylist);
//
//	// resize the list and set the new elements to 20
//	mylist.resize(12, 20);
//	display(mylist);
//
//	// clear the contents of the list
//	mylist.clear();
//	display(mylist);
//
//	// splice the contents of another list into the current list
//	std::list<int> splicelist = { 1, 2, 3, 4, 5,3,3,3,3 };
//	mylist.splice(mylist.begin(), splicelist);
//	display(mylist);
//
//	// remove all elements with the value 3
//	mylist.remove(3);
//	display(mylist);
//
//	// remove all even elements
//	mylist.remove_if([](int i) -> bool { return i % 2 == 0; });
//	display(mylist);
//
//	// reverse the order of the elements
//	mylist.reverse();
//	display(mylist);
//
//	// list assignment
//	mylist = { 9,8,7,5,5,5,3,3,2,2,1,1,5,5,6,6,6,6,9,9,9,8,8,8,7,7 };
//	display(mylist);
//
//
//	// sort the elements in ascending order
//	mylist.sort();
//	display(mylist);
//
//	// remove all consecutive duplicate elements
//	mylist.unique();
//	display(mylist);
//
//	// sort the elements in descending order
//	mylist.sort([](int a, int b) { return a > b; });
//	display(mylist);
//
//	// create a forward list of integers
//	std::forward_list<int> forwardlist = { 1, 2, 3, 4, 5 };
//	display(forwardlist);
//
//	//// splice the contents of the forward list into the current list
//	//mylist.splice_after(mylist.before_begin(), forwardlist);
//
//	//return 0;
//}
