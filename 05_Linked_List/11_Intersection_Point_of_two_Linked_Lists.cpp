// We are first calculating the length of both the linked lists and then finding the difference in lenght.
// Then we will move the head pointer of longer LL such that the remaining lenghts of bith the lists will become same.
// Then we will start both the pointers until they meet each other and the first meeting point will be the point of intersection.

int intersectPoint(Node* head1, Node* head2){
    Node* temp1 = head1; Node* temp2 = head2;
    int len1 = 1, len2 = 1;
    while(temp1 != NULL){
        temp1 = temp1->next;
        len1++;
    }
    while(temp2 != NULL){
        temp2 = temp2->next;
        len2++;
    }
    
    temp1 = head1; temp2 = head2;
    if(len1 < len2){
        while(len1 != len2){
            temp2 = temp2->next;
            len2--;
        }
    }
    else{
        while(len1 != len2){
            temp1 = temp1->next;
            len1--;
        }
    }
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1->data;
}



// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using hashing
    TC: O(max(m, n))    // size of linklist
    SC: O(N)
*/
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    unordered_set<Node*> s;
    while (head1) {
        s.insert(head1);
        head1 = head1->next;
    }
    while (head2) {
        if (s.find(head2) != s.end()) {
            return head2->data;
        }
        head2 = head2->next;
    }
    return NULL;
}



// This solution will also work but giving TLE.
// This solution will work when it is confirmed that the linked list will have intersection. 

//Function to find intersection point in Y shaped Linked Lists.
int intersectPoint(Node* head1, Node* head2){
    Node* temp1 = head1; Node* temp2 = head2;
    while(temp1 != temp2){
        temp1 = temp1->next;
        temp2 = temp2->next;
        if(temp1 == NULL){
            temp1 = head1;
        }
        if(temp2 == NULL){
            temp2 = head2;
        }
    }
    return temp1->data;
}

// Old solution submitted on letcode.

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* l1 = headA;
        ListNode* l2 = headB;
        if(l1 == NULL or l2 == NULL){
            return NULL;
        }
        while(l1 != l2){
            if(l1 == NULL){
                L1 = headB;
            }
            else{
                l1 = l1 ->next;
            }
            if(l2 == NULL){
                l2 = headA;
            }
            else{
                l2 = l2->next;
            }
        }
        return l1;
    }
};
