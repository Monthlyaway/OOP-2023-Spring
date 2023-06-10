# Vector

## exercises

1. Write a program that creates a vector of integers and adds 10 elements to it. Then, iterate through the vector and print out each element.
2. Write a program that creates two vectors of integers and adds 10 elements to each vector. Then, use the vector member function `at()` to access the first element of each vector and swap them.
3. Write a program that creates a vector of integers and adds 10 elements to it. Then, use the vector member function `erase()` to remove the first element and the last element of the vector.
4. Write a program that creates a vector of integers and adds 10 elements to it. Then, use the vector member function `insert()` to insert a new element at the beginning of the vector and another new element at the end of the vector.
5. Write a program that creates a vector of integers and adds 10 elements to it. Then, use the vector member function `sort()` to sort the elements in ascending order.

```c++
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

vector<int> initialize_vector(int size) {
	vector<int> v(size);
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(1, 100);
	for (int i = 0; i < size; ++i) {
		v[i] = dis(gen);
	}
	return v;
}

void ex1(void)
{
	vector<int> ivec;
	for (int i = 0; i < 10; i++)
	{
		ivec.push_back(i);
	}
	for (int i = 0; i < 10; i++)
	{
		cout << ivec[i] << " ";
	}
	cout << endl;
}

void ex2(void)
{
	vector<int> ivec1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> ivec2{ 10,11,12,13,14,15,16,17 };

	cout << "original\nivec1: " << endl;
	for (auto i : ivec1)
		cout << i << " ";
	cout << endl;
	cout << "ivec2: " << endl;
	for (auto i : ivec2)
		cout << i << " ";
	cout << endl;

	// swap
	auto tp = ivec1.at(0);
	ivec1.at(0) = ivec2.at(0);
	ivec2.at(0) = tp;

	cout << "\n\nswapped\nivec1: " << endl;
	for (auto i : ivec1)
		cout << i << " ";
	cout << endl;
	cout << "ivec2: " << endl;
	for (auto i : ivec2)
		cout << i << " ";
	cout << endl;


}

void ex3(void)
{
	vector<int> ivec1{ 1,2,3,4,5,6,7,8,9,10 };
	for (auto i : ivec1)
		cout << i << " ";
	cout << endl;
	ivec1.erase(ivec1.begin());
	ivec1.pop_back();
	for (auto i : ivec1)
		cout << i << " ";
	cout << endl;
}

void ex4(void)
{
	vector<int> ivec1{ 1,2,3,4,5,6,7,8,9 };
	vector<int> ivec2{ 10,11,12,13,14,15,16,17 };

	ivec1.insert(ivec1.end(), ivec2.begin(), ivec2.end());
	for (auto i : ivec1)
		cout << i << " ";
	cout << endl;
}

void ex5(void)
{
	vector<int> ivec = initialize_vector(10);
	sort(ivec.begin(), ivec.end());
	for (auto i : ivec)
		cout << i << " ";
	cout << endl;
}

```

## `remove_if()`

```c++
std::vector<int> myVector = {1, 2, 3, 4, 5};
myVector.erase(std::remove_if(myVector.begin(), myVector.end(),
                              [](int x) { return x % 2 == 0; }),
                myVector.end());

```

- `std::remove_if()` is a standard library algorithm that takes a range of elements and a predicate function as arguments. It returns an iterator to the first element in the range that does not satisfy the predicate. 
- The lambda function `[](int x) { return x % 2 == 0; }` is a shorthand way of defining a function object that tests whether an integer is even (i.e., has a remainder of zero when divided by 2).
- The expression `myVector.erase()` removes elements from the vector. It takes two arguments: the first is an iterator to the first element to be removed, and the second is an iterator to the element one past the last one to be removed.

So what the example is doing is:

1. Applying the `std::remove_if()` algorithm to the range of elements in `myVector`, using the lambda function to test for even numbers. This returns an iterator to the first element in the range that is not even.
2. Passing the iterator returned by `std::remove_if()` and `myVector.end()` to `myVector.erase()`. This removes all the elements in the range from the first non-even element to the end of the vector.

# Vector Member Function Syntax

## Basic Operations

### Constructor

```c++
// Creates an empty vector
vector();
// Creates a vector with n elements, each initialized to a default value
vector(size_t n);
// Creates a vector with n elements, each initialized to value
vector(size_t n, const T& value);
// Creates a vector with the elements of the range [first, last)
vector(InputIterator first, InputIterator last);
// Copy constructor
vector(const vector& other);
// Move constructor
vector(vector&& other) noexcept;
```

