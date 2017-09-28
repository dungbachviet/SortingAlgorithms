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
//bool searchValue(struct Node *head, int value);
//bool recursiveSearchValue(struct Node *head, int value);
//
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
//	cout << "Does value 7 exist ?  : " << searchValue(head, 7) << endl;
//	cout << "Dose value 7 exist using recursive method ? " << recursiveSearchValue(head, 7) << endl;
//
//	cout << "Does value 17 exist ?  : " << searchValue(head, 17) << endl;
//	cout << "Does value 17 exist using recursive method ? " << recursiveSearchValue(head, 17) << endl;
//
//
//	getchar();
//	return 1;
//}
//
//// Checks whether the value x is present in linked list
//bool searchValue(struct Node *head, int value) {
//	struct Node *currentNode;
//	bool isPresented = false;
//	for (currentNode = head; currentNode != NULL; currentNode = currentNode->next) {
//		if (currentNode->data == value) {
//			isPresented = true;
//			break;
//		}
//	}
//
//	return isPresented;
//}
//
//// Using recursive methods for checking whether the value x is present in linked list
//bool recursiveSearchValue(struct Node *head, int value) {
//	if (head == NULL) return false;
//	if (head->data == value) 
//		return true;
//	return searchValue(head->next, value);
//
//
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