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
int splitArray(int array[], int left, int right) 
{
    int mid = left + (right - left) / 2;
    int pivot = array[mid];
    // move the mid point value to the front.
    std::swap(array[mid], array[left]);
    int i = left + 1;
    int j = right;
    while (i <= j) {
        while(i <= j && array[i] <= pivot) 
            i++;
            
        while(i <= j && array[j] > pivot) 
            j--;
            
        if (i < j) 
            std::swap(array[i], array[j]);
    }
    int pivotIndex = i - 1;
    std::swap(array[pivotIndex], array[left]);
    return pivotIndex;
}

void Quicksort(int array[], int left, int right){

    int part = splitArray(array, left, right);
    //std::cout << "QSC:" << left << "," << right << " part=" << part << "\n";

    if (left < part - 1) 
        Quicksort(array, left, part - 1);
   
    if (part + 1 < right) 
        Quicksort(array, part + 1, right);
}

int main()
{
	int array1[] = {4,5,2,7,1,10,12,22,0,1,4,6};

	printArray(array1, 12);
	Quicksort(array1, 0, 11);
	printArray(array1, 12);

	return 0;
	printf("pivot around value 5\n");
	int pivot = splitArray(array1, 0, 11);
	printf("pivot is at index %i\n", pivot);
	printArray(array1, 12);



	return 0;
}
