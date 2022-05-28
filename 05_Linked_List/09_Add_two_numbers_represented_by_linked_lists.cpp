// This solution is written by me.
// In problem it was saying touse some extra space for the new final LL. 
// But i managesd to form the solution LL in the first gIven LL.

// The solution approach is simple we are first reversing both the lists na then adding the corresponding nodes.
// We are adding until one of the list gets over.
// After adding the nodes we will then add the remaining nodes form one of the lists.
// If the carry is still remaining we will add it by crating extra node nad link these extra nodes with our current list.


class Solution{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* reverseList(Node* head){
        Node* prev = NULL; Node* next = NULL; Node* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    struct Node* addTwoLists(struct Node* first, struct Node* second){
        Node* prev1 = reverseList(first); Node* lag1; Node* lag2;
        Node* prev2 = reverseList(second); int c = 0;
        Node* start = prev1;
        while(prev1 != NULL and prev2 != NULL){
            int sum = prev1->data + prev2->data + c;
            prev1->data = sum%10;
            c = sum/10;
            lag1 = prev1; lag2 = prev2;
            prev1 = prev1->next; prev2 = prev2->next;
        }
        
        while(prev1 != NULL){                 // To add remaining prev1 nodes. We dint need to create new nodes here as we are transforming LL1 into ans.
            int sum = prev1->data + c;
            prev1->data = sum%10;
            c = sum/10;
            lag1 = prev1;
            prev1 = prev1->next;
        }
        
        while(prev2 != NULL){                 // we need to create extra nodes here.
            int sum = prev2->data + c;
            Node* nd = new Node(sum%10);
            c = sum/10;
            lag1->next = nd;
            lag1 = nd;
            prev2 = prev2->next;
        }
        if(c != 0){                           // we need to create extra nodes here.
            Node* nd = new Node(c);
            lag1->next = nd;
            lag1 = nd;
        }
        lag1->next = NULL;
        
        Node* head = reverseList(start);
        return head;
    }
};
