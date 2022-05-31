// This is the simple program to find the nth node from the end of the LL.

//Function to find the data of nth node from the end of a linked list.
int getNthFromLast(Node *head, int n){
    
    Node* temp = head; int cnt = 1;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    
    if(n >= cnt){
        return -1;
    }
    
    cnt = cnt-n-1;
    temp = head;
    while(cnt){
        temp = temp->next;
        cnt--;
    }
    return temp->data;
}


