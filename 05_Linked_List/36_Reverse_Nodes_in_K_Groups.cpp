// simple solution approach :
// problem link : https://www.codingninjas.com/codestudio/problems/763406?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

Node *getListAfterReverseOperation(Node *head, int n, int b[]){
    Node* temp = head;
    Node* nd = new Node(0); Node* ptr = nd;
    
    for(int i=0; i<n; i++){
        int k = b[i];
        stack<Node*> st;
        while(temp != NULL and k--){
            st.push(temp);
            temp = temp->next;
        }
        
        while(!st.empty()){
            ptr->next = st.top();
            st.pop(); ptr = ptr->next;
        }
        
        if(temp == NULL){
            ptr->next = NULL;
            break;
        }
    }
    if(temp != NULL){
        ptr->next = temp;
    }
    
    return nd->next;
}
