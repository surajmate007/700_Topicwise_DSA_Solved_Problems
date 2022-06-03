// we are simply using divide and conquer approach.
// understood from this video : https: //www.youtube.com/watch?v=aZNaLrVebKQ

// Coded by me

class Solution{
    public:
    unordered_map<int, int> mp;
    int idx = 0;
    
    Node* construct(int in[], int i, int j){
        
        if(i>j){
            return NULL;
        }
        
        Node* root;
        for(int k=i; k<=j; k++){
            if(mp[in[k]] == idx){
                root = new Node(in[k]);
                idx++;
                root->left = construct(in, i, k-1);
                root->right = construct(in, k+1, j);
            }
        }
        
        return root; 
    }
    
    Node* buildTree(int in[],int pre[], int n){
        for(int i=0; i<n; i++){
            mp[pre[i]] = i;
        }
        
        Node* head = construct(in, 0, n-1);
        return head;
    }
};
