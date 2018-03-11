/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
};

struct BstNode *find_node(struct BstNode *root, int k){
	if (root==NULL||root->data <= k){
		return root;
	}
	else if (root->data < k){
		return find_node(root->right, k);
	}
	else{
		return find_node(root->left, k);
	}
}
void merge_two_bst(struct BstNode **root1, struct BstNode *root2) {
	if (root1 == NULL||root2==NULL){
		return;
	}
	struct BstNode *temp = find_node(*root1, root2->data);
	if (temp != NULL){
		struct BstNode *temp_next = temp->left;
		struct BstNode *temp_prev = temp->right;
		temp->left = root2;
		while (root2->right != NULL){
			root2 = root2->right;
		}
		root2->right = temp_next;
	}
	

}