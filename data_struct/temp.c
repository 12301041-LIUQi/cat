#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct TreeNode *BinTree;
struct TreeNode{
	const char *data;
	BinTree left;
	BinTree right;
};

/**
 * 先序遍历二叉树
 */
void preOrderTraversal(BinTree tree);

BinTree createChildTree(BinTree tree, char *left_data, char *right_data);

BinTree initTree();

char alphbet[] = "ABCDFGIEH";

int main(int argc, char const *argv[])
{
	// create binary tree...
	BinTree tree = initTree();
	printf("sizeof BinTree %lu, TreeNode %lu, struct TreeNode %lu\n", sizeof(BinTree), sizeof(TreeNode), sizeof(struct TreeNode));
	preOrderTraversal(tree);
	return 0;
}

void preOrderTraversal(BinTree tree){
	// more smarter way...
	if(tree){
		printf("node data of tree is %c\n", *(tree->data));
		preOrderTraversal(tree->left);
		preOrderTraversal(tree->right);
	}
}

BinTree initTree(){
	// root tree node....
	BinTree tree = (BinTree) malloc(sizeof(TreeNode));
	tree->data = &alphbet[0]; 
	tree->left = NULL; tree->right = NULL;
	// second level...
	createChildTree(tree, &alphbet[1], &alphbet[2]);
	printf("---%p, %p, %p\n", &alphbet[0], &alphbet[1], &alphbet[8]);
	// third level...
	createChildTree(tree->left, &alphbet[3], &alphbet[4]);
	createChildTree(tree->right, &alphbet[5], &alphbet[6]);

	// fourth level,not complete
	createChildTree(tree->left->right, &alphbet[7], NULL);
	createChildTree(tree->right->left, NULL, &alphbet[8]);
	return tree;
}

BinTree createChildTree(BinTree tree, char *left_data, char *right_data){
	if(left_data){
		BinTree left = (BinTree) malloc(sizeof(TreeNode));
		left->data = left_data; 
		left->left = NULL; left->right=NULL;
		tree->left = left;
	}
	if(right_data){
		BinTree right = (BinTree) malloc(sizeof(TreeNode));
		right->data = right_data; 
		right->left = NULL; right->right = NULL;
		tree->right = right;
	}
	return tree;
}
