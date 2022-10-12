// C++ program to create a new linked list
// from two given linked list
// of the same size with
// the greater element among the two at each node

#include <iostream>
using namespace std;

// Representation of node
struct Node {
	int data;
	Node* next;
};

// Function to insert node in a linked list
void insert(Node** root, int item)
{
	Node *ptr, *temp;
	temp = new Node;
	temp->data = item;
	temp->next = NULL;

	if (*root == NULL)
		*root = temp;
	else {
		ptr = *root;
		while (ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = temp;
	}
}

// Function which returns new linked list
Node* newList(Node* root1, Node* root2)
{
	Node *ptr1 = root1, *ptr2 = root2, *ptr;
	Node *root = NULL, *temp;

	while (ptr1 != NULL) {
		temp = new Node;
		temp->next = NULL;

		// Compare for greater node
		if (ptr1->data < ptr2->data)
			temp->data = ptr2->data;
		else
			temp->data = ptr1->data;

		if (root == NULL)
			root = temp;
		else {
			ptr = root;
			while (ptr->next != NULL)
				ptr = ptr->next;

			ptr->next = temp;
		}
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return root;
}

void display(Node* root)
{
	while (root != NULL) {
		cout << root->data << "->";
		root = root->next;
	}

	cout << endl;
}

// Driver code
int main()
{
	Node *root1 = NULL, *root2 = NULL, *root = NULL;

	// First linked list
	insert(&root1, 5);
	insert(&root1, 2);
	insert(&root1, 3);
	insert(&root1, 8);

	cout << "First List: ";
	display(root1);

	// Second linked list
	insert(&root2, 1);
	insert(&root2, 7);
	insert(&root2, 4);
	insert(&root2, 5);

	cout << "Second List: ";
	display(root2);

	root = newList(root1, root2);
	cout << "New List: ";
	display(root);
	return 0;
}
