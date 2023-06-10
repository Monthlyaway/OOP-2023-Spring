// C++ program for Merge Sort
// https://www.geeksforgeeks.org/merge-sort/
#include <iostream>
#include <algorithm>
using namespace std;

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
	int const right)
{
	int const subArrayOne = mid - left + 1;  // count of the array
	int const subArrayTwo = right - mid;

	// Create temp arrays
	auto* leftArray = new int[subArrayOne],
		* rightArray = new int[subArrayTwo];

	// The second parameter: one past final
	copy(array + left, array + mid + 1, leftArray);
	copy(array + mid + 1, array + right + 1, rightArray);

	auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
	int indexOfMergedArray = left;

	// Merge the temp arrays back into array[left..right]
	while (indexOfSubArrayOne < subArrayOne
		&& indexOfSubArrayTwo < subArrayTwo) {
		if (leftArray[indexOfSubArrayOne]
			<= rightArray[indexOfSubArrayTwo]) {
			array[indexOfMergedArray]
				= leftArray[indexOfSubArrayOne];
			indexOfSubArrayOne++;
		}
		else {
			array[indexOfMergedArray]
				= rightArray[indexOfSubArrayTwo];
			indexOfSubArrayTwo++;
		}
		indexOfMergedArray++;
	}

	if (indexOfSubArrayOne < subArrayOne)
		copy(leftArray + indexOfSubArrayOne, leftArray + subArrayOne, array + indexOfMergedArray);
	else
		copy(rightArray + indexOfSubArrayTwo, rightArray + subArrayTwo, array + indexOfMergedArray);

	delete[] leftArray;
	delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
	if (begin >= end)
		return;

	int mid = begin + (end - begin) / 2;
	mergeSort(array, begin, mid);
	merge(array, begin, mid, end);
	mergeSort(array, mid + 1, end);
}



// UTILITY FUNCTIONS
// Function to print an array
template<typename elemType>
void printArray(elemType* array, int size) {
	for (int ix = 0; ix < size; ix++)
		cout << *(array + ix) << " ";
	cout << endl;
}

// Driver code
int main()
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	int arr_size = sizeof(arr) / sizeof(arr[0]);

	cout << "Given array is \n";
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	cout << "\nSorted array is \n";
	printArray(arr, arr_size);
	return 0;
}

// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes
