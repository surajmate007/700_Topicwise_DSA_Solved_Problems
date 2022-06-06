// More intuitive code by striver.
// 1. First we are finding the node to be deleted.
// 2. After finding the node then we are simply attaching the left subtree of the node to the parent of the node to be deleted.
// 3. After attaching the left subtree we are then attacing the right subtree of that node to the extreme right position of the node
// of the attached left subtree. 


class Solution {
public:
    
    TreeNode* findlast(TreeNode* root){
        while(root->right){
            root = root->right;
        }
        return root;
    }
    
    TreeNode* helper(TreeNode* root){
        if(!root->left){
            return root->right;
        }
        else if(!root->right){
            return root->left;
        }
        TreeNode* rightchild = root->right;
        TreeNode* lastRight = findlast(root->left);
        lastRight->right = rightchild;
        
        return root->left;
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL){
            return NULL;
        }
        
        if(root->val == key){
            return helper(root);
        }
        
        TreeNode* dummy = root;
        
        while(root){
            if(root->val > key){
                if(root->left and root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                if(root->right and root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        
        return dummy;
    }
};






/*
    link: https://leetcode.com/problems/delete-node-in-a-bst/
    video: https://youtu.be/5_AZcOOc-kM
*/




// ----------------------------------------------------------------------------------------------------------------------- //
// Code from reference github profile.

TreeNode* deleteNode(TreeNode* root, int key) {
    // base case
    if (!root) return NULL;

    // if value of root matches with the key
    if (root->val == key) {

        // if there is no right child then simply attach root's parent with root's child
        if (!root->right) {
            TreeNode* left = root->left;
            delete root;
            return left;
        }
        // if there is no left child then simply attach root's parent with root's child
        else if (!root->left) {
            TreeNode* right = root->right;
            delete root;
            return right;
        }
        // then swap with the right-subtrees' smallest child with curr-value, also BST won't change (trace it!)
        // alternative way we can also swap left-subtrees' greatest child with curr-value, still BST won't change
        else {
            TreeNode* right = root->right;
            while (right->left) {
                right = right->left;
            }
            swap(root->val, right->val);
        }
    }

    // get deleted and arranged root from the recursion
    root->left = deleteNode(root->left, key);
    root->right = deleteNode(root->right, key);
    return root;
}


