// Exactly reverse code of Kth largest element.


class Solution {
  public:
    // Return the Kth smallest element in the given BST
    Node* ans = NULL;
    
    void findNode(Node* root, int& k){
        if(root == NULL){
            return;
        }
        
        findNode(root->left, k);
        k = k-1;
        
        if(k == 0){
            ans = root;
        }
        
        findNode(root->right, k);
        
    }
    
    int KthSmallestElement(Node *root, int K) {
        if(root == NULL){
            return -1;
        }
        
        ans = NULL;
        findNode(root, K);
        
        if(ans == NULL){
            return -1;
        }
        
        return ans->data;
    }
};
