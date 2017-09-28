
#include <iostream>
using namespace std;

struct Node {
	int data;
	struct Node *next = NULL;
};

void printLinkedList(struct Node *);
void insertHead(struct Node **, int);
void insertHead(struct Node *&head, int newValue);
void swapNodes(struct Node **addressOfHead, int index1, int index2);


int main() {
	struct Node *head = NULL, *second = NULL, *third = NULL;

	// Alocate memory for all pointers
	head = (struct Node *) malloc(sizeof(struct Node));
	second = (struct Node *) malloc(sizeof(struct Node));
	third = (struct Node *) malloc(sizeof(struct Node));

	// Assign value for each node and link them together
	head->data = 1;
	head->next = second;

	second->data = 2;
	second->next = third;

	third->data = 3;
	third->next = NULL;

	// Test function insertHead
	insertHead(&head, 4);
	insertHead(&head, 5);
	insertHead(&head, 6);
	insertHead(&head, 7);
	printLinkedList(head);

	// Test function swapNodes
	swapNodes(&head, 0, 3);
	printLinkedList(head);
	swapNodes(&head, 0, 2);
	printLinkedList(head);
	swapNodes(&head, 0, 1);
	printLinkedList(head);
	swapNodes(&head, 0, 0);
	printLinkedList(head);

	getchar();
	return 1;
}

void swapNodes(struct Node **addressOfHead, int index1, int index2) {
	int countOfNodes = 0;
	struct Node *currentNode = NULL, *previousNode1 = NULL, *currentNode1 = NULL, *previousNode2 = NULL, *currentNode2 = NULL;

	// Is the same index, don't swap
	if (index1 == index2) return;

	// Count the total of nodes in the linked list
	for (currentNode = (*addressOfHead); currentNode != NULL; currentNode = currentNode->next) {
		countOfNodes++;
	}

	// Check the validation of index1, index2 variables
	if ((index1 < 0) || (index1 > countOfNodes - 1))
		return;
	if ((index2 < 0) || (index2 > countOfNodes - 1))
		return;

	// Find previousNode1, CurrentNode1
	int tempIndex = 0;
	currentNode1 = (*addressOfHead);
	while (tempIndex < index1) {
		previousNode1 = currentNode1;
		currentNode1 = currentNode1->next;
		tempIndex++;
	}

	// Find previousNode2, CurrentNode2
	tempIndex = 0;
	currentNode2 = (*addressOfHead);
	while (tempIndex < index2) {
		previousNode2 = currentNode2;
		currentNode2 = currentNode2->next;
		tempIndex++;
	}
	
	// When those two swapped nodes is adjacent
	if (index1 + 1 == index2) {
		// Check if currentNode1 is the top of the linked list
		if (currentNode1 != (*addressOfHead)) {
			previousNode1->next = currentNode2;
		}
		else {
			(*addressOfHead) = currentNode2;
		}
		currentNode1->next = currentNode2->next;
		currentNode2->next = currentNode1;

	}
	else {
		// Check if the currentNode1 is the top of the linked list
		if (currentNode1 != (*addressOfHead)) {
			previousNode1->next = currentNode2;
		}
		else {
			(*addressOfHead) = currentNode2;
		}

		previousNode2->next = currentNode1;
		struct Node *tempNode = currentNode2->next;
		currentNode2->next = currentNode1->next;
		currentNode1->next = tempNode;
	}
}



// Insert new node to the head of linked list using value passing
void insertHead(struct Node **addressOfHead, int newValue) {
	struct Node *newNode = NULL;

	// Allocate memory for new node
	newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = newValue;
	newNode->next = NULL;

	// Attach the new node at the head of link list
	newNode->next = *addressOfHead;
	*addressOfHead = newNode;
}

// Insert new node to the head of linked list using reference passing
void insertHead(struct Node *&head, int newValue) {
	struct Node *newNode = NULL;

	// Allocate memory for new node
	newNode = (struct Node *) malloc(sizeof(struct Node));
	newNode->data = newValue;
	newNode->next = NULL;

	// Attach the new node at the head of link list
	newNode->next = head;
	head = newNode;
}

// Display the linked list on the screen
void printLinkedList(struct Node *head) {
	struct Node *tempNode = head;

	if (tempNode == NULL) return;
	cout << endl;
	cout << tempNode->data << " ";

	while (tempNode->next != NULL) {
		cout << "-> ";
		tempNode = tempNode->next;
		cout << tempNode->data << " ";
	}
	cout << endl;

}