/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes
will be followed by ones and then twos.

You should only change the links and shouldnt swap the data. Basically no write operation should be done on data field.

INPUTS:  SLL head pointer
OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2
ERROR CASES:
NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};

/*
Optional : For this function swapping data is allowed.Although this wont be tested on our end.
It is only for learning purpose.
*/
void sll_012_sort_swapData(struct node **head, struct node *p, struct node *q){
	struct node *t,*t2=q->next,*t3;
	if (p == *head){
		t = *head;
		while (t->next != q){
			t = t->next;
		}
		t->next = p;
		q->next = p->next;
		p->next = t2;
		*head = q;
	}
	else{
		t =t2= *head;
		while (t->next != p){
			t = t->next;
		}
		while (t2->next != q){
			t2 = t2->next;
		}
		if (p->next == q){
			p->next = q->next;
			t->next = q;
			q->next = p;
			return;
		}
		t3 = p->next;
		p->next = q->next;
		t->next = q;
		t2->next = p;
		q->next = t3;
	}
}

/*
This is the actual function. You are supposed to change only the links.
*/
void sll_012_sort(struct node **head){
	struct node *p, *q,*t;
	p = q = *head;
	while (p != NULL){
		q = p;
		while (q != NULL){
			if (p->data > q->data){
				sll_012_sort_swapData(head, p,q);
				t = p;
				p = q;
				q = t;
			}
			q = q->next;
		}
		p=p->next;
	}
	return;
}

