// There are no changes with the normal reverse function.
// It is exactly same only extra care should be taken of prev pointer.


Node* reverseDLL(Node * head){
    Node* nxt = NULL;
    Node* curr = head;
    Node* pre = NULL;
    while(curr){
        nxt = curr->next;
        curr->next = pre;
        curr->prev = nxt;
        pre = curr;
        curr = nxt;
    }
    head = pre;
    return head;
}
