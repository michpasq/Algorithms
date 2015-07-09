#include <iostream>
#include <stdio.h>

// Notes "start" variable controls where loop of denominations begins-- important to not 
// count multiple permutations.
bool countCoins_Util(const int denominations[], const int size, const int amount, int& count, int coins[], int sum, int start) {
	if (sum > amount) {
		return false;
	}
	else if (sum == amount) {
		count++;
		std::cout << "Reached amount = " << amount << "! Printing coins:\n";
		for (int i = 0; i < size; i++) {
			printf("coins[%i] == %i\n", i, coins[i]);
		}
		printf("\n");

		return true;
	}
	else {
		std::cout << "sum is " << sum << '\n';
		for (int i = start; i < size; i++) {
			if (sum + denominations[i] <= amount) {
				coins[i] += 1;
				sum += denominations[i];
				printf("recursing with sum = %i and %ith coin set\n", sum, i);
				// Recurse at "start" = i (last argument) so that you don't consider
				// any previous elements. For example, 1,1,2 and 1,2,1 both sum to 4,
				// but we don't consider 1,2,1 because at 1,2... you won't consider 1
				// again in the recursion!
				if (countCoins_Util(denominations, size, amount, count, coins, sum, i)) {
					printf("recursion on sum %i plus %ith coin returned true\n", sum, i);
				}
				coins[i] -= 1;
				printf("sum = %i - %i\n", sum, denominations[i]);
				sum -= denominations[i];	
			}
		}
		return false;
	}
}

// In "denominations[]" 2 would indicate 2 cents
// "amount" is also in cents
int countCoins(const int denominations[], const int size, const int amount) {
	int n = 0;	// n counts number of ways
	int* coins = new int[size]();	// Adding () causes all values to be initilized to zero!!
	for (int i = 0; i < size; i++) {
		printf("init coins[%i] == %i\n", i, coins[i]);
	}

	int sum = 0;
	countCoins_Util(denominations, size, amount, n, coins, sum, 0);
	delete[] coins;
	return n;
}

int main()
{
	int denominations[] = {1,2,3};
	int size = 3;
	int amount = 4;

	int numWays = countCoins(denominations, size, amount);

	printf("Number of ways is %i\n", numWays);


	return 0;
}