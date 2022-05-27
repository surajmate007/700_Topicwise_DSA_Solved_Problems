// using modified slow and fast pointer approach:

class Solution{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head){
        Node* slow = head; Node* prev;
        Node* fast = head;
        while(slow and fast and fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                break;
            }
        }
        
        if(slow and fast and fast->next){
            fast = head; 
            while(slow != fast){
                prev = slow;
                slow = slow->next;
                fast = fast->next;
            }
            prev->next = NULL;
        }
    }
};
