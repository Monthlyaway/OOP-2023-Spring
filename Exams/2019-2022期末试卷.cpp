#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

template <typename iterator>
void selectSort(iterator begin, iterator end)
{
	iterator min = begin;
	auto tmp = *begin;
	for (iterator curr = begin; curr != end; curr++)
	{
		for (iterator iter = curr; iter != end; iter++)
		{
			if (*iter < *min)
				min = iter;
		}
		tmp = *curr;
		*curr = *min;
		*min = tmp;
	}

}

//template <typename container>
//void selectSort(typename container::iterator begin, 
//	typename container::iterator end)
//{
//	typename container::iterator min = begin;
//	auto tmp = *begin;
//	for (typename container::iterator curr = begin; curr != end; curr++)
//	{
//		for (typename container::iterator iter = curr; iter != end; iter++)
//		{
//			if (*iter < *min)
//				min = iter;
//		}
//		tmp = *curr;
//		*curr = *min;
//		*min = tmp;
//	}
//
//}

void ex1_8()
{
	static string const TIOBE[] = {
		"java", "C", "python", "c++",
		"c#", "Visual Basic", "javascript", "PHP", "SQL", "R"
	};
	string Lan[10];
	copy(TIOBE, TIOBE + 10, Lan);
	for (int ix = 0; ix < 10; ix++) {
		cout << Lan[ix] << " ";
	}
	cout << endl;

}

void ex4_1()
{
	vector<int> ivec{ 4,5,6,8,9,2,1,2,3,6,6,5,4 };
	selectSort(ivec.begin(), ivec.end());
	for (auto u : ivec)
		cout << u << " ";
	cout << endl;
}

int main(void)
{
	//ex1_8();
	ex4_1();
	return 0;
}