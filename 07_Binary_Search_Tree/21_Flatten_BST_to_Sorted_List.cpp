// simple approach of inorder traversal.

void getLL(TreeNode<int>* root, TreeNode<int>*& head, TreeNode<int>*& prev){
    if(root == NULL){
        return;
    }
    
    getLL(root->left, head, prev);
    
    if(head == NULL){
        head = root;
        prev = root;
        head->left =- NULL;
    }
    else{
        prev->right = root;
        root->left = NULL;
        prev = root;
    }
    
    getLL(root->right, head, prev);
}


TreeNode<int>* flatten(TreeNode<int>* root){
    TreeNode<int>* head = NULL; 
    TreeNode<int>* prev = NULL;
    getLL(root, head, prev);
    
    return head;
}

