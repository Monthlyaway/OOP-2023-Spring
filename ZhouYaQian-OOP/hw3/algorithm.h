#ifndef GUARD_median_h
#define GUARD_median_h
#define DEBUG
#include "debug.h"
#include <vector>
#include <stdexcept>

//�����Ƕ���Զ���ķ��ͺ�����
//�����Զ���������ռ�MySpace�С�
//��Ҫʹ�õ���Щ������ʱ��
//�������ļ���ʼʹ�á�using MySpace::find;�������
//����ֱ���ں�����ǰ�ӡ�MySpace::����

namespace MySpace {

	//����ʵ�ַ��ͺ���swap����������������ֵ 
	template <typename X>
	void swap(X& x, X& y) {
		X tmp = x;
		x = y;
		y = tmp;
	}

	//����ʵ�ַ��ͺ���sort����ð�ݷ����� 
	template<typename Ran>
	void sort(Ran begin, Ran end)
	{
		//	std::cout << "sort...\n";
		for (Ran i = begin; i != end; i++)
			for (Ran j = begin; j + 1 + (i - begin) != end; j++)
				if (*j > *(j + 1))
					swap(*j, *(j + 1));
	}

	//����ʵ�ַ��ͺ���median������ֵ 
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

	//����ʵ�ַ��ͺ���average�����ֵ
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

	//����ʵ�ַ��ͺ���find��ʵ�ֲ��ҹ��� 
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

	//����ʵ�ַ��ͺ���remove_copy��
	//��������x��ƥ���Ԫ�ظ��Ƶ����������dest��ʾ��Ŀ���ַ�С� 
	template <typename In, typename Out, typename X>
	Out remove_copy(In begin, In end, Out dest, const X& x) {
		for (In iter = begin; iter != end; iter++) {
			if (*iter == x) {
				*(dest++) = x;
			}
		}
		return dest;
	}

	//����ʵ�ַ��ͺ���transform��
	//�����������begin��end��ʾ�����е�Ԫ���ϵ��ú���f��
	//������浽���������d��ʾ��Ŀ���ַ�С� 
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
