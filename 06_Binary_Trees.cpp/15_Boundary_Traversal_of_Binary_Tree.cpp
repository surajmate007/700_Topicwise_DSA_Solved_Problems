// There are three steps for this program:
// 1. Visit left side nodes without leaf nodes.
// 2. Visit only leaf nodes using inorder traversal.
// 3. Visit right side in reverse order (used stack) for this without leaf nodes.

class Solution {
public:
    
    void leftbnd(Node* root, vector<int>& ans){
        if(root->left == NULL){
            ans.push_back(root->data);
            return;
        }
        
        while(root->left != NULL or root->right != NULL){
            ans.push_back(root->data);
            if(root->left){
                root = root->left;
            }
            else if(root->right){
                root = root->right;
            }
        }
    }
    
    void rightbnd(Node* root, vector<int>& ans){
        
        if(root->right == NULL){
            return;
        }
        
        stack<int> st;
        while(root->left != NULL or root->right != NULL){
            st.push(root->data);
            if(root->right){
                root = root->right;
            }
            else if(root->left){
                root = root->left;
            }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        ans.pop_back();
    }
    
    void leafbnd(Node* root, vector<int>& ans){
        if(root == NULL){
            return;
        }
        
        if(root->left == NULL and root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        
        leafbnd(root->left, ans);
        leafbnd(root->right, ans);
    }
    
    vector <int> boundary(Node *root){
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        if(root->left == NULL and root->right == NULL){
            ans.push_back(root->data);
            return ans;
        }
        
        leftbnd(root, ans);
        
        leafbnd(root, ans);
        
        rightbnd(root, ans);
        
        
        return ans;
    }
};