#### Move constructor

The line `vector(vector&& other) noexcept;` is the syntax for the move constructor of the `std::vector` class in C++.

A move constructor is a special constructor that creates a new object by stealing the resources (memory, file handles, network sockets, etc.) of an existing object, typically a temporary object.

In the case of the `std::vector` class, the move constructor creates a new vector by "stealing" the contents of another vector. This can be very useful in cases where creating a copy of the vector would be too expensive or unnecessary.

The `&&` notation indicates that the move constructor takes an rvalue reference as a parameter, which allows it to efficiently move the contents of the other vector. The `noexcept` keyword indicates that the move constructor does not throw any exceptions, which is a requirement for certain types of optimization in C++11 and later.

In summary, the move constructor of the `std::vector` class is a special constructor that creates a new vector by efficiently moving the contents of another vector, and is declared with the syntax `vector(vector&& other) noexcept;`.

`&&` is an operator in C++ called "rvalue reference". It is used in move semantics to transfer the ownership of a resource (like memory) from one object to another, without copying it.

In C++, variables can be categorized as lvalues or rvalues. An lvalue is an expression that has an address in memory and can be assigned a value, while an rvalue is an expression that doesn't have an address in memory and can't be assigned a value. For example, a variable is an lvalue, and a literal (like the number 5) is an rvalue.

When we create an object in C++, it is either an lvalue or an rvalue. An object that is going to be destroyed (like a temporary object) is an rvalue. By using `&&` in a function parameter or a constructor parameter, we are telling the compiler that the function or constructor is capable of accepting rvalues as arguments.

In the case of the move constructor `vector(vector&& other) noexcept;`, the `&&` indicates that the constructor takes an rvalue reference to another vector object, allowing it to transfer ownership of the resources of the source vector to the new vector without copying them. This makes it much more efficient than copying, especially for large vectors. The `noexcept` keyword indicates that the move constructor won't throw any exceptions.

```c++
#include <iostream>

void foo(int&& x)
{
    std::cout << "x: " << x << std::endl;
}

int main()
{
    int a = 42;
    foo(std::move(a)); // using std::move to cast 'a' to an rvalue reference
    return 0;
}

```

In this example, `foo` is a function that takes an rvalue reference to an integer (`int&&`). The `std::move` function is used to cast the variable `a` to an rvalue reference, allowing it to be passed to `foo`. When `foo` is called, the value of `a` is printed to the console.

Note that `std::move` doesn't actually move anything - it simply casts its argument to an rvalue reference. It's up to the function that receives the rvalue reference to decide what to do with it.

```c++
#include <iostream>
#include <vector>

class MyData {
public:
    MyData() {
        m_data = new int[1000000]; // Allocate a large array of integers
        for (int i = 0; i < 1000000; i++) {
            m_data[i] = i;
        }
    }

    ~MyData() {
        delete[] m_data; // Release the allocated memory
    }

    // Copy constructor
    MyData(const MyData& other) {
        m_data = new int[1000000]; // Allocate new memory for the copy
        for (int i = 0; i < 1000000; i++) {
            m_data[i] = other.m_data[i];
        }
    }

    // Move constructor
    MyData(MyData&& other) noexcept {
        m_data = other.m_data; // Take ownership of the other object's memory
        other.m_data = nullptr; // Set the other object's pointer to null
    }

private:
    int* m_data;
};

int main() {
    std::vector<MyData> vec1(100); // Create a vector with 100 MyData objects

    // Copy vec1 to vec2
    std::vector<MyData> vec2(vec1); // Copy constructor is called

    // Move vec1 to vec3
    std::vector<MyData> vec3(std::move(vec1)); // Move constructor is called

    return 0;
}
```

In the example above, `MyData` is a class that contains a large array of integers. The copy constructor allocates a new array and copies the elements one by one, which can be very slow for large data. On the other hand, the move constructor simply takes ownership of the other object's memory and sets its pointer to null, which is very fast.

When we create `vec1`, `vec2`, and `vec3`, we allocate memory for 100 `MyData` objects. When we copy `vec1` to `vec2`, the copy constructor is called, which allocates new memory for the 100 objects and copies each one individually. This can be very slow for large data.

