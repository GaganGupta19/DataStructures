/*
Problem to solve

	1 -> 2 -> 3 -> 4 -> 5 -> 11 -> 6 -> 7 
							/
			8 -> 2 -> 3 -> 4 	

finding the intersecting node
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include "linked_list.h"


void traverse(int d, struct node **head){
	int i = 0;
	for(i = 0; i < d ;i++)
		*head = (*head) -> next;
}

int find_length(struct node *head){
	struct node *temp = head;
	int length = 0;
	while(temp){
		temp = temp -> next;
		length++;
	}
	return length;
}

int find_intersecting_node(struct node *first, struct node *second){
	int l_first = find_length(first);
	int l_second = find_length(second);
	
	int d = abs(l_first - l_second);
	l_first > l_second ? traverse(d, &first) : traverse(d, &second);

	while(first && second){
		if(first == second)
			return first -> key;
		first = first -> next;
		second = second -> next;
	}
	return -1;
}

int main(){

	struct node *first, *second, *intersecting_node;
	first = second = NULL;
	/* intersecting node */
	intersecting_node = createnode(11);
	/* creating two lists intersecting at a particular node and then becoming a SLL */

	/* first list */
	first = createnode(1);
	first -> next = createnode(2);
	first -> next -> next = createnode(3);
	first -> next -> next -> next = createnode(4);
	first -> next -> next -> next -> next = createnode(5);
	first -> next -> next -> next -> next -> next = intersecting_node;
	first -> next -> next -> next -> next -> next -> next = createnode(6); 
	first -> next -> next -> next -> next -> next -> next -> next = createnode(7);
	
	/* second list */
	second = createnode(8);
	second -> next = createnode(2);
	second -> next -> next = createnode(3);
	second -> next -> next -> next = createnode(4);
	second -> next -> next -> next -> next = intersecting_node;

	display(first);
	printf("\nsecond list\n");
	display(second);

	int intersection = find_intersecting_node(first, second);
	intersection != -1 ? printf("\nIntersection occurs at node : %d\n", intersection) : printf("\nFailed\n");  
	free(first);
	free(second);
	return 0;
}