#include <stdio.h>
#include <algorithm>

void printArray(int array[], int size)
{
	for (int i = 0; i < size; i++) {
		printf("%i, ", array[i]);
	}
	printf("\n");
}

// "Splits" the array in range [l,r] around "pivot".
// All elements between "l" and "r" less than "pivot"
// end to left of pivot,  likewise elements greater to the right.
int splitArray(int array[], int pivot, int l, int r)
{

	int startIter = l;
	int endIter = r;

	while (startIter < endIter) {

		// Find element starting from left side greater than pivot
		int i;
		for (i = startIter; array[i] < pivot; i++);
		startIter = i;

		// Fine element starting from right side less than pivot
		int j;
		for (j = endIter; array[j] > pivot; j--);
		endIter = j;

		// Found elements to swap
		std::swap(array[i], array[j]);
	}

	return startIter;
}

int main()
{
	int array1[] = {4,5,2,7,1,10,12,22,0,1,4,6};

	printArray(array1, 12);
	printf("pivot around value 5\n");
	int pivot = splitArray(array1, 5, 0, 11);
	printf("pivot is at index %i\n", pivot);
	printArray(array1, 12);

	return 0;
}