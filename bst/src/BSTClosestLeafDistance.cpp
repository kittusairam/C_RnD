
/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};

int getLevelUtil(struct node *node, int data, int level)
{
	if (node == NULL)
		return 0;

	if (node->data == data)
		return level;

	int downlevel = getLevelUtil(node->left, data, level + 1);
	if (downlevel != 0)
		return downlevel;

	downlevel = getLevelUtil(node->right, data, level + 1);
	return downlevel;
}

int getLevel(struct node *node, int data)
{
	return getLevelUtil(node, data, 1);
}

int minDepth(struct node *root)
{
	// Corner case. Should never be hit unless the code is 
	// called on root = NULL
	if (root == NULL)
		return 0;

	// Base case : Leaf Node. This accounts for height = 1.
	if (root->left == NULL && root->right == NULL)
		return 0;

	// If left subtree is NULL, recur for right subtree
	if (!root->left)
		return minDepth(root->right) + 1;

	// If right subtree is NULL, recur for right subtree
	if (!root->right)
		return minDepth(root->left) + 1;

	int a = minDepth(root->left);
	int b=minDepth(root->right);
	if (a <= b){
		return a+1;
	}
	else{
		return b+1;
	}
}

int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL){
		return -1;
	}
	int ele_level = getLevel(root, temp->data);
	ele_level--;
	int dept1 = minDepth(temp);
	int dept2 = minDepth(root);
	if (dept2 + ele_level<= dept1){
		return dept2 + ele_level;
	}
	else{
		return dept1;
	}


}