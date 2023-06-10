#include <vector>
#include <iterator>
#include <algorithm>
#include <utility>
#include <iostream>
#include <random>

template<typename I, typename BI>
void mergeTogether(I begin, I mid, I end, BI beginBuffer)
{
	I  low = begin;
	I  hig = mid;
	BI buf = beginBuffer;
	// --------------------------------------
	// | begin       mid-1 | mid         end|                           
	// --------------------------------------
	// | low               | high           |
	// --------------------------------------
	while (low < mid && hig < end) {
		if (*low <= *hig) {
			std::iter_swap(low, buf);
			++low;
		}
		else {
			std::iter_swap(hig, buf);
			++hig;
		}
		++buf;
	}
	buf = std::move(low, mid, buf);
	buf = std::move(hig, end, buf);

	// move back
	std::size_t size = std::distance(begin, end);
	std::move(beginBuffer, std::next(beginBuffer, size), begin);
}

template<typename I, typename BI>
void mergeSortUsingBuffer(I begin, I end, BI beginBuffer)
{
	std::size_t size = std::distance(begin, end);
	if (size < 2) {
		return;
	}
	std::size_t split = size / 2;
	I mid = std::next(begin, split);
	BI midBuffer = std::next(beginBuffer, split);

	mergeSortUsingBuffer(begin, mid, beginBuffer);
	mergeSortUsingBuffer(mid, end, midBuffer);

	mergeTogether(begin, mid, end, beginBuffer);
}

template<typename I>
void mergeSort(I begin, I end)
{
	using ValueType = typename std::iterator_traits<I>::value_type;
	std::size_t size = std::distance(begin, end);
	// do not use size = end - begin, that assume random access
	std::vector<ValueType> buffer(size);

	mergeSortUsingBuffer(begin, end, std::begin(buffer));
}

int main()
{

	std::random_device rd;                           
	// Obtain a random seed from the hardware
	std::mt19937 gen(rd());                         
	// Standard mersenne_twister_engine seeded with rd()
	std::uniform_int_distribution<int> dist(1, 10000); 
	// Define the range for random numbers

	std::vector<int> a;
	a.reserve(10000);  // Reserve space in the vector to avoid reallocation

	for (int i = 0; i < 15; ++i) {
		int num = dist(gen);  // Generate a random number using the random engine and distribution
		a.push_back(num);
	}
	//std::vector<int> a = 
	//{ 9,5,3,2,2,9,12,5,6,9,6,3,2,1,5,4,7,8,9,6,5,4,5,8,5,2,1,3 };
	mergeSort(std::begin(a), std::end(a));
	std::copy(std::begin(a), std::end(a),
		std::ostream_iterator<int>(std::cout, ", "));
	std::cout << "\n";
}