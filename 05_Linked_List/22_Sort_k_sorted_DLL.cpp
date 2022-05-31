// Naive Approach: Sort the given doubly linked list using the insertion sort technique. While inserting each element in the sorted part of the list,
// there will be at most k swaps to place the element to its correct position since it is at most k steps away from its correct position.
// Time Complexity: O(n*k)
// Auxiliary Space: O(1)


// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL(struct Node* head, int k){
    if(head == NULL || head->next == NULL)
        return head;
  
    // perform on all the nodes in list
    for(Node *i = head->next; i != NULL; i = i->next) {
        Node *j = i;
          // There will be atmost k swaps for each element in the list
        // since each node is k steps away from its correct position
        while(j->prev != NULL && j->data < j->prev->data) {
              // swap j and j.prev node
            Node* temp = j->prev->prev;
            Node* temp2 = j->prev;
            Node *temp3 = j->next;
            j->prev->next = temp3;
            j->prev->prev = j;
            j->prev = temp;
            j->next = temp2;
            if(temp != NULL)
                temp->next = j;
            if(temp3 != NULL)
                temp3->prev = temp2;
        }
          // if j is now the new head
       // then reset head
        if(j->prev == NULL)
            head = j;
    }
    return head;
}
 


// Efficient Approach: We can sort the list using the MIN HEAP data structure. The approach has been explained in Sort a nearly sorted
// (or K sorted) array. We only have to be careful while traversing the input doubly linked list and adjusting the required next and previous
// links in the final sorted list.

// Time Complexity: O(n*log k)
// Auxiliary Space: O(k)

// function to sort a k sorted doubly linked list
struct Node* sortAKSortedDLL(struct Node* head, int k){
    // if list is empty
    if (head == NULL)
        return head;
 
    // priority_queue 'pq' implemented as min heap with the
    // help of 'compare' function
    priority_queue<Node*, vector<Node*>, greater<Node*> > pq;
 
    struct Node* newHead = NULL, *last;
 
    // Create a Min Heap of first (k+1) elements from
    // input doubly linked list
    for (int i = 0; head != NULL && i <= k; i++) {
        // push the node on to 'pq'
        pq.push(head);
 
        // move to the next node
        head = head->next;
    }
 
    // loop till there are elements in 'pq'
    while (!pq.empty()) {
 
        // place root or top of 'pq' at the end of the
        // result sorted list so far having the first node
        // pointed to by 'newHead'
        // and adjust the required links
        if (newHead == NULL) {
            newHead = pq.top();
            newHead->prev = NULL;
 
            // 'last' points to the last node
            // of the result sorted list so far
            last = newHead;
        }
 
        else {
            last->next = pq.top();
            pq.top()->prev = last;
            last = pq.top();
        }
 
        // remove element from 'pq'
        pq.pop();
 
        // if there are more nodes left in the input list
        if (head != NULL) {
            // push the node on to 'pq'
            pq.push(head);
 
            // move to the next node
            head = head->next;
        }
    }
  
    // making 'next' of last node point to NULL
    last->next = NULL;
 
    // new head of the required sorted DLL
    return newHead;
}
 
