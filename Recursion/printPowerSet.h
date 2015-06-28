#include <iostream>
#include <cmath>

using namespace std;

// NOTES:
// Still work though the permutations based method for understanding


// This utility function implements printPowerSet() by print all r-combinations
// for r in range [0, size). It looks very similar to the combinationsUtil()
// function but with the addition of "while (subset++ <= end)".
// Thus, this function is O(n^2 * n!). (combinationsUtil() is O(n * n!) = O(2^n)).
template <class T>
void powerSetUtil_byCombinations(T set[], int subsetSize, int start, int end, T data[], int index)
{
	if (subsetSize == index) {
		for (int i = 0; i < index; i++) {
			cout << data[i] << ' '; 
		}
		cout << '\n';
	}
	while (subsetSize++ <= end) {
		for (int i = start; i <= end; i++) {
			data[index] = set[i];
			powerSetUtil_byCombinations(set, subsetSize, i + 1, end, data, index + 1);
		}
	}
}

template <class T>
void powerSet_byCombinations(T set[], int size)
{
	T* data = new T[size]();
	cout << "Power Set:\n";
	powerSetUtil_byCombinations(set, 0, 0, size - 1, data, 0);
	delete[] data;
}
/**************************************************************************************/

// Found this function on SO. It looks like a variation of a normal print permutations
// algorithm.
void powerSet_byPermutationsUtil(char *arr, int arrLen, int pos, int startPos, int length)
{
	if (length == 0)
		printf("%.*s\n", pos, arr);
	else {
		for (int i = startPos; i < arrLen; i++) {
			std::swap(arr[pos], arr[i]);
			powerSet_byPermutationsUtil(arr, arrLen, pos + 1, i + 1, length - 1);
			std::swap(arr[pos], arr[i]);
		}
	}
}

void powerSet_byPermutations(char *arr, int arrLen)
{
	for (int i = 1; i <= arrLen; i++)
		powerSet_byPermutationsUtil(arr, 4, 0, 0, i);
}
/**************************************************************************************/

// This function prints the power set iteratively by incrementing the binary
// representation of the size of the set. There are 2^n subsets to print
// for a set of size n. The order it prints in looks funky because 
// it is based on binary representations.
template <class T>
void powerSet_Iterative(T set[], int size)
{
	int numSubsets = pow(2, size);
	int counter = 0;
	while (counter < numSubsets) {
		int index = 0;
		for (int i = counter; i > 0; i >>= 1) {
			if (i & 1) {
				cout << set[index];
			}
			index++;
		}
		cout << '\n';
		index = 0;
		counter++;
	}
}

// Note: change "printPowerSet()" to specific implementation.
// Driver program:
//int main()
//{
//	int sample = { 1, 2, 3, 4 };
//	printPowerSet(sample, 4);
//
//	return 0;
//}