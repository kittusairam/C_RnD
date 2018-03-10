/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int K) {
	struct node *p=head,*q=head;
	int i=0;
	if (head == NULL){
		return NULL;
	}
	if (K <= 1){
		return NULL;
	}
	else{
		for (int i = 1;p != NULL; i++){
			if ((i) % K == 0){
				q->next = p->next;
			}
			q = p;
			p = p->next;
		}
	}
	return head;
}