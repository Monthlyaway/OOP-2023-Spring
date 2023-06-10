#pragma once
#include <stdexcept>
using namespace std;

template<typename T> class Handle {
public:
	Handle() : _ptr(0) {}
	Handle(const Handle& rhs) : _ptr(0) {
		if (rhs._ptr)
			_ptr = rhs._ptr->clone();
	}
	Handle& operator=(const Handle& rhs) {
		if (&rhs != this) {  // if rhs and this are not the same object
			// check for self assignment
			delete _ptr;  // delete the old ptr and its associated memeory
			if (rhs._ptr)
				_ptr = rhs._ptr->clone();
			else
				_ptr = 0;  
			// new ptr is either a pointer to a
			// copy of the object rhs._ptr points to or NULL
		}
		return *this;
	}
	~Handle() {
		delete _ptr;
	}

	Handle(T* nptr) : _ptr(nptr) {}
	explicit operator bool() const {
		return _ptr;
	}
	/*T* pointer() const {
		return _ptr;
	}*/
	T& operator*() const {
		if (_ptr)
			return *_ptr;  // return a reference to T
		throw runtime_error("Unbound Handle");
	}
	T* operator->() const {
		// (x.operator->())->y
		// x._ptr->y
		if (_ptr)
			return _ptr;
		throw runtime_error("Unbound Handle");

	}
private:
	T* _ptr;
};

