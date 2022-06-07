// It is expected to find the median in O(n) time and O(1) space.
// This is the brute force approach for this problem whwere we are first storing all the nodes in vector via inorder traversal and then finding the
// median of sorted array.


void inorder(struct Node* root, vector<int>& vec){
    if(root == NULL){
        return;
    }
    
    inorder(root->left, vec);
    vec.push_back(root->data);
    inorder(root->right, vec);
}


float findMedian(struct Node *root){
    vector<int> vec;
    inorder(root, vec);
    float ans = 0.0;
    int n = vec.size();
    
    if(n % 2){
        return (float)vec[n/2];
    }
    ans = (vec[n/2] + vec[(n/2) - 1])/2.0;
    
    return ans;
}




// This is the most optimised approach for this problem.

void count(struct Node* root, int& cnt){
    if(root == NULL){
        return;
    }
    
    count(root->left, cnt);
    cnt++;
    count(root->right, cnt);
}


void findMed(struct Node* root, Node*& prev, Node*& curr, int k, int& f, int& c){
    if(root == NULL){
        return;
    }
    
    findMed(root->left, prev, curr, k, f, c);
    
    if(prev == 0){
        prev  = root;
        c++;
    }
    
    else if(c == k){
        c++;
        curr = root;
        f = 1;
        return;
    }
    
    else if(f == 0){
        c++;
        prev = root;
    }
    
    findMed(root->right, prev, curr, k, f, c);
}


float findMedian(struct Node *root){
    int cnt = 0;
    count(root, cnt);
    
    Node* prev = NULL; Node* curr = NULL;
    int k = cnt/2 + 1;
    int c = 1; int f = 0;
    findMed(root, prev, curr, k, f, c);
    
    if(cnt%2 ==1){
        return (float)(curr->data);
    }
    
    return (prev->data + curr->data)/2.0;
}
