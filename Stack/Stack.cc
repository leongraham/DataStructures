/*Stack
add and delete options
First In Last Out (FILO)
Leon Graham, 2014 */

#include <iostream>
#include <limits>
#include <string>

using namespace std;

//define node
struct node
{
	string data;
	node* next;
};

//forward declarations
bool isEmpty(node*& top);
void push(node*& top, node*& temp, node*& bottom);
void user_selection(node*& top, node*& temp, node*& bottom);
void printList(node*& top);

//test if list is empty
bool isEmpty(node*& top)
{
	if (top == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Adds node to list
void push(node*& top, node*& bottom)
{
	string value;

	cout << "Enter value to add" << endl;
	cin >> value;

	//if first time
	if (isEmpty(top))
	{
		node *n = new node;
		n->data = value;
		n->next = bottom;
		top = n;
		cout << "added first value" << endl;
	}
	else
	{
		node *n = new node;
		n->data = value;
		n->next = top;
		top = n;
	}
}

//deletes node starting from the top
void pop(node*& top)
{
	node *temp;

	if (isEmpty(top))
	{
		cout << "stack is empty" << endl;
	}
	else
	{
		temp = top;
		top = top->next;
		delete temp;
	}
}

//get user options
void user_selection(node*& top, node*& temp, node*& bottom)
{
	int selection = 1;

	while (selection != 0)
	{
		cout << "Enter option:" << endl;
		cout << "0 - exit" << endl;
		cout << "1 - add" << endl;
		cout << "2 - print" << endl;
		cout << "3 - delete" << endl;

		while (!(cin >> selection))
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Please enter number option" << endl;
		}
		cout << endl;

		switch (selection)
		{
		case 0: break;
		case 1: push(top, bottom);
			break;
		case 2: printList(top);
			break;
		case 3: pop(top);
			break;
		default: cout << "Input entered not an option." << endl;

		}

	}
}

//traverses list and prints contents
void printList(node *&top)
{
	node *temp;
	temp = top;

	if (isEmpty(top))
	{
		cout << "stack is empty" << endl;
	}

	while (temp != NULL)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << endl;
}


int main()
{
	node *top = NULL;
	node *bottom = NULL;
	node *temp = NULL;

	user_selection(top, temp, bottom);

	return 0;
}
