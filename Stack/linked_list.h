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