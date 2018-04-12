#pragma once

class CharList
{
private:
	//declare struct for list
	struct ListNode 
	{
		char value;			// Value in the node
		struct ListNode* next;	// To point to the next node
	};

	ListNode* head;

public:
	//Constructor
	CharList()
	{
		head = nullptr;
	}

	// Destructor
	~CharList();

	// Linked List operations
	void appendNode(char);
	void insertNode(char, int);
	void deleteNode(int);
	void reverseList();
	int searchList(char);
	void displayList() const;
	
};

