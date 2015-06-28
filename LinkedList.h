#include <iostream>
#include <cassert>

template <typename T>
struct Node
{
	T data;
	Node* next;
};

template <typename T>
class LinkedList
{
typedef Node<T> Node;

public:

	// Default constructor, creates empty list
	LinkedList() : head(nullptr) {};

	// Constructor to create list with one node
	LinkedList(T init) {
		Node* nodePtr = new Node;
		nodePtr->data = init;
		nodePtr->next = nullptr;
		head = nodePtr;
	};

	// Copy constructor (deep copy of list)
	LinkedList(const LinkedList& otherList) {
		Node* current = otherList.head;
		if (!current) {
			head = nullptr;
		}
		else {
			Node* newHead = new Node;
			newHead->data = current->data;
			newHead->next = nullptr;	// Unecessary for copy, but good style to initialize data
			Node* newCurrent = newHead;
			while (current = current->next) {
				Node* copyNode = new Node;
				copyNode->data = current->data;
				newCurrent->next = copyNode;
				newCurrent = newCurrent->next;
			}
			newCurrent->next = nullptr;
			head = newHead;
		}	
	}

	// Destructor
	~LinkedList() {
		Node* current = head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		head = nullptr;
	};

	// Defining swap() for the copy-and-swap idiom (part of assignment operator overloading)
	friend void swap(LinkedList& first, LinkedList& second) {
		using std::swap;
		swap(first.head, second.head);
	}

	// Note that pass by value causes call to copy constructor, which has deep copy
	LinkedList& operator=(LinkedList other) {
		swap(*this, other);
		
		return *this;
	}

	// Pretty print function
	void printList() {
		if (head == nullptr) {
			std::cout << "{}\n";
			return;
		}
		else if (head->next == nullptr) {
			std::cout << head->data << '\n';
			return;
		}	
		else {
			Node* current = head;
			while (current->next != nullptr) {
				std::cout << current->data << " -> ";
				current = current->next;
			}
			std::cout << current->data << '\n';
		}
	}

	// Append data to end of current list
	// Returns reference to allow function chaining
	LinkedList& appendData(T _data) {
		if (head == nullptr) {
			*this = LinkedList(_data);
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			Node* nodePtr = new Node;
			nodePtr->data = _data;
			nodePtr->next = nullptr;
			current->next = nodePtr;
		}
		return *this;
	}

	LinkedList& appendList(Node* _node) {
		if (head == nullptr) {
			head = _node;
		}
		else {
			Node* current = head;
			while (current->next != nullptr) {
				current = current->next;
			}
			std::cout << "current is " << current->data << '\n';
			current->next = _node;
		}
		return *this;
	}

	static void privateTesting() {
		LinkedList<int> sorted1;
		LinkedList<int> sorted2;
		sorted1.appendData(1).appendData(3).appendData(5).appendData(10);
		sorted2.appendData(2).appendData(3).appendData(4).appendData(12);

		// Test appendList()
		//sorted1.appendList(sorted2.head);
		//sorted1.printList();

		Node* someNode = new Node;
		someNode->data = 100;
		someNode->next = nullptr;
		sorted1.head->next->next->next->next = someNode;
	}

private:

	Node* head;

};