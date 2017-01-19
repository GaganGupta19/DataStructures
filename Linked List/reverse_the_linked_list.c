#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

struct node* reverse_list(struct node* head){
	struct node *temp, *next_node;
	temp = NULL;
	while(head){
		next_node = head -> next;
		head -> next = temp;
		temp = head;
		head = next_node;
	}
	return temp;	
}

int main(){

	struct node *head = NULL;
	head = createnode(1);
	head -> next = createnode(2);
	head -> next -> next = createnode(3);
	head -> next -> next -> next = createnode(4);
	head -> next -> next -> next -> next = createnode(5);
	printf("Before\n");
	display(head);	
	printf("\nAfter\n");
	display(reverse_list(head));
	free(head);
	return 0;
}