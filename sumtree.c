#include <stdio.h>
#include <stdlib.h>

struct Node {
	int val;
	struct Node * left;
	struct Node * right;
};


// Make a node
struct Node * makeNode(int val){
	struct Node * nodee = (struct Node *)malloc(sizeof(struct Node));
	if(nodee){
		nodee->val = val;
		nodee->left = NULL;
		nodee->right = NULL;
	}else{
		printf("Failed to a create node\n");
	}
	return nodee;
}

//Finding sum of a subtree
int sumOfSubTree(struct Node * node){
	//If the node is empty
	if(node == NULL){
		return 0;
	}else{
		//calculates the sum of the subtree recursively
		return node->val + sumOfSubTree(node->left) + sumOfSubTree(node->right);
	}
}

int validateSumTree(struct Node * node){
	int left_stree,right_stree,summ;

	//Empty tree is a sum tree
	if(node==NULL){
		return 1;
	}

	//Only leaf is also a sum tree
	if(node->left==NULL && node->right==NULL){
		return 1;
	}

	left_stree = sumOfSubTree(node->left);
	right_stree = sumOfSubTree(node->right);

	summ = left_stree + right_stree;

	if((node->val == summ) && validateSumTree(node->left) && validateSumTree(node->right)){
		return 1;
	}

	return 0;
}

int main(){
	struct Node * node;

	node = makeNode(20);

	node->left = makeNode(6);
	node->right = makeNode(4);

	node->left->left = makeNode(2);
	node->left->right = makeNode(4);

	node->right->left = makeNode(1);
	node->right->right = makeNode(3);

	/*
			     20
			  /       \
			6           4
		      /   \        /  \
		     2     4      1    3
	*/

	if(validateSumTree(node))
        printf("Sum Tree\n");
    else
        printf("Not a Sum Tree\n");

	return 0;
}
