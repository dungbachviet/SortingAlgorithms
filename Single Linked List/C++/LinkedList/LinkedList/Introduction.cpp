////#include <stdio.h> // input, output,...
////#include <stdlib.h> // dynamic allocation, ...
//
//#include <iostream>
//
//
//struct Node {
//	int data;
//	struct Node * next;
//};
//
//void printLinkedList(struct Node *);
//
//
//int main() {
//	struct Node *head = NULL;
//	struct Node *second = NULL;
//	struct Node *third = NULL;
//	
//	// Allocate memory for pointers
//	head = (struct Node *) malloc(sizeof(struct Node));
//	second = (struct Node *) malloc(sizeof(struct Node));
//	third = (struct Node *) malloc(sizeof(struct Node));
//
//	// Assign values for each node and link them together
//	head->data = 1;
//	head->next = second;
//	
//	second->data = 2;
//	second->next = third;
//
//	third->data = 3;
//	third->next = NULL;
//
//	printLinkedList(head);
//
//	getchar();
//	return 1;
//}
//
//// Display the node list on screen
//void printLinkedList(struct Node *head) {
//	struct Node *tempNode = head;
//
//	if (tempNode == NULL) return;
//	printf("\n%d ", tempNode->data);
//	while (tempNode->next != NULL) {
//		printf("-> ");
//		tempNode = tempNode->next;
//		printf("%d ", tempNode->data);
//	}
//	printf("\n");
//}
