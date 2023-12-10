#include<iostream>
using namespace std;

//CDLL is similar to the DLL except that the last node of the CDLL points to the first node and fist node of the CDLL points to the last node.

struct node
{
	node *next;
	int data;
	node *prev;
};

node *create_node(int data)
{
	node *temp = (node *)malloc(sizeof(node));
	temp->prev = temp;
	temp->data = data;
	temp->next = temp;

	return temp;
}

node *insert_at_start(node *tail, int data)
{
	node *pnew = create_node(data);

	if (tail == NULL)
	{
		return pnew;
	}
	else
	{
		node *temp = tail->next;

		pnew->prev = tail;
		pnew->next = temp;
		temp->prev = pnew;
		tail->next = pnew;
	}
}

node *insert_at_end(node *tail, int data)
{
	node *pnew = create_node(data);

	if (tail == NULL)
		return pnew;
	else
	{
		node *temp = tail->next;
		pnew->next = temp;
		pnew->prev = tail;
		tail->next = pnew;
		temp->prev = pnew;
		tail = pnew;

		return tail;
	}
}

node *insert_btw_node(node *tail, int data, int pos)
{
	node *pnew = create_node(data);
	if (tail == NULL)
		return pnew;

	node *temp = tail->next;
	while (pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	pnew->prev = temp;
	pnew->next = temp->next;
	temp->next->prev = pnew;
	temp->next = pnew;

	if (temp == tail)
	{
		tail = tail->next;
	}
	return tail;
}

node *delete_first_node(node *tail)
{
	if (tail == NULL)
		return tail;

	node *temp = tail->next;

	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}

	tail->next = temp->next;
	temp->prev = tail->next;                //temp->next->prev=tail;
	free(temp);
	return tail;
}

node *delete_last_node(node *tail)
{
	node *temp = tail->next;
	if (tail == NULL)
		return tail;

	if (temp == tail)
	{
		free(tail);
		tail = NULL;
		return tail;
	}
	temp = tail->prev;

	temp->next = tail->next;
	tail->next->prev = temp;

	free(tail);
	tail = temp;
	return tail;
}

node *delete_btw_node(node *tail, int pos)
{
	node *temp = tail->next;
	while (pos > 1)
	{
		temp = temp->next;
		pos--;
	}
	node *temp2 = temp->prev;
	temp2->next = temp->next;
	tail->prev = temp2->prev;               //temp->next->prev = temp2;   =>method 2
	free(temp);

	if (temp == tail)
		tail = temp2;
	return tail;
}

void print(node *tail)
{
	if (tail == NULL)
	{
		cout << "No Element in the List !" << endl;
	}
	else
	{
		node *temp = tail->next;
		do
		{
			cout << temp->data << "  ";
			temp = temp->next;
		} while (temp!=tail->next);
	}
	cout << endl << endl << endl;
}



int main()
{
	node *tail = NULL;
	
	cout << "Creating node in Doubly Circular Linked List !" << endl;
	tail = create_node(66);
	print(tail);

	cout << "Inserting at the start of the node in Doubly Circular Linked List !" << endl;
	tail = insert_at_start(tail, 44);             //Time Complexity= O(1)
	tail = insert_at_start(tail, 22);             //Time Complexity= O(1)
	print(tail);

	cout << "Inserting at the end of the node in Doubly Circular Linked List !" << endl;
	tail = insert_at_end(tail, 99);                 //Time Complexity= O(1)
	tail = insert_at_end(tail, 111);                 //Time Complexity= O(1)
	print(tail);

	cout << "Inserting between the node in Doubly Circular Linked List !" << endl;
	tail = insert_btw_node(tail, 77, 2);                 //Time Complexity= O(n)
	tail = insert_btw_node(tail, 88, 2);                 //Time Complexity= O(n)
	print(tail);

	cout << "Deleting the first node in Doubly Circular Linked List !" << endl;
	tail = delete_first_node(tail);                 //Time Complexity= O(1)
	print(tail);

	cout << "Deleting the last node in Doubly Circular Linked List !" << endl;
	tail = delete_last_node(tail);                 //Time Complexity= O(1)
	print(tail);

	cout << "Deleting the center node in Doubly Circular Linked List !" << endl;
	tail = delete_btw_node(tail, 2);                 //Time Complexity= O(n)
	print(tail);


	return 0;
}