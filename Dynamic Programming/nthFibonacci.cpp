#include <stdio.h>

int nthFibonacci(int n) {
	if (n == 0)
		return 0;
	int first = 0;
	int second = 1;
	while (n > 1) {
		int temp = first;
		first = second;
		second += temp;
		n--;
	}
	return second;
}

int main() {
	int n[] = {0,1,2,3,4,5,6};
	int size = sizeof(n)/sizeof(int);
	for (int i = 0; i < size; i++) {
		printf("Fibonacci of %i is %i\n", i, nthFibonacci(i));
	}

	return 0;
}