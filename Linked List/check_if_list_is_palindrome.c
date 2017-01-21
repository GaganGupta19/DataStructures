#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

/*
1. find the middle element
2. reverse the second part
3. compare the first and second part of the list
*/
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


int check_for_palindrome(struct node* head){
	struct node* temp, *fast, *slow, *middle;
	temp = fast = slow = head;
	//finding middle element
	while(fast && fast -> next){
		slow = slow -> next;
		fast = fast -> next -> next;
	}
	struct node* limit = slow;
	middle = reverse_list(slow);
	while(temp != limit && middle -> next){
		if(temp -> key != middle -> key)
			return -1;
		temp = temp -> next;
		middle = middle -> next;	
	}
	return 1;
}

int main(){

	struct node* first, *second;
	first = second = NULL;

	//creating a palindrome using nodes
	//first list
	first = createnode(1);
	first -> next = createnode(2);
	first -> next -> next = createnode(3);
	first -> next -> next -> next = createnode(2);
	first -> next -> next -> next -> next = createnode(1);
	display(first);
	check_for_palindrome(first) == 1 ? printf("\nYes! it's a palindrome\n") : printf("\nIt's not a palindrome");
	
	//second list
	second = createnode(8);
	second -> next = createnode(2);
	second -> next -> next = createnode(3);
	second -> next -> next -> next = createnode(2);
	second -> next -> next -> next -> next = createnode(5);
	display(second);
	check_for_palindrome(second) == 1 ? printf("\nYes! it's a palindrome\n") : printf("\nIt's not a palindrome\n");
	
	//releasing resources
	free(first);
	free(second);
	return 0;
}