However, when we move `vec1` to `vec3`, the move constructor is called, which simply takes ownership of the 100 `MyData` objects in `vec1`. This is much faster than copying each object individually.

Overall, move semantics can be more efficient than copying, especially for large data, because it avoids unnecessary copying of data.



### Assignment Operator

```c++
// Assigns the elements of other to this vector
vector& operator=(const vector& other);
// Moves the elements of other to this vector
vector& operator=(vector&& other) noexcept;
```



### Element Access

```c++
// Returns a reference to the element at position n
T& operator[](size_t n);
const T& operator[](size_t n) const;
// Returns a reference to the first element
T& front();
const T& front() const;
// Returns a reference to the last element
T& back();
const T& back() const;
// Returns a pointer to the underlying array
T* data() noexcept;
const T* data() const noexcept;
```

#### `data()`

In programming, an array is a collection of elements of the same data type stored in contiguous memory locations. It provides a way to store multiple elements of the same type under a single variable name.

For example, to declare an integer array of size 5, we can write:

```c++
int arr[5];
```

This creates an integer array named `arr` with five elements. The first element is accessed using `arr[0]`, the second using `arr[1]`, and so on.

Now, regarding the `data()` member function of the `std::vector` class, it returns a pointer to the underlying array used by the vector to store its elements. This can be useful when we need to pass the contents of a vector to a function that accepts a pointer to an array.

Since the underlying array of a vector is guaranteed to be contiguous, we can use the `data()` function to get a pointer to the first element and pass it to the function as an argument.

Here's an example:

```c++
#include <iostream>
#include <vector>

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> vec {1, 2, 3, 4, 5};
    
    int* arr = vec.data();  // Get pointer to underlying array
    
    printArray(arr, vec.size());  // Pass pointer and size to function
    
    return 0;
}
```

In this example, we create a vector of integers named `vec` and initialize it with some values. We then use the `data()` function to get a pointer to the underlying array of `vec` and store it in a pointer variable named `arr`.

Finally, we pass `arr` and the size of the vector to a function named `printArray()` that accepts a pointer to an integer array and prints its contents. The `data()` function allows us to use the vector as if it were an array and pass its contents to the function.

### Capacity

```c++
// Returns the number of elements in the vector
size_t size() const noexcept;
// Returns the maximum number of elements that can be stored in the vector without reallocation
size_t capacity() const noexcept;
// Returns whether the vector is empty
bool empty() const noexcept;
// Reserves space for at least n elements
void reserve(size_t n);
// Reduces the capacity to fit the size
void shrink_to_fit();
```

#### `shrink_to_fit()`

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v {1, 2, 3, 4, 5};

    std::cout << "Before shrink_to_fit():\n";
    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Capacity: " << v.capacity() << "\n";

    v.pop_back(); // Removing an element from the vector

    std::cout << "\nAfter pop_back():\n";
    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Capacity: " << v.capacity() << "\n";

    v.shrink_to_fit(); // Shrinking the capacity to fit the size

    std::cout << "\nAfter shrink_to_fit():\n";
    std::cout << "Size: " << v.size() << "\n";
    std::cout << "Capacity: " << v.capacity() << "\n";

    return 0;
}
```

```yaml
Before shrink_to_fit():
Size: 5
Capacity: 5

After pop_back():
Size: 4
Capacity: 5

After shrink_to_fit():
Size: 4
Capacity: 4
```

#### `reserve()`

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v;

    std::cout << "Initial capacity: " << v.capacity() << std::endl;

    // Reserve space for at least 10 elements
    v.reserve(10);

    std::cout << "Capacity after reserve: " << v.capacity() << std::endl;

    // Add 5 elements to the vector
    for (int i = 1; i <= 5; ++i) {
        v.push_back(i);
    }

    std::cout << "Size after adding 5 elements: " << v.size() << std::endl;

    // Add 5 more elements to the vector
    for (int i = 6; i <= 10; ++i) {
        v.push_back(i);
    }

    std::cout << "Size after adding 5 more elements: " << v.size() << std::endl;

    // Add 1 more element to the vector
    v.push_back(11);

    std::cout << "Size after adding 1 more element: " << v.size() << std::endl;

    return 0;
}

```

```yaml
Initial capacity: 0
Capacity after reserve: 10
Size after adding 5 elements: 5
Size after adding 5 more elements: 10
Size after adding 1 more element: 11
```



