// Easy solution using simple level order traversal. 

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int mx = INT_MIN;
            int n = q.size();
            while(n--){
                TreeNode* nd = q.front();
                if(nd->left){
                    q.push(nd->left);
                }
                if(nd->right){
                    q.push(nd->right);
                }
                mx = max(mx, nd->val);
                q.pop();
            }
            ans.push_back(mx);
        }
        
        return ans;
    }
};
