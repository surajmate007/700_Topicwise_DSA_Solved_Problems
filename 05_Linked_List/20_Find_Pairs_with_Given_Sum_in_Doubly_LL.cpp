// This solution is also acceptable but the doubt is why I am not able to access last node by directly head->prev.
// Simple 2 pointer apprach used in sorted arrays.

bool findPair(Node* head, int k){
    if(head == NULL or head->next == NULL){
        return false;
    }
    
    Node* start = head;
    Node* end = head;
    while(end->next != NULL){
        end = end->next;
    }
     
    while(start != end){
        int sum = start->data + end->data;
        if(sum == k){
            return true;
        }
        else if(sum < k){
            start = start->next;
        }
        else{
            end = end->prev;
        }
    }
    return false;
}


