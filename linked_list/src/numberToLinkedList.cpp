/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include<math.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};
struct node * createNode(int n1) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = n1;
	newNode->next = NULL;
	return newNode;
}
void add(struct node **head, int p){
	struct node *temp = *head;
	if (*head == NULL){
		(*head) = createNode(p);
		(*head)->next = NULL;
	}
	else{
		temp = createNode(p);
		temp->next=*head;
		*head = temp;
	}
}

struct node * numberToLinkedList(int N) {
	struct node *head=NULL;
	if (N == 0){
		head = createNode(0);
		head->next = NULL;
		return head;
	}
	N = abs(N);
	while (N){
		int r = N % 10;
		add(&head, r);
		N = N / 10;
	}
	return head;
}