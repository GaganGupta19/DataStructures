#include<stdlib.h>
#include<stdio.h>

struct node{
	int key;
	struct node *left, *right;
};

struct node* createnode(int key){
	struct node* newnode = (struct node*)malloc(sizeof(struct node));
	newnode -> key = key;
	newnode -> left = newnode -> right = NULL;
}

void preorder(struct node* root){
	if(root){
		printf("\n%d", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

int main(){
	struct node* root = NULL;
	root = createnode(1);
	root -> left = createnode(2);
	root -> right = createnode(3);
	preorder(root);
	free(root);
	return 0;
}