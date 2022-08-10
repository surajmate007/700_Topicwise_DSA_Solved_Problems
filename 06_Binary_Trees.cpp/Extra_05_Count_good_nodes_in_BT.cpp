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
    
    int getAns(TreeNode* root, int msf){
        if(root == NULL){
            return 0;
        }
        
        long long ans = 0;
        if(root->val >= msf){
            ans = 1 + getAns(root->left, root->val) + getAns(root->right, root->val);
        }
        else{
            ans = getAns(root->left, msf) + getAns(root->right, msf);
        }
        
        return (int)ans;
    }
    
    int goodNodes(TreeNode* root) {
        return getAns(root, root->val);
    }
};
