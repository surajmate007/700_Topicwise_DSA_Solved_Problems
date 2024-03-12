// this solution can tell us how to remove all subarrays from an array with sum 0.

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode node = ListNode(0, head);
        ListNode* temp = &node;
        int sum = 0;
        unordered_map<int, ListNode*> mp;

        while(temp){
            sum += temp->val;
            mp[sum] = temp;
            temp = temp->next;
        }

        sum = 0; temp = &node;
        while(temp){
            sum += temp->val;
            temp->next = mp[sum]->next;
            temp = temp->next;
        }

        return node.next;
    }
};
