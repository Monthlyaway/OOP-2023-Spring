#ifndef GUARD_median_h
#define GUARD_median_h
#define DEBUG
#include "debug.h"
#include <vector>
#include <stdexcept>

//以下是多个自定义的泛型函数，
//放在自定义的命名空间MySpace中。
//需要使用的这些函数的时候，
//可以在文件开始使用“using MySpace::find;”等语句
//或者直接在函数名前加“MySpace::”。

namespace MySpace {

	//以下实现泛型函数swap，交换两个变量的值 
	template <typename X>
	void swap(X& x, X& y) {
		X tmp = x;
		x = y;
		y = tmp;
	}

	//以下实现泛型函数sort，用冒泡法排序 
	template<typename Ran>
	void sort(Ran begin, Ran end)
	{
		//	std::cout << "sort...\n";
		for (Ran i = begin; i != end; i++)
			for (Ran j = begin; j + 1 + (i - begin) != end; j++)
				if (*j > *(j + 1))
					swap(*j, *(j + 1));
	}

	//以下实现泛型函数median，求中值 
	template<typename T>
	T median(std::vector<T> vec)
	{
		DEBUG_OUTPUT("median...");
		typedef typename std::vector<T>::size_type vec_sz;
		vec_sz size = vec.size();
		if (size == 0)
			throw std::domain_error("median of an empty vector");
		sort(vec.begin(), vec.end());
		vec_sz mid = size / 2;
		return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
	}

	//以下实现泛型函数average，求均值
	template<typename T>
	T average(std::vector<T> vec)
	{
		//DEBUG_OUTPUT("average...");
		//T sum = T(); // initialize sum to 0
		//typename std::vector<T>::const_iterator iter = vec.begin();
		//typename std::vector<T>::const_iterator end_it = vec.end();
		//// dependent types in templates

		//for (; iter != end_it; iter++)
		//	sum += *iter;
		//T average = sum / static_cast<T>(vec.size()); // compute the average
		///*static_cast is considered safer than C-style type casting because it performs a compile-time check to ensure that the conversion is valid. */
		//DEBUG_OUTPUT("average = " << average);
		//return average;
		T sum(0);
		for (auto u : vec)
			sum += u;
		return sum / vec.size();
	}

	//以下实现泛型函数find，实现查找功能 
	template <typename In, typename X>
	In find(In begin, In end, const X& x) {
		DEBUG_OUTPUT("find...");
		for (In iter = begin; iter != end; iter++)
		{
			if (*iter == x)
				return iter;
		}
		return end;
	}

	//以下实现泛型函数remove_copy，
	//把所有与x不匹配的元素复制到输出迭代器dest表示的目标地址中。 
	template <typename In, typename Out, typename X>
	Out remove_copy(In begin, In end, Out dest, const X& x) {
		for (In iter = begin; iter != end; iter++) {
			if (*iter == x) {
				*(dest++) = x;
			}
		}
		return dest;
	}

	//以下实现泛型函数transform，
	//在输入迭代器begin和end表示的序列的元素上调用函数f，
	//结果保存到输出迭代器d表示的目标地址中。 
	template <typename In, typename Out, typename F>
	Out transform(In begin, In end, Out dest, F func) {
		DEBUG_OUTPUT("transform...");
		for (In iter = begin; iter != end; iter++)
		{
			*dest++ = func(*iter);
		}
		return dest;
	}
	
}
#endif
