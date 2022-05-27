// here we are simply traversing over the list with 2 pointers temp and prev.
// then at last setting temp->next = head and prev->next = NULL
// The setting head = temp.


void moveNode(Node* &head){
		if(head->next == NULL or head == NULL){
			return;
		}
		Node* prev;
		Node* temp = head;
		while(temp->next != NULL){
			prev = temp;
			temp = temp->next;
		}
		temp->next = head;
		prev->next = NULL;
		head = temp;
	}


