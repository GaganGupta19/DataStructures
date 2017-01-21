#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

// Let the list be 1-2-3-4-5-6-7-8-9-10-11

int main(){

	struct node *head;
	
	head = createnode(1);
	head -> next = createnode(2);
	head -> next -> next = createnode(3);
	head -> next -> next -> next = createnode(4);
	head -> next -> next -> next -> next = createnode(5);
	head -> next -> next -> next -> next -> next = createnode(6);
	head -> next -> next -> next -> next -> next -> next = createnode(7); 
	head -> next -> next -> next -> next -> next -> next -> next = createnode(8);
	head -> next -> next -> next -> next -> next -> next -> next -> next = createnode(9);
	head -> next -> next -> next -> next -> next -> next -> next -> next -> next = createnode(10);
	return 0;	
}

