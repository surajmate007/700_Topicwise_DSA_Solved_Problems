// Just changing the node values and not the actual nodes

class Solution{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int cnt0=0, cnt1=0, cnt2=0;
        Node* temp = head;
        while(temp != NULL){
            if(temp->data == 0){
                cnt0++;
            }
            else if(temp->data == 1){
                cnt1++;
            }
            else{
                cnt2++;
            }
            
            temp = temp->next;
        }
        
        temp = head;
        
        while(temp != NULL){
            if(cnt0 > 0){
                temp->data = 0;
                cnt0--;
            }
            else if(cnt1 > 0){
                temp->data = 1;
                cnt1--;
            }
            else{
                temp->data = 2;
                cnt2--;
            }
            
            temp = temp->next;
        }
        
        return head;
    }
};



// Another good solution where we are first creating 3 diferent LLs for 0, 1 and 2 adn then joing them all in order.


class Solution{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        Node* zero = new Node(0); Node* zptr = zero;
        Node* one = new Node(0); Node* optr = one;
        Node* two = new Node(0); Node* tptr = two;
        
        Node* temp = head;
        
        while(temp != NULL){
            if(temp->data == 0){
                zptr->next = temp;
                zptr = zptr->next;
            }
            else if(temp->data == 1){
                optr->next = temp;
                optr = optr->next;
            }
            else{
                tptr->next = temp;
                tptr = tptr->next;
            }
            
            temp = temp->next;
        }

        zptr->next = (one->next) ? (one->next) : (two->next);
        optr->next = two->next;
        tptr->next = NULL;
        head = zero->next;
        
        delete zero;
        delete one;
        delete two;
        
        return head;
    }
};


