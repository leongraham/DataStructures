/*Linked list
  add and delete options
  First In First Out (FIFO)
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
bool isEmpty(node*& head);
void add(node*& head, node*& temp, node*& tail);
void user_selection(node*& head, node*& temp, node*& tail);
void printList(node*& head);

//test if list is empty
bool isEmpty(node*& head)
{
	if (head==NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//Adds node to list
void add(node*& head, node*& temp, node*& tail)
{
	string value;

	cout << "Enter value to add" << endl;
	cin >> value;

	//if first time
	if (isEmpty(head))
	{
		node *n = new node;
		n->data = value;
		n->next = tail;
		temp = n;
		head = n;
		cout << "added first value" << endl;
	}
	else
	{
		node *n = new node;
		n->data = value;
		n->next = tail;
		temp->next = n;
		temp = n;
	}
}

//deletes node starting from the head
void deleteList(node*& head)
{
	node *temp;

	if (isEmpty(head))
	{
		cout << "list is empty" << endl;
	}
	else
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}

//get user options
void user_selection(node*& head, node*& temp, node*& tail)
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
			     case 1: add(head, temp, tail);
				      break;
				 case 2: printList(head);
				      break;
				 case 3: deleteList(head);
				      break;
			     default: cout << "Input entered not an option." << endl;

		  }
		
	}
}

//traverses list and prints contents
void printList(node *&head)
{
	node *temp;
	temp = head;

	if (isEmpty(head))
	{
		cout << "list is empty" << endl;
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
	node *head=NULL;
	node *tail=NULL;
	node *temp=NULL;

	user_selection(head, temp, tail);
	
	return 0;
}
