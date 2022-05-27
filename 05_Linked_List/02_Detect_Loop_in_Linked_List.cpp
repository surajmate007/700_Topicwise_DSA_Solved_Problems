// ----------------------------------------------------------------------------------------------------------------------- //
/*
    Floyd’s Cycle-Finding Algorithm
    This is the fastest method
    1. Traverse linked list using two pointers.
    2. Move one pointer(slow_p) by one and another pointer(fast_p) by two.
    3. If these pointers meet at the same node then there is a loop. If pointers do not meet then linked list doesn’t have a loop.
    TC: O(N)
    SC: O(1)
*/
 
int detectLoop(Node* list)
{
    Node* slow_p = list, * fast_p = list;

    while (slow_p && fast_p && fast_p->next) {
        slow_p = slow_p->next;
        fast_p = fast_p->next->next;
        if (slow_p == fast_p) {
            return 1;
        }
    }
    return 0;
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(N)
    SC: O(N)
*/
class Solution{
    public:
    //Function to check if the linked list has a loop.
    bool detectLoop(Node* head){
        unordered_map<Node*, int> mp;
        Node* temp = head;
        while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                return true;
            }
            mp[temp]++;
            temp = temp->next;
        }
        return false;
    }
};



 
// ----------------------------------------------------------------------------------------------------------------------- //
/*
    altering the value
    as all data are positive, alter their sign
    hence if we get any data negative, loop is detected
    TC: O(N)
    SC: O(1)
*/
bool detectLoop(Node* head)
{
    while (head != NULL) {
        if (head->data < 0) return true;
        head->data = -(head->data);
        head = head->next;
    }
    return false;
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using flag
    struct Node {
        int data;
        struct Node* next;
        int flag;                   // add flag
    };
*/
bool detectLoop(struct Node* h)
{
    while (h != NULL) {
        // If this node is already traverse
        // it means there is a cycle
        // (Because you we encountering the
        // node for the second time).
        if (h->flag == 1)
            return true;

        // If we are seeing the node for
        // the first time, mark its flag as 1
        h->flag = 1;

        h = h->next;
    }

    return false;
}

