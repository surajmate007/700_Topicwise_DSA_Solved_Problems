

// Recursive function to perform postorder traversal on the tree
void postorder(Node* root){
    // if the current node is empty
    if (root == nullptr) {
        return;
    }

    // Traverse the left subtree
    postorder(root->left);

    // Traverse the right subtree
    postorder(root->right);

    // Display the data part of the root (or current node)
    cout << root->data << " ";
}


// Iterative apporach using 2 stacks:

class Solution {
public:
   
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
       
        stack<TreeNode*> st;
        stack<int> res;
        st.push(root);
        
        while(!st.epmpty()){
            Node* root = st.top();
            st.pop();
            res.push(root->val);
            
            if(root->left){
                st.push(root->left);
            }
            
            if(root->right){
                st.push(root->right);
            }
        }
        
        while(!res.empty()){
            ans.push_back(res.top());
            res.pop();
        }
    
        return ans;
    }
};
