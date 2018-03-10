/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL){
		return -1;
	}
	int l = 0;
	struct node *p = head;
	while (p != NULL){
		l++;
		p = p->next;
	}
	p = head;
	if (l % 2 == 0){
		int i = 1;
		while (i<l/2){
			p = p->next;
			i++;
		}
		return((p->num + p->next->num) / 2);
	}
	else{
		int i = 1;
		while (i < l / 2+1){
			p = p->next;
			i++;
		}
		return p->num;
	}
}
