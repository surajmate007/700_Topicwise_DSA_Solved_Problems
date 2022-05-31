// This is the blend of 2 approaches on merges sort on linked list.
// This approach is easy and understandable.


Node* merge(Node* left, Node* right){
    Node* res = new Node(0);
    Node* ptr = res;
    Node* ptr1 = left; Node* ptr2 = right;
    
    if(ptr1 == NULL){
        return ptr2;
    }
    
    if(ptr2 == NULL){
        return ptr1;
    }
    
    while(ptr1 != NULL and ptr2 != NULL){
        if(ptr1->data <= ptr2->data){
            ptr->bottom = ptr1;
            ptr1 = ptr1->bottom;
        }
        else{
            ptr->bottom = ptr2;
            ptr2 = ptr2->bottom;
        }
        ptr = ptr->bottom;
    }
    
    while(ptr1 != NULL){
        ptr->bottom = ptr1;
        ptr1 = ptr1->bottom;
        ptr = ptr->bottom;
    }
    
    while(ptr2 != NULL){
        ptr->bottom = ptr2;
        ptr2 = ptr2->bottom;
        ptr = ptr->bottom;
    }
    
    return res->bottom;
}

Node* findMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;
    while(slow and fast and fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}


Node *flatten(Node *root){
    if(root->next == NULL){
        return root;
    }
    Node* head = root;
    Node* mid = findMid(root);
    Node* head2 = mid->next;
    mid->next = NULL;
    Node* left = flatten(head);
    Node* right = flatten(head2);
    Node* newHead = merge(left, right);
    
    return newHead;
}
