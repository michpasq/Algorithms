#include <stdio.h>
#include "LinkedList.h"

int main()
{
	// Test that constructor works
	LinkedList<int> a(4);
	a.appendData(5);
	a.appendData(6);
	a.printList();

	// Test that default constructor works
	LinkedList<int> b;
	b.appendData(1);
	b.appendData(2);
	b.appendData(3);
	b.appendData(4);
	b.printList();

	// Test that copy constructor works
	LinkedList<int> c = a;
	std::cout << "Test copy constructor. c == a\n";
	std::cout << "c:\t";
	c.printList();
	std::cout << "a:\t";
	a.printList();


	// Test that assignment operator works
	c = b;
	c.printList();

	LinkedList<int> sorted1;
	LinkedList<int> sorted2;
	sorted1.appendData(1).appendData(3).appendData(5).appendData(10);
	sorted2.appendData(2).appendData(3).appendData(4).appendData(12);

	sorted1.printList();
	sorted2.printList();

	// More testing, documented in class definition
	LinkedList<int>::privateTesting();
	

	return 0;
}