// The approach is simple;
// we will first find the mid of the list.
// Then we will reverse the second half section of the LL.
// Then starting one pointer from head and other pointer from mid we will keep on checking the the value of elements are matching or not.

// TC = O(n)
// SC = O(1) 


class Solution{
  public:
    Node* reverse(Node* head){
        if(head->next == NULL){
            return head;
        }
        
        Node* prev = NULL; Node* next = NULL; Node* curr = head;
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    //Function to check whether the list is palindrome.
    bool isPalindrome(Node *head){
        if(head->next == NULL){
            return true;
        }
        
        Node* slow = head; Node* fast = head->next;
        while(slow and fast and fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        Node* prev = reverse(slow->next);
        slow->next = prev;
        slow = slow->next;
        Node* dummy = head;
        while(slow != NULL){
            if(slow->data == dummy->data){
                slow = slow->next;
                dummy = dummy->next;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
