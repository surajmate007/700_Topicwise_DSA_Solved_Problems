// Here instead of directly going for adding the nu,ber to the list.
// we will first reverse the list and add the number from front of the list.
// If aftercomplete addition carry remains then we will create new node to store that number.
// Then after complete addition we will reverse the list again.


class Solution{
    public:
    
    Node* reverseList(Node* head){
        Node* prev = NULL; Node* next = NULL; Node* curr = head;
        while(curr != NULL){\
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node* addOne(Node *head){
        Node* prev = reverseList(head);
        Node* temp = prev;
        Node* ptr;
        int c = 1;
        while(temp != NULL){
            int sum = temp->data + c;
            c = sum/10;
            temp->data = sum%10;
            ptr = temp;
            temp = temp->next;
        }
        if(c){
            Node* start = new Node(c);
            ptr->next = start;
        }
        
        head = reverseList(prev);
        return head;
    }
};


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
*/
int addWithCarry(Node* head){
    // If linked list is empty, then
    // return carry
    if (head == NULL)
        return 1;

    // Add carry returned be next node call
    int res = head->data + addWithCarry(head->next);

    // Update data and return new carry
    head->data = (res) % 10;
    return (res) / 10;
}

