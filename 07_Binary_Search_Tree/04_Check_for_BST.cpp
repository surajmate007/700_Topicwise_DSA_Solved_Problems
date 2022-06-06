// The solution approach is simple we are hust maintaining the left and right limit for each node and checking whether the value is lying
// in the same range or not.


bool getans(Node* root, int mn, int mx){
        if(root == NULL){
            return true;
        }
        
        if(root->data <= mn or root->data >= mx){
            return false;
        }

        bool l = getans(root->left, mn, root->data);
        bool r = getans(root->right, root->data, mx);
        
        return l and r;
}
    
bool isBST(Node* root) {
    if(root == NULL){
        return true;
    }
    return getans(root, INT_MIN, INT_MAX);
}
