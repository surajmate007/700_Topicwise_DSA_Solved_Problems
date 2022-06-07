// Code written by me.
// Very intuitive recursive calls.

class Solution{
    public:
    Node* ans = NULL;
    void findNode(Node* root, int& k){
        if(root == NULL){
            return;
        }
        
        findNode(root->right, k);
        k = k-1;
        
        if(k==0){
            ans = root;
        }
        
        findNode(root->left, k);
    }
    
    int kthLargest(Node *root, int K){
        if(root == NULL){
            return -1;
        }
        ans = NULL;
        
        findNode(root, K);
        
        return ans->data;
    }
};
