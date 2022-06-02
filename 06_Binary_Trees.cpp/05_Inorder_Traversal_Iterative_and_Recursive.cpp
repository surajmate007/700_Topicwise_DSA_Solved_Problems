

// Recursive function to perform inorder traversal on the tree
void inorder(Node* root){
    // return if the current node is empty
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    inorder(root->left);

    // Display the data part of the root (or current node)
    cout << root->data << " ";

    // Traverse the right subtree
    inorder(root->right);
}



// Iterative approach:

class Solution {
public:

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        stack<TreeNode*> st;
        
        while(!st.empty() or root != NULL){
            while(root != NULL){
                st.push(root);
                root = root->left;
            }
            root = st.top();
            ans.push_back(root->val);
            st.pop();
            root = root->right;
        }
        return ans;
    }
};
