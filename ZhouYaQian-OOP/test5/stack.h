#ifndef __STACK_H
#define __STACK_H
#include <memory> // for std::allocator
#include <iostream>

using namespace std;
template <typename T>
class myStack {
public:
	myStack() : _data(nullptr), _size(0), _capacity(0) {}
	~myStack() {
		clear();
	}
	void push(const T& item) {
		if (_size == _capacity) {
			reserve(2 * (_capacity + 1));
		}
		alloc.construct(&_data[_size], item);
		++_size;
	}
	void push(const T&& item) {
		if (_size == _capacity) {
			reserve(_capacity + 1);
		}
		alloc.construct(&_data[_size], item);
		++_size;
	}
	void pop() {
		if (_size > 0) {
			--_size;
			alloc.destroy(&_data[_size]);
			//delete &_data[_size];
		}
	}
	T& top() {
		return _data[_size - 1];
	}
	const T& top() const {
		return _data[_size - 1];
	}
	size_t size() const {
		return _size;
	}
	bool empty() const {
		return _size == 0;
	}

	// random access
	T& operator[](size_t i)
	{
		if (i >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _data[i];
	}
	const T& operator[](size_t i) const {
		if (i >= _size) {
			throw std::out_of_range("Index out of range");
		}
		return _data[i];
	}
	void clear() {
		for (size_t i = 0; i < _size; ++i) {
			alloc.destroy(&_data[i]);
		}
		alloc.deallocate(_data, _capacity);
		_data = nullptr;
		_size = _capacity = 0;
	}

private:
	std::allocator<T> alloc;
	T* _data;
	size_t _size;  // number of elements
	size_t _capacity;  // number of allocated memories

	void reserve(size_t new_capacity) {
		if (new_capacity <= _capacity) {
			return;
		}
		T* new_data = alloc.allocate(new_capacity);
		for (size_t i = 0; i < _size; ++i) {
			alloc.construct(&new_data[i], _data[i]);
			//new (&new_data[i]) T(_data[i]);
			alloc.destroy(&_data[i]);
		}
		alloc.deallocate(_data, _capacity);
		_data = new_data;
		_capacity = new_capacity;
	}

};


#endif