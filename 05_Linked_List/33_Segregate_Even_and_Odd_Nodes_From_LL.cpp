// the approach is simple first create seperate lists of odd and even numbers and then merge odd list at the end of even list.

class Solution{
public:
    Node* divide(int N, Node *head){
        if(head == NULL or head->next == NULL){
            return head;
        }
        
        Node* even = new Node(0); Node* e = even;
        Node* odd = new Node(0); Node* o = odd;
        Node* temp = head;
        
        while(temp != NULL){
            if((temp->data)%2 == 0){
                e->next = temp;
                e = e->next;
            }
            else{
                o->next = temp;
                o = o->next;
            }
            temp = temp->next;
        }
        o->next = NULL;
        e->next = NULL;
        
        if(odd->next and even->next){
            e->next = odd->next;
        }
        else if(!even->next){
            return odd->next;
        }
        
        return even->next;
    }
};
