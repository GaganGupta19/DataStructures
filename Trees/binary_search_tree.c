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

int insert(struct node *root, int key){
	if(root == NULL){
		root = createnode(key);
		return 1;
	}
	else if(root -> key > key ){
		insert(root->left, key);
	}
	else if(root -> key < key ){
		insert(root -> right, key);
	}
	return -1;
}

void preorder(struct node* root){

	if(root){
		printf("\n%d", root->key);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(struct node* root){
	if(root){
		preorder(root->left);
		preorder(root->right);
		printf("\n%d", root->key);
	}
}

int main(){
	struct node* root = NULL;
	int choice, value;

	while(1){
		printf("\n1.Insert\n2.Preorder\n3.Postorder\n4.Exit\nEnter : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter the value : ");
				scanf("%d", &value);
				insert(root, value) == 1 ? printf("\nSuccess") : printf("\nFailed");
				break;
			case 2:
				preorder(root);
				break;
			case 3:
				postorder(root);
				break;
			case 4:
				return -1;
				break;
			default: 
				printf("\nEnter again");
				break;
		}
	}
	free(root);
	return 0;
}