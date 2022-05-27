// simple approach
// just check if the value of next node is same or not.
// if it is same then update the next of that node.

void removeDuplicates(struct Node* head){
    struct Node* temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }
}
