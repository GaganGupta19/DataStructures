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
	while(head != NULL){
		printf("%d\n", head -> key);
		head = head -> next;
	}
}

//for insertion at the end
int insertion(struct node** head, int key, int position){
	struct node *tempnode = createnode(key);
	if(*head == NULL){
		*head = tempnode;
		return 1;
	}
	else if(position == 0){
		tempnode -> next = *head;
		*head = tempnode;
		return 1;
	}
	else if(position == -1){
		while((*head) -> next != NULL)
			*head = (*head) -> next;
		(*head) -> next = tempnode;
		return 1;
	}
	else{
		int count = 1;
		while((*head) -> next != NULL && count != position){
			count++;
			*head = (*head) -> next;
		}
		if((*head) -> next == NULL)
			(*head) -> next = tempnode;
		else{
			struct node *temp = (*head) -> next;
			(*head) -> next = tempnode;
			tempnode -> next = temp;
			return 1;
		}
	}
}

int main(){
	struct node *head = NULL;
	
	while(1){
		int choice, value, result, position;

		printf("\n1.Insertion at end\n2.Insertion at front\n3.Insertion at a specific location\n4.Traversal\n5.Exit\nEnter : ");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 1: 
			printf("\nEnter value : ");
			scanf("%d",&value);
			if(result = insertion(&head, value, 0))
				printf("\nSuccess");
			break;

			case 2:
			printf("\nEnter value : ");
			scanf("%d",&value);
			if(result = insertion(&head, value, -1))
				printf("\nSuccess");
			break;

			case 3:
			printf("\nEnter value : ");
			scanf("%d",&value);
			printf("\nEnter position : ");
			scanf("%d",&position);
			if(result = insertion(&head, value, position))
				printf("\nSuccess");
			break;
			
			case 4:
			display(head);
			break;

			case 5:
			return -1;
			break;
		}
	}

	//releasing the resources
	free(head);
	return 0;
}
