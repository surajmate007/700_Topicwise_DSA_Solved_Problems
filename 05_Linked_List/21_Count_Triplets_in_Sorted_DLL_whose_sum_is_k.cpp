// we are using the same approach in arrays.
// we are first fixing one value and then using 2 pointer approach to get the remaining sum.

int countTriplets(DLLNode* head, int x){
    int count = 0;
    DLLNode* temp = head;
    DLLNode* end = head;
    while(end->next != NULL){
        end = end->next;
    }
    DLLNode* first; DLLNode* last;
    while(temp->next != NULL){
        first = temp->next;
        last = end;
        int dif = x - temp->data;
        while(first != last and first->prev != last and last->next != first){
            int sum = first->data + last->data;
            if(sum == dif){
                count++;
                first = first->next;
                last = last->prev;
            }
            else if(sum < dif){
                first = first->next;
            }
            else{
                last = last->prev;
            }
        }
        temp = temp->next;
    }
    
    return count;
}  
