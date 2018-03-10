/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder_f(struct node *root, int *arr,int *c){
	if (root != NULL){
		inorder_f(root->left, arr,c);
		arr[*c] = root->data;
		(*c)++;
		inorder_f(root->right, arr,c);
	}
}
void inorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int *c = new int();
	inorder_f(root, arr, c);
}
void preorder_f(struct node *root, int *arr, int *c){
	if (root != NULL){
		arr[*c] = root->data;
		(*c)++;
		preorder_f(root->left, arr, c);
		preorder_f(root->right, arr,c);
	}
}
void preorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int *c = new int();
	preorder_f(root, arr, c);
}
void postorder_f(struct node *root, int *arr, int *c){
	if (root != NULL){
		postorder_f(root->left, arr, c);
		postorder_f(root->right, arr, c);
		arr[*c] = root->data;
		(*c)++;
	}
}
void postorder(struct node *root, int *arr){
	if (root == NULL || arr == NULL){
		return;
	}
	int *c = new int();
	postorder_f(root,arr, c);
}

