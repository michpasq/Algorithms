#include <iostream>

// Notes about algorithm:
// merge() works "bottom-up" (I think). It assumes array[left,mid]
// and array[mid+1,right] are both sorted, which is guaranteed when you 
// begin merging at the "bottom" of recursion starting with the base case,
// i.e. arrays of size one.

// Just be careful with indices for left and right temp arrays
void merge(int array[], int left, int mid, int right) 
{
	// Copy elements [left, right] into temporary arrays

	int leftSize = mid - left + 1;
	int rightSize = right - mid;

	int tempLeft[leftSize];
	int tempRight[rightSize];

	int i, j, k;
	for (i = 0; i < leftSize; i++) {
		tempLeft[i] = array[left + i];
	}

	for (j = 0; j < rightSize; j++) {
		tempRight[j] = array[mid + j + 1];
 	}

 	// Merge temporary arrays back into "array"
 	i = 0;
 	j = 0;
 	k = left;
 	while (i < leftSize && j < rightSize) {
 		if (tempLeft[i] <= tempRight[j]) 
 			array[k] = tempLeft[i++];
 		else 
 			array[k] = tempRight[j];
 		k++;
 	}

 	// Appened remaining elements, if there are any
 	while (i < leftSize) 
 		array[k++] = tempLeft[i++];

 	while (j < rightSize) 
 		array[k++] = tempRight[j++];
}

void mergeSort(int array[], int left, int right)
{
	if (left == right) {
		return;
	}
	int mid = left + (right - left) / 2; //Same as (left + right) / 2, but avoids overflow for large l and r
	mergeSort(array, left, mid);
	mergeSort(array, mid + 1, right);
	merge(array, left, mid, right);
}

int main()
{
	int sample[] = {5,6,4,2,8,9,1,10};
	mergeSort(sample, 0, 7);

	for (int i = 0; i < 8; i++) {
		std::cout << sample[i] << ' ';
	}
	std::cout << '\n';

	return 0;
}