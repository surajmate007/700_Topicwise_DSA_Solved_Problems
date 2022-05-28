// we are simply using the slow and fast pointer approach.

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
