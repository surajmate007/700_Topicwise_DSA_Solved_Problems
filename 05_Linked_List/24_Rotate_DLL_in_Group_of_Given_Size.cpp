// Easy, exactly same approach of singly linked list is used.

Node* reverseDLLInGroups(Node* head, int k){
    if(head == NULL or head->next == NULL){
        return head;
    }
    
    stack<Node*> st; Node* start = new Node(0); start->prev = NULL;
    Node* temp = head; Node* pre = start;
    while(temp != NULL){
        st.push(temp);
        temp = temp->next;
        if(st.size() == k or temp == NULL){
            Node* curr = st.top();
            curr->prev = pre; pre->next = curr; 
            Node* nxt = NULL;
            while(!st.empty()){
                st.pop();
                if(!st.empty()){
                    nxt = st.top();
                    curr->next = nxt;
                    nxt->prev = curr;
                    curr = nxt;
                }
            }
            pre = curr;
        }
    }
    pre->next = NULL;
    head = start->next;
    head->prev = NULL;
    start->next = NULL;
    free(start);
    return head;
}

