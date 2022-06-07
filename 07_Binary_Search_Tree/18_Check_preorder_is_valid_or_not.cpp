// This is not the actual code for this problem.

unordered_map<int, int> mp;
int idx = 0;

Node* formTree(int in[], int lo, int hi){
    if(lo > hi){
        return NULL;
    }
    
    Node* temp;
    for(int k=lo; k<=hi; k++){
        if(mp[in[k]] == idx){
            temp = newNode(in[k]); idx++;
            temp->left = formTree(in, lo, k-1);
            temp->right = formTree(in, k+1, hi);
        }
    }
    
    return temp;
}


Node* post_order(int pre[], int size){
    
    int in[size];
    
    idx = 0;
    mp.clear();
    
    for(int i=0; i<size; i++){
        mp[pre[i]] = i;
        in[i] = pre[i];
    }
    
    sort(in, in+size);
    return formTree(in, 0, size-1);
}


