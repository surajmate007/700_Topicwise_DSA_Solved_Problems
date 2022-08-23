// simple recursive solution:

bool getAns(Node* root1, Node* root2){
    if(root1==NULL and root2==NULL){
        return true;
    }
    if(root1==NULL or root2==NULL){
        return false;
    }
    
    bool ans1 = getAns(root1->left, root2->right);
    bool ans2 = getAns(root1->right, root2->left);
    
    return ans1 and ans2;
}

bool IsFoldable(Node* root){
    if(root == NULL){
        return true;
    }
    
    return getAns(root->left, root->right);
}
