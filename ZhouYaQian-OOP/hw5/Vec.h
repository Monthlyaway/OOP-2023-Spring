#ifndef __VEC_H
#define __VEC_H
#include <memory>

using namespace std;
template<typename T>
class Vec {
public:
	// type defines
	typedef T* iterator;
	typedef const T* const_iterator;
	typedef size_t size_type;
	typedef T value_type;
	typedef ptrdiff_t difference_type;
	typedef T& reference;
	typedef const T& const_reference;

	// default constructor
	Vec() { create(); }
	// explicit constructor with default arguments
	explicit Vec(size_type n, const_reference Val = T()) { create(n, Val); }
	// copy constructor
	Vec(const Vec& v) { create(v.begin(), v.end()); }
	// destructor
	~Vec() { uncreate(); }

	// operator overloads
	Vec& operator=(const Vec& rhs);

	// getters
	size_type size(void) const;
	reference operator[](size_type ix);
	const_reference operator[](size_type ix) const;
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;

	// modifiers
	void push_back(const value_type& val);
	void clear(void) { uncreate(); }

	std::allocator<T> alloc;

private:
	iterator _data;  // pointer to the first element
	iterator _avail;  // pointer to the first uninitialized element
	iterator _limit;  // pointer to one past the last element

	void create(void) {
		_data = _limit = _avail = 0;
	}
	void create(size_type n, const T& val);
	void create(const_iterator begin, const_iterator end) {
		size_type size = end - begin;
		_data = new value_type[size];
		_limit = _data + size;
		iterator dest = _data;
		for (const_iterator src = begin; src != end; src++, dest++)
			new (dest) value_type(*src);
		/* This constructs a new object of type value_type at the memory location pointed to by dest. It uses placement new to construct the object by invoking the copy constructor and passing the value referred to by src.
		*/
		_avail = _limit;
	}
	void uncreate(void);
	void grow(void);
	void unchecked_append(const T& val);
};

// getters
template<class T>
typename Vec<T>::size_type Vec<T>::size() const {
	return (_avail - _data);
}

template<class T>
typename Vec<T>::reference Vec<T>::operator[](typename Vec<T>::size_type ix) {
	return _data[ix];
}

template<class T>
typename Vec<T>::const_reference Vec<T>::operator[](typename Vec<T>::size_type ix) const {
	return _data[ix];
}

template<class T>
typename Vec<T>::iterator Vec<T>::begin() {
	return _data;
}

template<class T>
typename Vec<T>::const_iterator Vec<T>::begin() const {
	return _data;
}

template<class T>
typename Vec<T>::iterator Vec<T>::end() {
	return _avail;
}

template<class T>
typename Vec<T>::const_iterator Vec<T>::end() const {
	return _avail;
}

template<class T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs)
{
	if (this != &rhs)
	{
		uncreate();
		create(rhs.begin(), rhs.end());
	}
	return *this;
}

template<class T>
void Vec<T>::push_back(const value_type& val)
{
	/*if (_avail == _limit)
		grow();*/
	unchecked_append(val);
}

template <class T>
void Vec<T>::grow()
{
	size_type new_size = _limit == _data ? 1 : 2 * (_limit - _data);
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = uninitialized_copy(_data, _avail, new_data);
	uncreate();
	_data = new_data;
	_avail = new_avail;
	_limit = _data + new_size;
}


template <class T>
void Vec<T>::unchecked_append(const T& val)
{
	if (_avail == _limit) {
		grow();
	}
	//allocator.construct(avail++, val);
	new (_avail++) T(val);
}

template <class T>
void Vec<T>::uncreate()
{
	if (_data) {
		//（以相反的顺序）析构构造函数生成的元素
		iterator it = _avail;
		while (it != _data)
			alloc.destroy(--it);
		//释放data所指的空间
		alloc.deallocate(_data, _limit - _data);
	}
	_data = _avail = _limit = 0;
}

template <class T>
void Vec<T>::create(size_type n, const T& val)
{
	_data = alloc.allocate(n, 0);  
	// 0 for no specific alignment requirement
	_avail = _limit = _data + n;
	std::uninitialized_fill(_data, _limit, val);
}

#endif
