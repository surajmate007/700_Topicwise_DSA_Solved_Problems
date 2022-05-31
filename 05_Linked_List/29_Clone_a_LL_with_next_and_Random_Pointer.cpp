// Expected time and space complexity for this problem is O(n) and O(1) resp.
// we have used unordered_map in this solution.


class Solution:
  public:
    Node *copyList(Node *head){
        Node* temp = head;
        unordered_map<Node*, Node*> mp;
        
        Node* dummy = new Node(0);
        Node* newHead = dummy;
        while(temp != NULL){
            Node* nd = new Node(temp->data);
            mp[temp] = nd;
            dummy->next = nd;
            dummy = dummy->next;
            temp = temp->next;
        }
        
        temp = head;
        while(temp != NULL){
            mp[temp]->arb = mp[temp->arb];
            temp = temp->next;
        }
        
        dummy = newHead;
        newHead = newHead->next;
        delete dummy;
        return newHead;
    }

};


// the approach is too simple we are creating the nodes in between the original nodes and then forming the random links according to the links of 
// original LL.

Node* makeDup(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* nd = new Node(temp->data);
            nd->next = temp->next;
            temp->next = nd;
            temp = nd->next;
        }
        
        return head;
    }
    
    Node* allotRand(Node* head){
        Node* temp = head;
        while(temp != NULL){
            if(temp->arb != NULL){
                temp->next->arb = temp->arb->next;
            }
            temp = temp->next->next;
        }
        return head;
    }
    
    Node* breakLinks(Node* head){
        Node* temp = head;
        Node* newHead = new Node(0);
        Node* dummy = newHead;
        
        while(temp != NULL){
            Node* nxt = temp->next->next;
            dummy->next = temp->next;
            dummy = dummy->next;
            temp->next = nxt;
            temp = nxt;
        }
        return newHead->next;
    }
    
    
    Node *copyList(Node *head){
        head = makeDup(head);
        head = allotRand(head);
        return breakLinks(head);
    }
