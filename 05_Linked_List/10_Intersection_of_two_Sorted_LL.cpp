// using 2 pointer approach solved by me.
// Since it is sorted.

Node* findIntersection(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* start = new Node(0);
    Node* point = start;
    
    while(temp1 != NULL and temp2 != NULL){
        if(temp1->data == temp2->data){
            Node* nd = new Node(temp1->data);
            start->next = nd;
            start = nd;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data){
            temp1 = temp1->next;
        }
        else{
            temp2 = temp2->next;
        }
    }
    start->next = NULL;
    return point->next;
}

// Some optimisation with use of less pointers.

Node* findIntersection(Node* head1, Node* head2){
    Node* temp1 = head1;
    Node* temp2 = head2;
    Node* head = NULL;
    Node* point = NULL;
    
    while(temp1 != NULL and temp2 != NULL){
        if(temp1->data == temp2->data){
            Node* nd = new Node(temp1->data);
            if(point != NULL){
                point->next = nd;
            }
            if(head == NULL){
                head = nd;
            }
            point = nd;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else if(temp1->data < temp2->data){
            temp1 = temp1->next;
        }
        else{
            temp2 = temp2->next;
        }
    }
    point->next = NULL;
    return head;
}