### Modifiers

```c++
// Adds an element to the end of the vector
void push_back(const T& value);
void push_back(T&& value);
// Removes the last element from the vector
void pop_back();
// Inserts an element at position pos
iterator insert(const_iterator pos, const T& value);
iterator insert(const_iterator pos, T&& value);
iterator insert(const_iterator pos, size_t n, const T& value);
iterator insert(const_iterator pos, InputIterator first, InputIterator last);
// Removes an element at position pos
iterator erase(const_iterator pos);
iterator erase(const_iterator first, const_iterator last);
// Swaps the contents of this vector with other
void swap(vector& other) noexcept;
// Removes all elements from the vector
void clear() noexcept;
```

#### `push_back(T&& value)` 

```c++
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> words;
    std::string my_word = "hello";

    words.push_back(std::move(my_word));

    std::cout << "my_word: " << my_word << std::endl;
    std::cout << "words[0]: " << words[0] << std::endl;

    return 0;
}
```

```yaml
my_word:
words[0]: hello
```

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    std::vector<int> w = { 6, 7, 8 };

    //v.assign(w.begin(), w.end()); // v now contains {6, 7, 8}
    v.assign(1, 3);
    v.push_back(8);
    v.erase(v.begin());
    /*In the case of push_back(8), 8 is a literal constant which is not stored in a memory location that can be referred to by a lvalue. It is a rvalue, which means that it is a temporary value that does not have a memory address that can be accessed by a lvalue reference. Therefore, it can only be moved, not copied, by the move constructor or moved by the move assignment operator.*/

    for (auto x : v) {
        std::cout << x << " ";
    }

    return 0;
}

```



#### `insert(const_iterator pos, InputIterator first, InputIterator last)`

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {1, 2, 3};

    // Insert 4 and 5 at the end
    v.insert(v.end(), {4, 5});

    for (auto x : v) {
        std::cout << x << " ";
    }

    return 0;
}

```



## Advanced Operations

### Modifying Sequence Operations

```c++
// Assigns the elements of the range [first, last) to the vector
template<class InputIterator>
void assign(InputIterator first, InputIterator last);
// Assigns n copies of value to the vector
void assign(size_t n, const T& value);
// Removes all elements with the given value
void erase(const T& value);
// Removes consecutive duplicate elements
void unique();
```

### `assign()`

```c++
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = { 1, 2, 3, 4, 5 };
    std::vector<int> w = { 6, 7, 8 };

    v.assign(w.begin(), w.end()); // v now contains {6, 7, 8}


    for (auto x : v) {
        std::cout << x << " ";
    }

    return 0;
}
```

```yaml
6 7 8
```

#### `erase()`

```c++
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = { 1, 2, 2, 3, 3, 3, 4, 4, 4, 4 };

    // Print the original vector
    std::cout << "Original vector: ";
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    // Remove consecutive duplicates
    std::vector<int>::iterator it = std::unique(v.begin(), v.end());
    v.erase(it, v.end());

    // Print the modified vector
    std::cout << "Modified vector: ";
    for (int i : v) {
        std::cout << i << " ";
    }
    std::cout << "\n";

    return 0;
}
```

```yaml
Original vector: 1 2 2 3 3 3 4 4 4 4
Modified vector: 1 2 3 4
```



### Non-modifying Sequence Operations

```c++
// Returns an iterator to the first element equal to value, or end() if not found
iterator find(const T& value);
const_iterator find(const T& value) const;
// Returns whether all elements satisfy the given predicate
template<class UnaryPredicate>
bool all_of(UnaryPredicate p) const;
// Returns whether any element satisfies the given predicate
template<class UnaryPredicate>
bool any_of(UnaryPredicate p) const;
// Returns whether no elements satisfy the given predicate
template<class UnaryPredicate>
bool none_of(UnaryPredicate
```

# Lambda

```c++
[capture list] (parameter list) -> return type { function body }
```

Now, let's work on some practice problems to help solidify your understanding of lambda functions.

1. Write a lambda function that takes a string as input and returns the number of vowels in the string.

   ```c++
   void ex1(void)
   {
   	string str("AeiOu");
   	int vowels_count = 0;
   
   	auto count_vowels = [&vowels_count](string str) {
   		// count_vowels is a funtion object that stores the lambda function
   		for (auto ch : str)
   			// each element in a string is a c char
   		{
   			ch = tolower(ch);
   			if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
   				vowels_count++;
   			//cout << "str: " << str << endl;
   		}
   		return vowels_count;
   	};
   
   	cout << "Number of vowels in \"" << str << "\" is: " << count_vowels(str) << endl;
   }
   ```

   

