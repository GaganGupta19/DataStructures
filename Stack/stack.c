#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"
#define LIMIT 5

int is_empty(struct node* head){
	head == NULL ? return 1 : return -1;
}

int is_full(int count){
	count == LIMIT ? return 1 : return -1;
}

int push(struct node** head, int key, int count){
	is_full(count) && insertion(head, key, 0) ? return 1 : return -1;
}

int pop(struct node** head){
	is_empty(count) && deletion(head, 0) ? return 1 : return -1;
}

int main(){

	struct node* head = NULL;
	int count,choice,value;
	count = choice = value;

	while(1){

		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\nEnter : ");
		scanf("%d", &choice);
		
		switch(choice){
			
			case 1	:
			printf("\nEnter value : ");
			scanf("%d", &value);
			push(&head, value, count) ? printf("\nSuccess\nLIMIT : %d, CURRENT : %d", LIMIT, count++) : printf("\nFailed");	
			break;
			
			case 2	:
			pop(&head) ? printf("\nSuccess") : printf("\nFailed");
			break;
			
			case 3	:
			display(head);
			break;			
			
			case 4	:
			return -1;
			break;

			default	:
			printf("\nPlease enter right choice ");
			break;		
		}

	}
}