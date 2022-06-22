// Simple solution using properties of binary tree.
// returning the pair where first element represents the value of the noe and the second element represents the heght of the node.
// For the tree to be haep 2 properties should be followed. 
// 1. It should be complete binary tree.
// 2. The value of odes should be less than its root node.


class Solution {
  public:
  bool flag = true;
  
    pair<int, int> getAns(struct Node* root){
        if(root == NULL){
            return {0, 0};
        }
        
        pair<int, int> l = getAns(root->left);
        pair<int, int> r = getAns(root->right);
        
        if(l.first >= root->data or r.first >= root->data){
            flag = false;
        }
        
        if(l.second < r.second){
            flag = false;
        }
        
        return {root->data, max(l.second, r.second)+1};
    }
  
  
    bool isHeap(struct Node* tree) {
        getAns(tree);
        
        return flag;
    }
};