2. Given a vector of integers, write a lambda function that returns the sum of all even integers in the vector.

   ```c++
   void ex2(void)
   {
   	/*Given a vector of integers, write a lambda function that returns the sum of all even integers in the vector.*/
   	vector<int> ivec{ 1,2,3,4,5,6,7,8,9 };
   	int sum_of_even = 0;
   
   	auto calculate_sum_of_even = [](vector<int> vec) {
   		int sum_of_even = 0;
   		for (auto i : vec)
   		{
   			if (i % 2 == 0)
   				sum_of_even += i;
   		}
   		return sum_of_even;
   	};
   
   	cout << "sum of even integers: " << calculate_sum_of_even(ivec) << endl;
   	
   }
   ```

   

3. Write a lambda function that takes two vectors of integers and returns a new vector containing the intersection of the two input vectors (i.e., the elements that are common to both vectors).

   ```c++
   void ex3(void)
   {
   	/*Write a lambda function that takes two vectors of integers and returns a new vector containing the intersection of the two input vectors (i.e., the elements that are common to both vectors).*/
   
   	vector<int> v1{ 1,2,3,4,5,6,7 }, v2{ 2,5,6,9,7,3 };
   	auto intersect_vectors = [](vector<int> v1, vector<int> v2) {
   
   		vector<int> new_vec;
   
   		sort(v1.begin(), v1.end());
   		sort(v2.begin(), v2.end());
   
   		set_intersection(v1.begin(), v1.end(), v2.begin(), v2.end(), back_inserter(new_vec));
   
   		return new_vec;
   	};
   
   	vector<int> new_vec = intersect_vectors(v1, v2);
   
   	cout << "v1: ";
   	for (auto u : v1)
   		cout << u << " ";
   	cout << endl;
   	cout << "v2: ";
   	for (auto u : v2)
   		cout << u << " ";
   	cout << endl;
   	cout << "new_vec: ";
   	for (auto u : new_vec)
   		cout << u << " ";
   	cout << endl;
   }
   
   ```
   
   
   

# List

Sure, here are more member functions and their overloads of `std::list`:

## Constructors

- `list()` : creates an empty list
- `list(size_type count, const T& value)` : creates a list with `count` elements, each initialized to `value`
- `explicit list(size_type count)` : creates a list with `count` value-initialized elements
- `list(const list& other)` : copy constructor
- `list(list&& other)` : move constructor
- `list(initializer_list<T> init)` : creates a list from an initializer list
- `template< class InputIt > list(InputIt first, InputIt last)` : creates a list from the elements in the range `[first, last)`

```c++
#include <iostream>
#include <list>

int main() {
    // Default constructor
    std::list<int> l1; // Creates an empty list
    std::cout << "l1: ";
    for (const auto& elem : l1) {
        std::cout << elem << " "; // Nothing is printed
    }
    std::cout << std::endl;

    // Constructor with count and value
    std::list<int> l2(3, 42); // Creates a list with three elements, all with value 42
    std::cout << "l2: ";
    for (const auto& elem : l2) {
        std::cout << elem << " "; // Prints "42 42 42"
    }
    std::cout << std::endl;

    // Explicit constructor with count
    std::list<int> l3(4); // Creates a list with four value-initialized (i.e. zero-initialized) elements
    std::cout << "l3: ";
    for (const auto& elem : l3) {
        std::cout << elem << " "; // Prints "0 0 0 0"
    }
    std::cout << std::endl;

    // Copy constructor
    std::list<int> l4(l2); // Creates a copy of l2
    std::cout << "l4: ";
    for (const auto& elem : l4) {
        std::cout << elem << " "; // Prints "42 42 42"
    }
    std::cout << std::endl;

    // Move constructor
    std::list<int> l5(std::move(l2)); // Moves the contents of l2 to l5
    std::cout << "l2: ";
    for (const auto& elem : l2) {
        std::cout << elem << " "; // Nothing is printed, since l2 is now empty
    }
    std::cout << std::endl;
    std::cout << "l5: ";
    for (const auto& elem : l5) {
        std::cout << elem << " "; // Prints "42 42 42"
    }
    std::cout << std::endl;

    // Constructor with initializer list
    std::list<int> l6{ 1, 2, 3 }; // Creates a list with three elements, with values 1, 2, and 3
    std::cout << "l6: ";
    for (const auto& elem : l6) {
        std::cout << elem << " "; // Prints "1 2 3"
    }
    std::cout << std::endl;

    // Constructor with iterators
    std::list<int> l7(std::next(l6.begin(), 1), l6.end()); // Creates a copy of l6 from the second element
    // use std::next(iter, offset) can not write l6.begin() + 1
    std::cout << "l7: ";
    for (const auto& elem : l7) {
        std::cout << elem << " "; // Prints "1 2 3"
    }
    std::cout << std::endl;

    return 0;
}
```



