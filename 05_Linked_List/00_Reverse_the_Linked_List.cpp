// self written code.

class Solution{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head){
        if(head->next == NULL){
            return head;
        }
        
        Node* temp1 = head->next;
        Node* temp2 = temp1->next;
        head->next = NULL;
        while(temp2 != NULL){
            temp1->next = head;
            head = temp1;
            temp1 = temp2;
            temp2 = temp1->next;
        }
        temp1->next = head;
        head = temp1;
        return head;
    }
    
};


// Better use of pointers.

class Solution{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head){
        Node* prev = NULL; Node* current = head; Node* next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
        return head;
    }
    
};
