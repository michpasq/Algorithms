#include <iostream>
#include <vector>

void crossOff(std::vector<bool>& flags, int prime)
{
	for (int i = prime * prime; i < flags.size(); i += prime) {
		flags[i] = false;
	}
}

int getNextPrime(std::vector<bool> flags, int prime)
{
	int next = prime + 1;
	while (next < flags.size() && !flags[next])
		next++;
	return next;
}

std::vector<bool> sieveOfEratosthenes(int max)
{
	std::vector<bool> flags(max + 1, true);
	flags[0] = flags[1] = false;
	int prime = 2;

	while (prime <= max)
	{
		// Cross of remaining multiples of prime
		crossOff(flags, prime);

		// Find next value which is true
		prime = getNextPrime(flags, prime);

		if (prime >= flags.size())
			break;
	}

	return flags;
}

int main()
{
	std::vector<bool> flaggedPrimes = sieveOfEratosthenes(10);
	for (int i = 0; i < flaggedPrimes.size(); i++) {
		if (flaggedPrimes[i])
			std::cout << i << '\n';
	}
	return 0;
}