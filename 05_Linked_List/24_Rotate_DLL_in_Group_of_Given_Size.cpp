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




// Recursive approach:


// function to insert a node at the beginging
// of the Doubly Linked List
void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;

    // link the old list off the new node
    new_node->next = (*head_ref);

    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;

    // move the head to point to the new node
    (*head_ref) = new_node;
}

// function to reverse a doubly linked list
// in groups of given size
Node* revListInGroupOfGivenSize(Node* head, int k)
{
    Node* current = head;
    Node* next = NULL;
    Node* newHead = NULL;
    int count = 0;

    // reversing the current group of k
    // or less than k nodes by adding
    // them at the beginning of list
    // 'newHead'
    while (current != NULL && count < k)
    {
        next = current->next;
        push(&newHead, current);
        current = next;
        count++;
    }

    // if next group exists then making the desired
    // adjustments in the link
    if (next != NULL)
    {
        head->next = revListInGroupOfGivenSize(next, k);
        head->next->prev = head;
    }

    // pointer to the new head of the
    // reversed group
    return newHead;
}
