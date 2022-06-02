// we arew simply using queue data structure to maintain the ortder of elements to be stored.
// TC = O(n)
// SC = O(n)


class Solution{
    public:
    //Function to return the level order traversal of a tree.
    
    vector<int> levelOrder(Node* node){
        queue<Node*> q;
        q.push(node);
        vector<int> ans;
        while(!q.empty()){
            Node* nd = q.front();
            ans.push_back(nd->data);
            q.pop();
            if(nd->left != NULL){
                q.push(nd->left);
            }
            if(nd->right != NULL){
                q.push(nd->right);
            }
        }
        return ans;
    }
};



// Leetcode level order traversal with minor modifications:

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            vector<int>vec; int n = q.size();
            while(n){
                TreeNode* nd = q.front();
                vec.push_back(nd->val);
                q.pop();
                if(nd->left != NULL){
                    q.push(nd->left);
                }
                if(nd->right != NULL){
                    q.push(nd->right);
                }
                n--;
            }
            ans.push_back(vec);
        }
        
        return ans;
    }
};

