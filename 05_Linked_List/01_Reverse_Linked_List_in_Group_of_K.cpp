// This is simple approach for this problem but not useful and scalable.

class Solution{
    public:
    struct node *reverse (struct node *head, int k){ 
        node* temp1 = head; node* temp2 = head;
        stack<int> st;
        while(temp1 != NULL){
            st.push(temp1->data);
            temp1 = temp1->next;
            if(st.size() == k or temp1 == NULL){
                while(!st.empty()){
                    temp2->data = st.top();
                    st.pop();
                    temp2 = temp2->next;
                }
            }
        }
        return head;
    }
};


// Here instead of storing only values we are actually storing pointers inside the stack:

class Solution{
    public:
    struct node *reverse (struct node *head, int k){ 
        node* temp1 = head;
        node* prev = new node(0);
        node* start = prev;
        stack<node*> st;
        while(temp1 != NULL){
            st.push(temp1);
            temp1 = temp1->next;
            if(st.size() == k or temp1 == NULL){
                node* curr = st.top(); node* nxt; prev->next = curr;
                while(!st.empty()){
                    st.pop();
                    if(!st.empty()){
                        nxt = st.top();
                        curr->next = nxt;
                        curr = nxt;
                    }
                }
                prev = curr;
            }
        }
        prev->next = NULL;
        return start->next;
    }
};


// Recursive code from reference github profile
// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Time Complexity: O(n).
        Traversal of list is done only once and it has ‘n’ elements.
    Auxiliary Space: O(n/k).
        For each Linked List of size n, n/k or (n/k)+1 calls will be made during the recursion.
*/
struct node* reverse(struct node* head, int k)
{
    if (!head) return NULL;

    int count = 0;
    node* curr = head;
    node* prev = NULL;
    node* next = NULL;

    while (count < k && curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) head->next = reverse(next, k);

    return prev;
}




