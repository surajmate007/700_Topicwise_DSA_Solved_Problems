// Here the approah is simple.
// everytime we are merging two linked lists and and thus reducing the number of lists into half.
// lists on 2 opposite ends are merged first and then pointers keep on going towards centre until they dont collide.
// Such merging is kept on going until we are remained with only one list at the end.

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergeLL(Node* l1 , Node* l2){
     if(l1 == NULL){
         return l2;
     }
     if(l2 == NULL){
         return l1;
     }
     Node* head = NULL;
     if(l1->data <= l2->data){
         head = l1;
         head->next = mergeLL(l1->next , l2);
     }else{
         head = l2;
         head->next = mergeLL(l1 , l2->next);
     }
     return head;
 }
 
   //Function to merge K sorted linked list.
   Node * mergeKLists(Node *arr[], int K){
         int si = 0;
         int ei = K-1;
         int i;
         
         while(ei != 0){
             si = 0;
             i = ei;
             while(si < i){
                 arr[si] = mergeLL(arr[si] , arr[i]);
                 si++;
                 i--;
             }
             ei = i;   // reinitialization of end index
         }
         return arr[0];
   }
};



// using the merge sort approach:


class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* mergesort(Node* L1, Node* L2){
        
        Node* res = new Node(0);
        Node* temp = res;
        Node* ptr1 = L1;
        Node* ptr2 = L2;
        
        if(ptr1 == NULL){
            return ptr2;
        }
        
        if(ptr2 == NULL){
            return ptr1;
        }
        
        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1->data <= ptr2->data){
                temp->next = ptr1;
                ptr1 = ptr1->next;
                temp = temp->next;
            }
            else {
                temp->next = ptr2;
                ptr2 = ptr2->next;
                temp = temp->next;
            }
        }
        
        while(ptr1 != NULL){
            temp->next = ptr1;
            ptr1 = ptr1->next;
            temp = temp->next;
        }
        
        while(ptr2 != NULL){
            temp->next = ptr2;
            ptr2 = ptr2->next;
            temp = temp->next;
        }
    
        return res->next;
    }
    
    Node* divide(Node* arr[], int start, int end){
        if(start > end){
            return NULL;
        }
        if(start == end){
            return arr[start];
        }
        
        int mid = start + (end - start)/2; //(start + end) /2;
        
        Node* L1 = divide(arr, start, mid);
        Node* L2 = divide(arr, mid + 1, end);
       
       return mergesort(L1,L2);
        
    }

    Node* mergeKLists(Node* arr[], int K){
        if(K == 0){
            return NULL;
        }
        
        return divide(arr,0,K-1);
    }
};
