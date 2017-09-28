//
//#include <iostream>
//using namespace std;
//
//struct Node {
//	int data;
//	struct Node *next;
//};
//
//void printLinkedList(struct Node *);
//void insertHead(struct Node **, int);
//void insertHead(struct Node *&head, int newValue);
//int getCount(struct Node *head);
//int recursiveGetCount(struct Node *head);
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
//	insertHead(&head, 4);
//	insertHead(&head, 5);
//	insertHead(&head, 6);
//	insertHead(&head, 7);
//	printLinkedList(head);
//
//	// test find length of linked list 
//	cout << "Number of nodes in linked list : " << getCount(head) << endl;
//	cout << "Number of nodes in linked list using recursive method : " << recursiveGetCount(head) << endl;
//
//
//	getchar();
//	return 1;
//}
//
//// Count number of nodes using recursive method
//int recursiveGetCount(struct Node *head) {
//	// Base case
//	if (head == NULL) return 0;
//	// Number of nodes is 1 plus to count of remaining nodes
//	return 1 + getCount(head->next);
//}
//
//
//// Count number of nodes in linked list
//int getCount(struct Node *head) {
//	int count = 0;
//	for (struct Node *currentNode = head; currentNode != NULL; currentNode = currentNode->next) {
//		count = count + 1;
//	}
//
//	return count;
//}
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