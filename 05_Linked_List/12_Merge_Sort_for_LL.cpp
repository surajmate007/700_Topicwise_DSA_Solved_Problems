// The implementation is very simple.

// If the size of the linked list is 1 then return the head
// Find mid using The Tortoise and The Hare Approach (slow pointer and fast pointer approach)
// Store the next of mid in head2 i.e. the right sub-linked list.
// Now Make the next midpoint null.
// Recursively call mergeSort() on both left and right sub-linked list and store the new head of the left and right linked list.
// Call merge() given the arguments new heads of left and right sub-linked lists and store the final head returned after merging.
// Return the final head of the merged linkedlist.


class Solution{
  public:
    
    Node* merge(Node* left, Node* right){
        Node* mid = new Node(0);
        Node* start = mid;
        while(left != NULL and right != NULL){
            if(left->data < right->data){
                mid->next = left;
                left = left->next;
            }
            else{
                mid->next = right;
                right = right->next;
            }
            mid = mid->next;
        }
        
        while(left != NULL){
            mid->next = left;
            left = left->next;
            mid = mid->next;
        }
        
        while(right != NULL){
            mid->next = right;
            right = right->next;
            mid = mid->next;
        }
        
        return start->next;
    }
    
    
    Node* findMid(Node* head){
       Node* slow = head; Node* fast = head->next;
       while(slow and fast and fast->next){
           slow = slow->next;
           fast = fast->next->next;
       }
       return slow;
    }
    

    Node* mergeSort(Node* head) {         // Main function to start
        if(head->next == NULL){
            return head;
        }
      
        Node* mid;
        Node* head2;
        mid = findMid(head);
        head2 = mid->next;
        mid->next = NULL;                 // to complete first LL by ending it with NULL.
        Node* left = mergeSort(head);
        Node* right = mergeSort(head2);
        Node* final = merge(left, right);
        
        return final;
    }
};
