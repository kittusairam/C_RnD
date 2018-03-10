/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	if (head == NULL){
		return NULL;
	}
	struct node *p=head;
	struct node *stack[20];
	int top = -1;
	while (p != NULL){
		stack[++top] = p;
		p = p->next;
	}
	p=head = stack[top];
	while (top != 0){
		p->next = stack[--top];
		p = p->next;
	}
	p->next = NULL;
	return head;
}
