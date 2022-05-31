// The approach is simple we will first find the kth node from where we have to break the list and also we will keep one pointer at last node
// to join this broken list to the last node.

class Solution {
public:
    Node *rotateDLL(Node *head,int p){
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        Node* temp1 = head; Node* temp2 = head; Node* temp3;
        int i=1;
        while(i != p){
            temp2 = temp2->next;
            i++;
        }
        while(temp1->next != NULL){
            temp1 = temp1->next;
        }
        temp3 = temp2->next;
        temp1->next = head;
        head->prev = temp1;
        temp2->next = NULL;
        temp3->prev = NULL;
        head = temp3;
        
        return head;
    }
};
