#include <stdio.h>
#include <algorithm>

// Try with two queues and stack: http://stackoverflow.com/questions/6479779/generate-permutation-using-a-single-stack

void swap(char* a, char* b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

template <class T> void swap(T& a, T& b)
{
	T c = a; 
	a = b; 
	b = c;
}

void permuteString(char str[], int l, int r)
{
	if (l == r)
		printf("%s\n", str);
	else {
		for (int i = l; i <= r; i++) {
			swap(str + l, str + i);
			permuteString(str, l + 1, r);
			swap(str + l, str + i);
		}
	}
}

// Source: https://en.wikipedia.org/wiki/Steinhaus%E2%80%93Johnson%E2%80%93Trotter_algorithm#Even.27s_speedup
void EvensSpeedupUtil(char str[], int l, int r, int signs[])
{
	// Number of elements with sign zero
	int marked = r;
	while (marked > 0) {
		printf("%s\n", str);
		// Un-comment to print corresponding signs:
		//for (int i = 0; i <= r; i++) {
		//	printf("%i", signs[i]);
		//}
		//printf("\n");

		// Find largest element that has a sign 
		int largest = 0;
		int largestIndex = 0;
		for (int i = 0; i <= r; i++) {
			if (signs[i] != 0 && int(str[i]) > largest) {
				largest = int(str[i]);
				largestIndex = i;
			}
		}
		// Swap found element in its assigned direction
		int newIndex = largestIndex + signs[largestIndex];
		swap(str + largestIndex, str + newIndex);
		swap(signs[largestIndex], signs[newIndex]);
		// If swap causes the "largest" element to move into start or end of permutation (l or r)
		// or if the next element in direction of swap is larger than the "largest" element, 
		// set "largest" element's sign to zero
		if (newIndex == l || newIndex == r || (int(str[newIndex + signs[newIndex]]) > int(str[newIndex]))) {
			signs[newIndex] = 0;
			marked--;
		}
		// All elements greater than the chosen ("largest") element have their directions set to positive or negative, 
		// according to whether they are between the chosen element and the start or the end of the permutation respectively
		for (int i = 0; i < newIndex; i++) {
			if (int(str[i]) > int(str[newIndex])) {
				if (signs[i] == 0)
					marked++;
				signs[i] = 1;
			}
		}
		for (int i = newIndex + 1; i <= r; i++) {
			if (int(str[i]) > int(str[newIndex])) {
				if (signs[i] == 0)
					marked++;
				signs[i] = -1;
			}
		}
		// This line is necessary to print the last permutation
		if (marked == 0) {
			printf("%s\n", str);
			// Un-comment to print corresponding signs:
			//for (int i = 0; i <= r; i++) {
			//	printf("%i", signs[i]);
			//}
			//printf("\n");
		}
	}
}

void EvensSpeedup(char str[], int l, int r)
{
	int* strSigns = new int[r + 1];

	// Sort the string
	std::sort(str, str + r + 1);

	// Initialize the first element to have no sign
	strSigns[0] = 0;
	// All other elements have negative sign to begin
	for (int i = 1; i <= r; i++) {
		strSigns[i] = -1;
	}
	EvensSpeedupUtil(str, l, r, strSigns);
	delete[] strSigns;
}


// Driver program:
//#include <ctime>
//int main(int argc, char* argv[])
//{
//	char sampleStr[] = "abc";
//
//	printf("Print Permutations: \n");
//	clock_t t0 = clock();
//	permuteString(sampleStr, 0, 2);
//	clock_t t1 = clock();
//	float permuteTime = float(t1) - float(t0);
//
//	printf("\nEven's Speedup: \n");
//	t0 = clock();
//	EvensSpeedup(sampleStr, 0, 2);
//	t1 = clock();
//	float EvensTime = float(t1) - float(t0);
//
//	printf("\n");
//	printf("permuateString took %f milliseconds\n", permuteTime);
//	printf("EvensSpeedup took %f milliseconds\n", EvensTime);
//
//	return 0;
//}