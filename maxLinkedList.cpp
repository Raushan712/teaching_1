// C++ implementation of the approach
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

// Function to print the
// nodes of a linked list
void display(Node* root)
{
	while (root != NULL) {
		cout << root->data << " -> ";
		root = root->next;
	}
	cout << "NULL";
}

// Function to generate the required
// linked list and return its head
Node* newList(Node* root1, Node* root2)
{
	Node *ptr1 = root1, *ptr2 = root2;
	Node* root = NULL;

	// While there are nodes left
	while (ptr1 != NULL) {

		// Maximum node at current position
		int currMax = ((ptr1->data < ptr2->data)
						? ptr2->data
						: ptr1->data);

		// If current node is the first node
		// of the newly linked list being
		// generated then assign it to the root
		if (root == NULL) {
			Node* temp = new Node;
			temp->data = currMax;
			temp->next = NULL;
			root = temp;
		}

		// Else insert the newly
		// created node in the end
		else {
			insert(&root, currMax);
		}

		// Get to the next nodes
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	// Return the head of the
	// generated linked list
	return root;
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

	// Second linked list
	insert(&root2, 1);
	insert(&root2, 7);
	insert(&root2, 4);
	insert(&root2, 5);

	// Generate the new linked list
	// and get its head
	root = newList(root1, root2);

	// Display the nodes of the generated list
	display(root);

	return 0;
}
