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

struct node* insert(struct node *root, int key){

    if (root == NULL) return createnode(key);

    if (key < root->key)
        root->left  = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);   
    
    return root;
}

void preorder(struct node* root){

	if(root){
		printf("%d->", root->key);
		preorder(root -> left);
		preorder(root -> right);
	}
}

void postorder(struct node* root){
	if(root){
		postorder(root -> left);
		postorder(root -> right);
		printf("%d->", root->key);
	}
}

void inorder(struct node* root){
	if(root){
		inorder(root -> left);
		printf("%d->", root->key);
		inorder(root -> right);
	}
}

int main(){
	struct node* root = NULL;
	int choice, value;

	printf("\nEnter the root node : ");
	scanf("%d", &value);
	root = insert(root, value);

	while(1){
		printf("\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.All Traversals\n6.Exit\nEnter : ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("\nEnter the value : ");
				scanf("%d", &value);
				(temp = insert(root, value)) != NULL ? printf("\nInserted : %d", temp -> key) : printf("\nFailed");
				break;
			case 2:
				printf("\n");
				preorder(root);
				break;
			case 3:
				printf("\n");
				postorder(root);
				break;
			case 4:
				printf("\n");
				inorder(root);
				break;
			case 5:
				printf("\nPreorder : "); preorder(root);
				printf("\nPostorder : "); postorder(root);
				printf("\nInorder : "); inorder(root);
				break;								
			case 6:
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