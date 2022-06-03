// solved by me.
// good recursive approach.

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    int convert(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int l = convert(root->left);
        int r = convert(root->right);
        
        int val = root->data;
        root->data = l + r;
        return val + root->data;
    }
    
    void toSumTree(Node *node){
        if(node == NULL){
            return;
        }
        
        convert(node);
    }
};