## Assignment Operators

- `list& operator=(const list& other)` : copy assignment
- `list& operator=(list&& other)` : move assignment
- `list& operator=(initializer_list<T> ilist)` : assigns the elements of the initializer list to the list

```c++
#include <iostream>
#include <list>

int main() {
    std::list<int> l1{ 1, 2, 3 }; // Creates a list with elements 1, 2, and 3
    std::list<int> l2{ 4, 5, 6 }; // Creates a list with elements 4, 5, and 6

    l1 = l2; // Copies the elements of l2 into l1
    std::cout << "l1: ";
    for (const auto& elem : l1) {
        std::cout << elem << " "; // Prints "4 5 6"
    }
    std::cout << std::endl;

    l1 = { 7, 8, 9 }; // Assigns the elements {7, 8, 9} to l1
    std::cout << "l1: ";
    for (const auto& elem : l1) {
        std::cout << elem << " "; // Prints "7 8 9"
    }
    std::cout << std::endl;

    l2 = std::move(l1); // Move assigns the elements of l1 into l2
    std::cout << "l2: ";
    for (const auto& elem : l2) {
        std::cout << elem << " "; // Prints "7 8 9"
    }
    std::cout << std::endl;

    std::cout << "l1: ";
    for (const auto& elem : l1) {
        std::cout << elem << " "; // Prints "7 8 9"
    }
    std::cout << std::endl;

    return 0;
}
```



## Iterators

- `iterator begin() noexcept` : returns an iterator to the beginning of the list
- `const_iterator begin() const noexcept` : returns a const iterator to the beginning of the list
- `iterator end() noexcept` : returns an iterator to the end of the list
- `const_iterator end() const noexcept` : returns a const iterator to the end of the list
- `reverse_iterator rbegin() noexcept` : returns a reverse iterator to the beginning of the list
- `const_reverse_iterator rbegin() const noexcept` : returns a const reverse iterator to the beginning of the list
- `reverse_iterator rend() noexcept` : returns a reverse iterator to the end of the list
- `const_reverse_iterator rend() const noexcept` : returns a const reverse iterator to the end of the list
- `const_iterator cbegin() const noexcept` : returns a const iterator to the beginning of the list
- `const_iterator cend() const noexcept` : returns a const iterator to the end of the list
- `const_reverse_iterator crbegin() const noexcept` : returns a const reverse iterator to the beginning of the list
- `const_reverse_iterator crend() const noexcept` : returns a const reverse iterator to the end of the list

```c++
#include <iostream>
#include <list>

int main() {
    // Create a list
    std::list<int> l = { 1, 2, 3, 4, 5 };

    // Use iterators to print the list forwards
    std::cout << "Printing list forwards:" << std::endl;
    for (std::list<int>::iterator it = l.begin(); it != l.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use const iterators to print the list forwards
    std::cout << "Printing list forwards with const iterator:" << std::endl;
    for (std::list<int>::const_iterator it = l.cbegin(); it != l.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use reverse iterators to print the list backwards
    std::cout << "Printing list backwards:" << std::endl;
    for (auto it = l.rbegin(); it != l.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Use const reverse iterators to print the list backwards
    std::cout << "Printing list backwards with const reverse iterator:" << std::endl;
    for (std::list<int>::const_reverse_iterator it = l.crbegin(); it != l.crend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    return 0;
}
```



## Capacity

