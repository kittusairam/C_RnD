/*
	problemCode : maxGold
	score : 20


 * Question:    Ragnar Lothbrok, a famous treasure collector went on an expedition to Paris. The Paris king offered him
 *              gold but the amount of gold offering depends on this problem.
 *				
 *              Ragnar need to start from the root of the 3-ary TREE and should reach any leaf. In this tree,
 *              each node contains either 0 or 1. Along the path travelled by Ragnar (root to leaf), forms a binary
 *              number. Ragnar will get the gold in tons of decimal value of the binary number.
 *
 *				A 3-ary tree is similar to any other tree except each node can have a maximum of 3 children.
 *
 *              Ragnar asked his intelligent friend Loki (you). How much maximum gold can they get,
 *
 * Example:                 1
 *                     /    |    \
 *                  0       1       0
 *                / | \   / | \   / | \   
 *               0  1  1 1  0  0 1  1  0
 *
 * Explanation:     In the above example, root to leaf paths are 100, 101, 101, 111, 110, 110, 101, 101, 100
 *                  Amoung them, 111 forms are highest decimal value which is 7.
 *                  So, Ragnar Lothbrok gets 7 tons of gold.
 *                  Return 7.
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include<math.h>

struct node {
    int bin;
    struct node* firstnode;
    struct node* secondnode;
	struct node* thirdnode;
};

int count(struct node* root){
	if (root->firstnode == NULL&&root->secondnode==NULL&&root->thirdnode==NULL){
		if (root->bin == 1)
		return 1;
		else
			return 0;
	}
	else{
		int one = count(root->firstnode);
		int two = count(root->secondnode);
		int three = count(root->thirdnode);
		if (one > two&&one > three){
			if (root->bin == 1){
				return one + 1;
			}
			return one;
		}
		else if (two > three){
			if (root->bin == 1){
				return two + 1;
			}
			return two;
		}
		else{
			if (root->bin == 1){
				return three + 1;
			}
			return three;
		}
		
	}
}

int MaxGold(struct node* root) {
	int n;
	if (root == NULL){
		return -1;
	}
	n = count(root);
	return pow(2.0,n)-1;
}
