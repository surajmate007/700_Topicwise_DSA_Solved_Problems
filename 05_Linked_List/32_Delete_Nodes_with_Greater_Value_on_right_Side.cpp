// we solved this problem recursively. It is very intuitive algorithm.

class Solution{
    public:
    Node *compute(Node *head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        Node* retHead = compute(head->next);
        
        if(retHead->data > head->data){
            head = retHead;
            return head;
        }
        
        head->next = retHead;
        return head;
    }
    
};
