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



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
void removeDuplicates(Node* head)
{
    /* Pointer to store the pointer of a node to be deleted*/
    Node* to_free;

    /* do nothing if the list is empty */
    if (head == NULL)
        return;

    /* Traverse the list till last node */
    if (head->next != NULL)
    {

        /* Compare head node with next node */
        if (head->data == head->next->data)
        {
            /* The sequence of steps is important.
              to_free pointer stores the next of head
             pointer which is to be deleted.*/
            to_free = head->next;
            head->next = head->next->next;
            free(to_free);
            removeDuplicates(head);
        }
        else /* This is tricky: only
        advance if no deletion */
        {
            removeDuplicates(head->next);
        }
    }
}
