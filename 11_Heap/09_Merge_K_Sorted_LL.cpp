struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/ 

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
