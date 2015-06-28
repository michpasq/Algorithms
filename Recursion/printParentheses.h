#include <stdio.h>

void parenthesesUtil(int n, char data[], int index, int open, int closed)
{
	if (open + closed == 2 * n) {
		for (int i = 0; i < 2 * n; i++) {
			printf("%c", data[i]);
		}
		printf("\n");
	}
	else {
		if (open < n) {
			data[index] = '(';
			parenthesesUtil(n, data, index + 1, open + 1, closed);
		}
		if (open > closed) {
			data[index] = ')';
			parenthesesUtil(n, data, index + 1, open, closed + 1);
		}

	}

}

// Function that prints all closed sequences of n pairs of parentheses
void printParentheses(int n)
{
	char* data = new char[2 * n]();
	parenthesesUtil(n, data, 0, 0, 0);
	delete[] data;

}

// Driver program:
//int main()
//{
//	printParentheses(3);
//
//	return 0;
//}
