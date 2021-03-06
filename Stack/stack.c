#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

int is_empty(struct node* head){
	if (head != NULL) return 1; return -1;
}

int is_full(int count, int limit){
	if (count != limit) return 1; else return -1;
}

int push(struct node** head, int key){
	if (insertion(head, key, 0)) return 1; else return -1;
}

int pop(struct node** head){
	if (deletion(head, 0)) return 1; else return -1;
}

int main(){

	struct node* head = NULL;
	int count, choice, value, size;
	count = choice = value = 0;

	printf("\nEnter the size of the stack : ");
	scanf("%d", &size);

	while(1){

		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter : ");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 1	:
			if (is_full(count, size) == 1){
				printf("\nEnter value : ");
				scanf("%d", &value);				
				push(&head, value) ? printf("\nSuccess\nLIMIT : %d, CURRENT : %d", size, ++count) : printf("\nFailed");	
			}
			else
				printf("\nLimit reached");
			break;
			
			case 2	:
			if (is_empty(head) == 1)
				pop(&head) ? printf("\nSuccess\nLIMIT : %d, CURRENT : %d", size, --count) : printf("\nFailed");
			else
				printf("\nAlready empty");
			break;
			
			case 3	:
			head ? display(head) : printf("\nEmpty");;
			break;			
			
			case 4	:
			//releasing the resources
			free(head);			
			return -1;
			break;

			default	:
			printf("\nPlease enter right choice ");
			break;		
		}

	}
}