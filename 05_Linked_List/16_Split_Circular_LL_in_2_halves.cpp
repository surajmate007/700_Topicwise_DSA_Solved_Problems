// we are first finding the last node of the circular list.
// then converting it into non circular LL by setting the next of last node ot NULL.
// After that we will find the mid node using slow and fast pointer approach.
// then set the pointers such that it will form 2 circular LLs.


void splitList(Node *head, Node **head1_ref, Node **head2_ref){
    if(head->next == head){
        *head1_ref = head;
        *head2_ref = head;
        return;
    }
    
    Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = NULL;
    Node* slow = head; Node* fast = head->next;
    while(slow and fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* head2 = slow->next;
    temp->next = head2;
    slow->next = head;
    *head1_ref = head;
    *head2_ref = head2;
}
