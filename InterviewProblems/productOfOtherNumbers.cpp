#include <iostream>

int* get_products_of_all_ints_except_at_index(int array[], int size)
{
    int* beforeProducts = new int[size];
    int afterProducts[size];

    int product = 1;
    for (int i = 0; i < size; i++) {
        beforeProducts[i] = product;
        product *= array[i];
    }

    product = 1;
    for (int i = size - 1; i >= 0; i--) {
     	afterProducts[i] = product;
        product *= array[i];
    }

    for (int i = 0; i < size; i++ ) {
     	  beforeProducts[i] *= afterProducts[i]; 
    }
    
    return beforeProducts;
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