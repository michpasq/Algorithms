#include <iostream>

bool binarySearch(int array[], int size, int val) {
 	int left = 0;
    int right = size - 1;
    int mid = left + ((left + right) / 2);
    
    while (left < right) {
        if (val == array[mid]) {
            return true;
        }
        else if (val < array[mid]) {
        	right = mid - 1;
        }
        else {
         	left = mid + 1;   
        }
        mid = left + ((left + right) / 2);
    }
    return val == array[mid];
}

int main() {

	int sample[] = {1,2,3,4,4,6,7,8};
	int size = sizeof(sample)/sizeof(int);
	std::cout << "sample:\n";
	for (int i = 0; i < size; i++) {
		std::cout << sample[i] << ' ';
	}
	std::cout << '\n';

	int vals[] = {-1,0,2,5,8,9};
	int valsSize = sizeof(vals)/sizeof(int);
	bool isInSample;
	for (int i = 0; i < valsSize; i++) {
		isInSample = binarySearch(sample, size, vals[i]);
		std::cout << vals[i] << (isInSample ? " is in sample" : " is not in sample") << ".\n";
	}
	
	return 0;
}