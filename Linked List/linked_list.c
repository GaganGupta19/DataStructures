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
	while(head){
		printf("%d\n", head -> key);
		head = head -> next;
	}
}

//for insertion at the end
int insertion(struct node** head, int key, int position){
	struct node *tempnode = createnode(key);
	//for initial node
	if(!(*head)){
		(*head) = tempnode;
		return 1;
	}
	//insertion at head
	else if(position == 0){
		tempnode -> next = *head;
		(*head) = tempnode;
		return 1;
	}
	//insertion at end
	else if(position == -1){
		struct node *temp = *head;
		while(temp -> next)
			temp = temp -> next;
		temp -> next = tempnode;
		return 1;
	}
	//insertion in between
	else{
		int count = 1;
		struct node *prev, *temp;
		temp = *head;
		while((temp -> next) && count < position){
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
int deletion(struct node** head, int position){

	if(!(*head))
		return -1;
	//deletion from head
	else if(position == 0){
		struct node* temp = (*head);
		(*head) = (*head) -> next;
		temp -> next = NULL;
		free(temp);
		return 1;
	}
	//deletion from end
	else if(position == -1){
		struct node* temp = (*head), *prev;
		while(temp -> next){
			prev = temp;
			temp = temp -> next;
		}
		prev -> next = NULL;
		free(temp);
		return 1;
	}
	//deletion in between
	else{
		struct node* temp = (*head), *prev;
		int count = 1;
		while((temp -> next) && count < position){
			count++;
			prev = temp;
			temp = temp -> next;
		}
		prev -> next = temp -> next;
		temp -> next = NULL;
		free(temp);
		return 1;
	}
}

//search function
int search(struct node* temp, int key){
	struct node* head = temp;
	if(!head)
		return -1;

	int count = 1;
	while((head)){
		if(head -> key == key)
			return count;
		head = head -> next;
		count++;
	}
		
	return -1;
}

//middle element
void find_mid(struct node* head){
	struct node *slow, *fast;
	slow = fast = head;
	int count = 1, i = 0;
	while(fast->next){
		if(i == 0){
			fast = fast -> next;
			i = 1;
		}
		else if(i == 1){
			slow = slow -> next;
			fast = fast -> next;
			i = 0;
			count++;
		}
	} 
	printf("\n%d found at position %d", slow->key, count);
}

int main(){
	int choice, value, result, position;
	struct node *head = NULL;

	while(1){

		printf("\n1.Insertion at front\n2.Insertion at end\n3.Insertion at a specific location\n4.Deletion from end\n5.Deletion from front\n6.Deletion from between\n7.Searching\n8.Find middle element\n9.Display\n10.Exit\nEnter : ");
		scanf("%d", &choice);

		switch(choice){

			case 1: 
			printf("\nEnter value : ");
			scanf("%d",&value);
			insertion(&head, value, 0) == 1 ? printf("\nSuccess") : printf("\nFailed");
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
			deletion(&head, -1) == 1 ? printf("\nSuccess" ) : printf("\nFailed" );
			break;

			case 5:
			deletion(&head, 0) == 1 ? printf("\nSuccess" ) : printf("\nFailed" );
			break;

			case 6:
			printf("\nEnter position : ");
			scanf("%d",&position);
			deletion(&head, position) == 1 ? printf("\nSuccess" ) : printf("\nFailed" );
			break;

			case 7:
			printf("\nEnter value : ");
			scanf("%d",&value);
			int position = search(head, value);
			position > 0 ? printf("\nFound at index : %d", position) : printf("\nFailed" );
			break;

			case 8:
			find_mid(head);
			break;

			case 9:
			display(head);
			break;

			case 10:
			//releasing the resources
			free(head);
			return -1;
			break;

			default:
			printf("\nEnter your choice again!");
			break;
		}
	}
	return 0;
}