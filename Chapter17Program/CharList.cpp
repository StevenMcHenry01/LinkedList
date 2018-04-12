#include "stdafx.h"
#include <iostream> // for cout and cin
#include "CharList.h"
using namespace std;

CharList::~CharList()
{
	ListNode* nodePtr; // To traverse the list
	ListNode* nextNode; // To point to the next node
	
	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;
		
		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}

void CharList::appendNode(char chr)
{
	ListNode* newNode; // To point to a new node
	ListNode* nodePtr; // To move through the list
	
	newNode = new ListNode; // Allocate a new node
	
	// LOW LEVEL Validity Check for char entered
	if (isalpha(chr) && isupper(chr)) //Checks for Capital Letter
		newNode->value = chr; // sets new node char entered
	else
	{
		cout << "Invalid entry. (Needs to be a capital Letter)" << endl;
		exit(EXIT_FAILURE); //Exit program
	}

	newNode->next = nullptr; // Sets the following node to null
	
	// If there are no nodes in the list
	// make newNode the first node.
	if (!head)
		head = newNode;
	else // Otherwise, insert newNode at end.
		{
		//Initialize nodePtr to head of list.
		nodePtr = head;
		
		// Find the last node in the list.
		while (nodePtr->next)
		nodePtr = nodePtr->next;
		
		// Insert newNode as the last node.
		nodePtr->next = newNode;
		}
}

void CharList::displayList() const
{
	ListNode* nodePtr; // To move through the list
	
	// Position nodePtr at the head of the list.
	nodePtr = head;
	
	// While nodePtr points to a node, traverse
	// the list.
	while (nodePtr)
		{
		// Display the value in this node.
		cout << nodePtr->value << endl;
		
		// Move to the next node.
		nodePtr = nodePtr->next;
		}
}

void CharList::insertNode(char chr, int pos)
{
	ListNode* newNode; // A new node
	ListNode* nodePtr; // To traverse the list
	ListNode* previousNode = nullptr; // The previous node

	int tempPos = 0;
	
	// Allocate a new node and store num there.
	newNode = new ListNode;
	
	// LOW LEVEL Validity Check for char entered
	if (isalpha(chr) && isupper(chr)) //Checks for Capital Letter
		newNode->value = chr; // sets new node char entered
	else
	{
		cout << "Invalid entry. (Needs to be a capital Letter)" << endl;
		exit(EXIT_FAILURE); //Exit program
	}
	
	// If there are no nodes in the list
	// make newNode the first node
	if (!head)
	{
		head = newNode;
		newNode->next = nullptr;
	}
	else // Otherwise, insert newNode
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		while (nodePtr->next != nullptr && tempPos != pos)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			tempPos++;
		}
		if (pos == 0)
		{
			cout << "Adding at Head! " << endl;
			head = newNode;
			newNode->next = nullptr;
		}
		else if (nodePtr->next == nullptr && pos == tempPos + 1)
		{
			cout << "Adding at Tail! " << endl;
			appendNode(chr);
		}
		else if (pos > tempPos + 1)
			cout << " Position is out of bounds " << endl;
		//Position not valid
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
			cout << "Node added at position: " << pos << endl;
		}
	}
}

void CharList::deleteNode(int pos)
{
	ListNode* nodePtr; // To traverse the list
	ListNode* previousNode = nullptr; // To point to the previous node

	int tempPos = 0;
	
	// If the list is empty, do nothing.
	if (!head)
		return;
	else // Otherwise, delete node
	{
		// Position nodePtr at the head of list.
		nodePtr = head;

		while (nodePtr->next != nullptr && tempPos != pos)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			tempPos++;
		}
		if (pos == 0)
		{
			cout << "Deleting at Head! " << endl;
			nodePtr = head->next;
			delete head;
			head = nodePtr;
		}
		else if (pos > tempPos + 1)
			cout << " Position is out of bounds " << endl;
		//Position not valid
		else
		{
			previousNode->next = nodePtr->next;
			delete nodePtr;
			cout << "Node deleted at position: " << pos << endl;
		}
	}
}

void CharList::reverseList()
{
	if (!head) 
		return;

	ListNode* previousNode = nullptr;
	ListNode* nodePtr = nullptr;
	ListNode* next = nullptr;

	nodePtr = head;

	while (nodePtr != nullptr) {
		next = nodePtr->next;
		nodePtr->next = previousNode;
		previousNode = nodePtr;
		nodePtr = next;
	}
	// now let the head point at the last node (prev)
	head = previousNode;
}

int CharList::searchList(char chr)
{
	ListNode* nodePtr;
	nodePtr = head;
	int i = 0;

	while (nodePtr != nullptr)
	{
		i++;
		if (nodePtr->value == chr)
			return i;
		else
			nodePtr = nodePtr->next;
	}
}