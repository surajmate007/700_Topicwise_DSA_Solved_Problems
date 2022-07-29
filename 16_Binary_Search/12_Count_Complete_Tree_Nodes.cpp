// We argiven complete binary tree we have to count the number of tree nodes into the tree using less than O(n) complexity.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
  
    int goLeft(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        return 1 + goLeft(root->left);
    }
    
    int goRight(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        return 1 + goRight(root->right);
    }
    
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        
        int val1 = goLeft(root); int val2 = goRight(root);
        int count = 0;
        
        if(val1 == val2){
            count = pow(2, val1) - 1;
        }
        
        else{
            int cnt1 = countNodes(root->left);
            int cnt2 = countNodes(root->right);
            count = cnt1 + cnt2 + 1;
        }
        
        return count;
    }
};
