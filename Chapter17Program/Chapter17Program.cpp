// Chapter17Program.cpp : Defines the entry point for the console application.
/*
*
* Steven McHenry
*
* Chapter 17 programming assignment
*
* April 04, 2018
*
*/

#include "stdafx.h"
#include <iostream> // for cout and cin
#include <iomanip> // for output formatting
#include "CharList.h"
using namespace std;

//Function Prototypes
void displayMenu(CharList);
char validateChar(char);

int main()
{
	//Define a CharList Object
	CharList list;

	displayMenu(list);

    return 0;
}

void displayMenu(CharList list)
{
	// Constants for menu choices
	const int APPEND_CHOICE = 1,
		INSERT_CHOICE = 2,
		DELETE_CHOICE = 3,
		PRINT_CHOICE = 4,
		REVERSE_CHOICE = 5,
		SEARCH_CHOICE = 6,
		EXIT_CHOICE = 7;

	// Variables
	int choice; // Menu choice
	char newChar = '\0';
	int position = 999;

	do
	{
		// Display the menu.
		cout << "\n *************************" << endl;
		cout << " Linked List Menu!" << endl;
		cout << " *************************\n" << endl;
		cout << " 1. Append Node" << endl;
		cout << " 2. Insert at Position" << endl;
		cout << " 3. Delete at Position" << endl;
		cout << " 4. Print List" << endl;
		cout << " 5. Reverse List" << endl;
		cout << " 6. Search List" << endl;
		cout << " 7. Exit Program\n" << endl;
		cout << " Please enter your choice" << endl;
		cout << " (1, 2, 3, 4, 5, 6, or to exit enter 7): ";
		cin >> choice;
		
		//Check for integer input so program does not crash
		while (cin.fail()) {
			cin.clear(); // clears error flags
			cin.ignore(999, '\n'); // the first parameter is just some 
								   //arbitrarily large value, the second param 
								   //being the character to ignore till
			cout << "\nERROR - Please enter an integer for your menu choice!\n";
			cin >> choice;
		}

		switch (choice)
		{
		case APPEND_CHOICE:
			cout << "Please enter a capital letter to append: ";

			// HIGH LEVEL validity check
			newChar = validateChar(newChar);

			list.appendNode(newChar);

			break;
		case INSERT_CHOICE:
			cout << "Please enter a capital letter to insert: ";

			// HIGH LEVEL validity check
			newChar = validateChar(newChar);

			cout << "Please enter position: ";

			cin >> position;
			list.insertNode(newChar, position);
			break;
		case DELETE_CHOICE:

			cout << "Please enter position: ";

			cin >> position;
			list.deleteNode(position);
			break;
		case PRINT_CHOICE:
			list.displayList();
			break;
		case REVERSE_CHOICE:
			list.reverseList();
			break;
		case SEARCH_CHOICE:
			cout << "Please enter a capital letter to search: ";

			// HIGH LEVEL validity check
			newChar = validateChar(newChar);

			position = list.searchList(newChar);

			cout << newChar << " is at position " << position << endl;

			break;
		case EXIT_CHOICE:
			cout << "\nGoodbye, and thank you!\n\n" << endl;
			break;
		default: //check for incorrect menu choice
			cout << "\nERROR - Number must be within (1-7)";
		}
	} while (choice != EXIT_CHOICE); // end do while
}

char validateChar(char newChar)
{
	cin >> newChar;
	while (!isalpha(newChar) || !isupper(newChar))
	{
		cout << "ERROR - Please enter a capital Letter: ";
		cin >> newChar;
	}

	return newChar;
}


