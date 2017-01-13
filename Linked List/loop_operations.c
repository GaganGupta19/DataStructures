#include<stdio.h>
#include<stdlib.h>
#include "linked_list.h"

int detect_loop(struct node* head){
	struct node *slow, *fast;
	slow = fast = head;
	int i = 0;
	while(slow != fast){
		if(i == 0){
			fast = fast -> next;
			i = 1;
		}
		else if(i == 1){
			slow = slow -> next;
			fast = fast -> next;
			i = 0;
		}
	} 
	return 1;
}

void find_starting_point_of_loop(struct node* head){
	struct node *slow, *fast;
	slow = fast = head;
	int i = 0;
	while(slow && fast && fast->next){
		slow = slow -> next;
		fast = fast -> next -> next;
		if(slow == fast){
			i = 1;
			break;
		}
	}
	if(i){
		slow = head;
		while(slow != fast){
			fast = fast -> next;
			slow = slow -> next;
		}

	}
	printf("\nloop started at : %d\n", slow->key);
}

int main(){
	struct node* head;
	head = createnode(1);
	head -> next = createnode(2);
	head -> next -> next = createnode(3);
	head -> next -> next -> next = createnode(4);
	struct node *junction = head -> next -> next -> next;
	head -> next -> next -> next -> next = createnode(5);
	head -> next -> next -> next -> next -> next = createnode(6);
	head -> next -> next -> next -> next -> next -> next = createnode(7);
	//created loop
	head -> next -> next -> next -> next -> next -> next -> next = junction;
	//display(head);
	detect_loop(head) == 1 ? printf("\nIt contains a loop") : printf("\nIt doesn't contains a loop");	
	//finding start of loop
	find_starting_point_of_loop(head);
	//releasing memory
	free(head);
}