- `bool empty() const noexcept` : returns true if the list is empty, false otherwise
- `size_type size() const noexcept` : returns the number of elements in the list
- `size_type max_size() const noexcept` : returns the maximum possible number of elements in the list
- `void resize(size_type count)` : changes the size of the list to `count`
- `void resize(size_type count, const value_type& value)` : changes the size of the list to `count` and initializes any new elements with `value`
- `void shrink_to_fit()` : reduces the capacity of the list to fit its size

```c++
#include <iostream>
#include <list>

int main() {
    std::list<int> l = { 1, 2, 3 };

    // empty
    if (l.empty()) {
        std::cout << "The list is empty" << std::endl;
    }
    else {
        std::cout << "The list is not empty" << std::endl;
    }

    // size
    std::cout << "The size of the list is: " << l.size() << std::endl;

    // max_size
    std::cout << "The maximum possible size of the list is: " << l.max_size() << std::endl;

    // resize
    l.resize(5);
    std::cout << "The size of the list after resizing to 5: " << l.size() << std::endl;
    for (const auto& elem : l) {
        std::cout << elem << " "; // prints "1 2 3 0 0"
    }
    std::cout << std::endl;

    l.resize(7, 4);
    std::cout << "The size of the list after resizing to 7 with value 4: " << l.size() << std::endl;
    for (const auto& elem : l) {
        std::cout << elem << " "; // prints "1 2 3 0 0 4 4"
    }
    std::cout << std::endl;


    return 0;
}
```

```yaml
The list is not empty
The size of the list is: 3
The maximum possible size of the list is: 768614336404564650
The size of the list after resizing to 5: 5
1 2 3 0 0
The size of the list after resizing to 7 with value 4: 7
1 2 3 0 0 4 4
```





## Element Access

- `reference front()` : returns a reference to the first element in the list
- `const_reference front() const` : returns a const reference to the first element in the list
- `reference back()` : returns a reference to the last element in the list
- `const_reference back() const` : returns a const reference to the last element in the list

```c++
#include <iostream>
#include <list>

int main() {
    std::list<int> mylist = {1, 2, 3, 4, 5};

    std::cout << "The first element is: " << mylist.front() << '\n';
    std::cout << "The last element is: " << mylist.back() << '\n';

    // modifying the first and last element
    mylist.front() = 6;
    mylist.back() = 7;

    std::cout << "The first element is: " << mylist.front() << '\n';
    std::cout << "The last element is: " << mylist.back() << '\n';

    return 0;
}
```



## Modifiers

- `template< class... Args > void emplace_front( Args&&... args )` : constructs a new element at the beginning of the list with `args`
- `template< class... Args > void emplace_back( Args&&... args )` : constructs a new element at the end of the list with `args`

- `void assign(size_type count, const T& value);`
- `template<class InputIt> void assign(InputIt first, InputIt last);`
- `void assign(std::initializer_list<T> ilist);`
- `void push_back(const T& value);`
- `void push_back(T&& value);`
- `void pop_back();`
- `void push_front(const T& value);`
- `void push_front(T&& value);`
- `void pop_front();`
- `iterator insert(const_iterator pos, const T& value);`
- `iterator insert(const_iterator pos, T&& value);`
- `iterator insert(const_iterator pos, size_type count, const T& value);`
- `template<class InputIt> iterator insert(const_iterator pos, InputIt first, InputIt last);`
- `iterator insert(const_iterator pos, std::initializer_list<T> ilist);`
- `iterator erase(const_iterator pos);`
- `iterator erase(const_iterator first, const_iterator last);`
- `void swap(list& other) noexcept(std::allocator_traits<Allocator>::is_always_equal_v<allocator_type>);`
- `void resize(size_type count);`
- `void resize(size_type count, const value_type& value);`
- `void clear() noexcept;`
- `void splice(const_iterator pos, list& other);`
- `void splice(const_iterator pos, list&& other);`
- `void splice(const_iterator pos, list& other, const_iterator it);`
- `void splice(const_iterator pos, list&& other, const_iterator it);`
- `void splice(const_iterator pos, list& other, const_iterator first, const_iterator last);`
- `void splice(const_iterator pos, list&& other, const_iterator first, const_iterator last);`
- `void remove(const T& value);`
- `template<class UnaryPredicate> void remove_if(UnaryPredicate p);`
- `void reverse() noexcept;`
- `void unique();`
- `template<class BinaryPredicate> void unique(BinaryPredicate binary_pred);`
- `void merge(list& other);`
- `void merge(list&& other);`
- `template<class Compare> void merge(list& other, Compare comp);`
- `template<class Compare> void merge(list&& other, Compare comp);`
- `void sort();`
- `template<class Compare> void sort(Compare comp);`
- `void splice_after(const_iterator pos, forward_list& other);`
- `void splice_after(const_iterator pos, forward_list&& other);`
- `void splice_after(const_iterator pos, forward_list& other, const_iterator it);`
- `void splice_after(const_iterator pos, forward_list&& other, const_iterator it);`
- `void splice_after(const_iterator pos, forward_list& other, const_iterator first, const_iterator last);`
- `void splice_after(const_iterator pos, forward_list&& other, const_iterator first, const_iterator last);`
- `void remove(const T& value);`
- `template<class UnaryPredicate> void remove_if(UnaryPredicate p);`
- `void unique();`
- `template<class BinaryPredicate> void unique(BinaryPredicate binary_pred);`
- `void sort();`
- `template<class Compare> void sort(Compare comp);`

