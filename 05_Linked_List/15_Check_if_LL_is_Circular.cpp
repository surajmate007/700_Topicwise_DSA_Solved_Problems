// we are simply using slow and fast pointer approach.

bool isCircular(Node *head){
    if(head->next == NULL or head == NULL){
        return false;
    }
    
    Node* slow = head; Node* fast = head;
    do{
        slow = slow->next;
        fast = fast->next->next;
        if(fast == NULL or fast->next == NULL){
            return false;
        }
        
    }while(slow != fast);
    
    return true;
}
