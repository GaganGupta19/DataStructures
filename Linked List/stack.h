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
