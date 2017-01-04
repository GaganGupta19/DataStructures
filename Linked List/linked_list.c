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
		(*head) = tempnode;
		return 5;
	}
	else if(position == 0){
		tempnode -> next = *head;
		(*head) = tempnode;
		return 1;
	}
	else if(position == -1){
		struct node *temp = *head;
		while(temp -> next != NULL)
			temp = temp -> next;
		temp -> next = tempnode;
		return 1;
	}
	else{
		int count = 1;
		struct node *prev, *temp;
		temp = *head;
		while(temp -> next != NULL && count < position){
			count++;
			prev = temp;
			temp = temp -> next;
		}

		tempnode -> next = temp;
		prev -> next = tempnode;
		return 1;
	}
	
}

// function for deletion of nodes
int delete(){

}

int main(){
	int choice, value, result, position;
	struct node *head = NULL, **head_ptr;
	head_ptr = &head;

	while(1){

		head = (*head_ptr);
		if (head != NULL)
			printf("\n First node : %d", head -> key );
		printf("\n1.Insertion at front\n2.Insertion at end\n3.Insertion at a specific location\n4.Deletion from end\n5.Deletion from front\n6.Deletion from between\n7.Traversal\n8.Exit\nEnter : ");
		scanf("%d", &choice);

		switch(choice){

			case 1: 
			printf("\nEnter value : ");
			scanf("%d",&value);
			insertion(&head, value, 0) == 5 ? printf("\nnull insertion") : printf("\nSuccess");
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
			break;

			case 5:
			break;

			case 6:
			break;


			case 7:
			display(head);
			break;

			case 8:
			return -1;
			break;

			default:
			printf("\nEnter your choice again!");
			break;
		}
	}

	//releasing the resources
	free(head);
	return 0;
}
