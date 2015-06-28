#include <iostream>

using namespace std;

template <class T> 
void combinationsUtil(T set[], int start, int end, int r, T data[], int index)
{
	if (index == r) {
		for (int i = 0; i < r; i++) {
			cout << data[i] << " ";
		}
		cout << '\n';
	}
	else {
		// Including "(end + 1 - i >= r - index)" in the loop condition
		// prevents executing the recursive call when 
		// the number of positions left to assign to in "data" is greater than
		// the number of positions left to choose from in "set". E.g., if you have
		// set={1,2,3,4,5} and r=3, when you're at i==4 and index==1 you have 
		// two more spots to fill in data (indices 1 and 2), but you would only
		// look at "set[4]" (one spot) -- in other words, it's not worth the recursion
		// because you couldn't fill all the remaining spots to fill in "data" with 
		// looking at fewer spots in "set". In summary:
		// Continue as long as the number of positions in "set" to choose from
		// is as great as the number of positions in "data" to assigne to.
		for (int i = start; (i <= end) && (end + 1 - i >= r - index); i++) {
			data[index] = set[i];
			combinationsUtil(set, i + 1, end, r, data, index + 1);
		}
	}
}

// Function to print all r-combinations of set
template <class T> 
void printCombinations(T set[], int size, int r)
{
	T* data = new T[r];
	combinationsUtil(set, 0, size-1, r, data, 0);
	delete[] data;
}

// Driver program:
//int main()
//{
//	int sample[] = { 1, 2, 3, 4, 5 };
//	printCombinations(sample, 5, 3);
//
//	return 0;
//}
