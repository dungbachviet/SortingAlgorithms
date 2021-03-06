//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	struct Node *next;
//};
//
//
//void deleteNodeIndex(struct Node **, int index);
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
//	// test code source
//	insertHead(&head, 4);
//	insertHead(&head, 5);
//	insertHead(&head, 6);
//	insertHead(&head, 7);
//	printLinkedList(head);
//	cout << "Xoa index 0" << endl;
//	deleteNodeIndex(&head, 6);
//	printLinkedList(head);
//
//
//	getchar();
//	return 1;
//}
//
//// Delete a node at the given index
//void deleteNodeIndex(struct Node **addressOfHead, int index) {
//	struct Node *deletedNode = NULL, *previousNode = NULL;
//	int currentIndex = 0;
//
//	if ((*addressOfHead) == NULL) return;
//	if (index == currentIndex) {
//		deletedNode = (*addressOfHead);
//		(*addressOfHead) = (*addressOfHead)->next;
//		free(deletedNode);
//		return;
//	}
//	currentIndex++;
//	previousNode = (*addressOfHead);
//	deletedNode = previousNode->next;
//	while ((deletedNode != NULL) && (currentIndex != index)) {
//		previousNode = deletedNode;
//		deletedNode = deletedNode->next;
//		currentIndex++;
//	}
//	
//	if (deletedNode == NULL) return;
//	previousNode->next = previousNode->next->next;
//	free(deletedNode);
//}
//
//
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
//
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