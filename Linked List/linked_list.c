#include<stdio.h>
#include<stdlib.h>
struct node {
	int key;
	struct node* next;
};

//for creation
struct node* createnode(int key){
	struct node *newnode = (struct node*) malloc(sizeof(struct node));
	newnode -> key = key;
	newnode -> next = NULL;
	return newnode;
}

//for traversal
void display(struct node* temp){
	struct node* head = temp;
	while(head->next != NULL){
		printf("%d\n", head->key);
		head = head->next;
	}
}

//for insertion at the end
int insertion(struct node* head, int key){
	if(head == NULL){
		head = createnode(key);
		return 1;	
	}
	else{
		printf("->%d", head->key);
		insertion(head->next, key);
	}
}

int main(){
	struct node* head, *temp ;
	head = NULL;
	temp = head;
	
	while(1){
		int choice, value;

		printf("\n1.Insertion\n2.Traversal\n3.Exit\nEnter : ");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 1: 
			printf("\nEnter value : ");
			scanf("%d",&value);
			if(insertion(temp, value))
				printf("\nSuccessful");
			break;

			case 2:
			display(head);
			break;

			case 3:
			return -1;
			break;
		}
	}

	free(temp);
	free(head);
	return 0;
}