```c++
#include <iostream>
#include <list>

int main() {
    // emplace_front and emplace_back
    std::list<int> my_list = {1, 2, 3};
    my_list.emplace_front(0);
    my_list.emplace_back(4);
    std::cout << "List after emplace_front and emplace_back: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // assign
    std::list<int> my_other_list;
    my_other_list.assign(3, 7);
    std::cout << "my_other_list after assign(count, value): ";
    for (const auto& elem : my_other_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    std::list<int> my_third_list = {1, 2, 3};
    my_third_list.assign(my_list.begin(), my_list.end());
    std::cout << "my_third_list after assign(first, last): ";
    for (const auto& elem : my_third_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    my_third_list.assign({4, 5, 6});
    std::cout << "my_third_list after assign(initializer_list): ";
    for (const auto& elem : my_third_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    // push_back, push_front, pop_back, pop_front
    my_list.push_back(5);
    my_list.push_front(-1);
    std::cout << "List after push_back and push_front: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
    
    my_list.pop_back();
    my_list.pop_front();
    std::cout << "List after pop_back and pop_front: ";
    for (const auto& elem : my_list) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}
```

```c++
#include <iostream>
#include <list>

int main()
{
    // create a list of integers
    std::list<int> mylist = { 1, 2, 3, 4, 5 };

    // insert an element at the beginning
    mylist.insert(mylist.begin(), 0);

    // insert an element at position 3
    mylist.insert(std::next(mylist.begin(), 3), 10);

    // insert three elements with the value 7 at the beginning
    mylist.insert(mylist.begin(), 3, 7);

    // insert elements from another list
    std::list<int> otherlist = { 6, 7, 8 };
    mylist.insert(std::next(mylist.begin(), 2), otherlist.begin(), otherlist.end());

    // erase an element at position 2
    mylist.erase(std::next(mylist.begin(), 2));

    // erase elements in the range [3,5)
    mylist.erase(std::next(mylist.begin(), 3), std::next(mylist.begin(), 5));

    // swap the contents of two lists
    std::list<int> anotherlist = { 9, 10, 11 };
    mylist.swap(anotherlist);

    // resize the list to contain 10 elements
    mylist.resize(10);

    // resize the list and set the new elements to 20
    mylist.resize(12, 20);

    // clear the contents of the list
    mylist.clear();

    // splice the contents of another list into the current list
    std::list<int> splicelist = { 1, 2, 3, 4, 5 };
    mylist.splice(mylist.begin(), splicelist);

    // remove all elements with the value 3
    mylist.remove(3);

    // remove all even elements
    mylist.remove_if([](int i) { return i % 2 == 0; });

    // reverse the order of the elements
    mylist.reverse();

    // remove all consecutive duplicate elements
    mylist.unique();

    // sort the elements in ascending order
    mylist.sort();

    // sort the elements in descending order
    mylist.sort([](int a, int b) { return a > b; });

    // create a forward list of integers
    std::forward_list<int> forwardlist = { 1, 2, 3, 4, 5 };

    // splice the contents of the forward list into the current list
    mylist.splice_after(mylist.before_begin(), forwardlist);

    return 0;
}

```



## Operations

- `void merge(list& other);`
- `void merge(list&& other);`
- `template<class Compare> void merge(list& other, Compare comp);`
- `template<class Compare> void merge(list&& other, Compare comp);`
- `void remove(const T& value);`
- `template<class UnaryPredicate> void
