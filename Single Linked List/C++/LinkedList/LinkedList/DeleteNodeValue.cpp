//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	struct Node *next;
//};
//
//void deleteNodeValue(struct Node **, int value);
//void printLinkedList(struct Node *);
//void insertHead(struct Node **, int);
//void insertHead(struct Node *&head, int newValue);
//
//
//int main() {
//	struct Node *head = NULL, *second = NULL, *third = NULL;
//	// Alocate memory for all pointers
//	head = (struct Node *) malloc(sizeof(struct Node));
//	second = (struct Node *) malloc(sizeof(struct Node));
//	third = (struct Node *) malloc(sizeof(struct Node));
//
//	// Assign value for each node and link them together
//	head->data = 1;
//	head->next = second;
//
//	second->data = 2;
//	second->next = third;
//
//	third->data = 3;
//	third->next = NULL;
//
//	// test function insertHead
//	printLinkedList(head);
//	insertHead(&head, 4);
//	insertHead(&head, 5);
//	insertHead(&head, 6);
//	insertHead(&head, 7);
//	printLinkedList(head);
//	deleteNodeValue(&head, 4);
//	printLinkedList(head);
//	deleteNodeValue(&head, 5);
//	printLinkedList(head);
//	deleteNodeValue(&head, 6);
//	printLinkedList(head);
//	deleteNodeValue(&head, 3);
//	printLinkedList(head);
//
//	getchar();
//	return 1;
//}
//
//// Delete the first occurrence of value in linked list
//void deleteNodeValue(struct Node **addressOfHead, int value) {
//	struct Node *deletedNode, *previousNode;
//
//	// When the linked list is empty
//	if ((*addressOfHead) == NULL) return;
//
//	// When the node needs to be deleted is the head node
//	if ((*addressOfHead)->data == value) {
//		deletedNode = (*addressOfHead);
//		(*addressOfHead) = (*addressOfHead)->next;
//		free(deletedNode);
//		return;
//	}
//	previousNode = (*addressOfHead);
//	deletedNode = previousNode->next;
//	while ((deletedNode != NULL) && (deletedNode->data != value)) {
//		previousNode = deletedNode;
//		deletedNode = deletedNode->next;
//	}
//	// If value was not found in linked list
//	if (deletedNode == NULL) return;
//
//	// Unlink the node from the linked list
//	previousNode->next = previousNode->next->next;
//	free(deletedNode);
//}
//
//// Display the linked list on the screen
//void printLinkedList(struct Node *head) {
//	struct Node *tempNode = head;
//
//	if (tempNode == NULL) return;
//	cout << endl;
//	cout << tempNode->data << " ";
//
//	while (tempNode->next != NULL) {
//		cout << "-> ";
//		tempNode = tempNode->next;
//		cout << tempNode->data << " ";
//	}
//	cout << endl;
//
//}
//
//// Insert new node to the head of linked list using value passing
//void insertHead(struct Node **addressOfHead, int newValue) {
//	struct Node *newNode = NULL;
//
//	// Allocate memory for new node
//	newNode = (struct Node *) malloc(sizeof(struct Node));
//	newNode->data = newValue;
//	newNode->next = NULL;
//
//	// Attach the new node at the head of link list
//	newNode->next = *addressOfHead;
//	*addressOfHead = newNode;
//}
//
//// Insert new node to the head of linked list using reference passing
//void insertHead(struct Node *&head, int newValue) {
//	struct Node *newNode = NULL;
//
//	// Allocate memory for new node
//	newNode = (struct Node *) malloc(sizeof(struct Node));
//	newNode->data = newValue;
//	newNode->next = NULL;
//
//	// Attach the new node at the head of link list
//	newNode->next = head;
//	head = newNode;
//}