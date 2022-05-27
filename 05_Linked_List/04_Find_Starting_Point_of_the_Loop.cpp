// we are using the same fast and slow pointer method.

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL or head->next == NULL){
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* dummy = head;
        while(fast->next != NULL and fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                while(dummy != slow){
                    slow = slow->next;
                    dummy = dummy->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};


// More easy solution using unordered_map:

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;
        ListNode* temp = head;
        while(temp != NULL){
            if(mp.find(temp) != mp.end()){
                return temp;
            }
            mp[temp]++;
            temp = temp->next;
        }
        return NULL;
    }
};



