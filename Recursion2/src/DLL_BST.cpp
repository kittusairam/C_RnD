/*
Given a Sorted Doubly Linked List and a Binary Search Tree , 
Check if they are identical or not .
The DLL will have nodes of type node_dll

Note :
	A DLL can be represented as a BST in many forms ,
	And if a dll and any one of the forms is given as input you
	need to return 1 otherwise 0.

	->Dont Create an Extra Array ,or else your solution would receive 20% Cut in the Marks you got .

Examples :

	Example 0:
	
	DLL:1->5->8

	BST(All 3 return 1):

	  5         8      1
	 / \       /        \
    1   8     5          5
               \
                8

		Returns 1


Example 1:
	
		DLL : 1->5
		
		BST :
			5
			 \
			  10
		
		Returns 0

Example 2:

	DLL:1->3->5-9->11
	
		BST:
		
		 5
		/ \
	   1   11
		\  /
1		3 9

	Returns 1


Example 3:
	
	DLL: 1->5->7->10->12->15->20
		
		BST:
		
		  10
		 /   \
	    5    15
	   / \   / \
	  1  7  12 20
Returns 1

Note 2 :
	Unequal Length BST and DLL should return 0;
	Return -1 for NULL inputs

*/

#include<stdio.h>
#include<stdlib.h>

struct node_dll {
	int data;
	struct node_dll *next;
	struct node_dll *prev;
};

struct node_bst {
	int data;
	struct node_bst *left;
	struct node_bst *right;
};


int countNodes(struct node_dll *head)
{
	int count = 0;
	struct node_dll *temp = head;
	while (temp)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
int find(int key, struct node_bst *root){
	if (root == NULL){
		return 0;
	}
	else if (root->data == key){
		return 1;
	}
	else if (root->data > key){
		return(find(key, root->left));
	}
	else{
		return(find(key, root->right));
	}
}
int is_identical(struct node_dll *head, struct node_bst *root) {
	if (head == NULL){
		root = NULL;
		return -1;
	}
	int n = countNodes(head);
	struct node_dll *temp = head;
	int c = 0;
	while (temp->next!=NULL)
	{
		temp = temp->next;
		if (find(temp->data, root)==1){
			c++;
		}
		else{
			break;
		}
	}
	if (c == n-1){
		return 1;
	}
	else{
		return 0;
	}
}




