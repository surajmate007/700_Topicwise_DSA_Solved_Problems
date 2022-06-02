// we simply solved the problem using queue but at last reversed the array.

vector<int> reverseLevelOrder(Node *root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }
    
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* nd = q.front();
        ans.push_back(nd->data);
        
        if(nd->right != NULL){
            q.push(nd->right);
        }
        if(nd->left != NULL){
            q.push(nd->left);
        }
        q.pop();
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}



// letcode problem with minor modifications.

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<int> vec; int n = q.size();
            while(n){
                TreeNode* nd = q.front();
                vec.push_back(nd->val);
                if(nd->left != NULL){
                    q.push(nd->left);
                }
                if(nd->right != NULL){
                    q.push(nd->right);
                }
                q.pop();
                n--;
            }
            ans.push_back(vec);
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
