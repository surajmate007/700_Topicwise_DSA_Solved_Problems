// Recursive function to perform preorder traversal on the tree
void preorder(Node* root){
    // if the current node is empty
    if (root == nullptr) {
        return;
    }

    // Display the data part of the root (or current node)
    cout << root->data << " ";

    // Traverse the left subtree
    preorder(root->left);

    // Traverse the right subtree
    preorder(root->right);
}


// Iterative solution using stack:

class Solution {
public:
  
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            TreeNode* curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            
            if(curr->right){
                st.push(curr->right);
            }
            
            if(curr->left){
                st.push(curr->left);
            }
        }
        
        return ans;
    }
};
