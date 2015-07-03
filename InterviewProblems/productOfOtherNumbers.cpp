#include <iostream>

int* get_products_of_all_ints_except_at_index(int array[], int size)
{
    int* otherProducts = new int[size];

    int product = 1;
    for (int i = 0; i < size; i++) {
        otherProducts[i] = product;
        product *= array[i];
    }

    product = 1;
    for (int i = size - 1; i >= 0; i--) {
     	otherProducts[i] *= product;  // We use multiplication because the before product is already here
        product *= array[i];
    }

    return otherProducts;
}

// Test Driver program
int main()
{
	int array[] = {1,7,3,4};
	int size = 4;

	int* otherProducts = get_products_of_all_ints_except_at_index(array, size);
	for (int i = 0; i < size; i++) {
		std::cout << otherProducts[i] << ' ';
	}
	
	delete[] otherProducts;

	return 0;
}

/* Problem description on Interview Cake */