// we need to complete 2 functions
// deleteNode function helps to delete the intended node.
// reverse function helps to reverse the LL after deleting the node.

/* Function to delete a given node from the list */
void deleteNode(struct Node **head, int key){
    Node* temp = *head;
    while(temp->next->data != key){
        temp = temp->next;
    }
    Node* del = temp->next;
    temp->next = temp->next->next;
    delete del;
}

/* Function to reverse the linked list */
 void reverse(struct Node** head_ref){
    Node* curr = *head_ref; Node* prev = NULL; Node* next = NULL;
    while(curr->next != NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    curr->next = prev;
    *head_ref = prev; 
}
