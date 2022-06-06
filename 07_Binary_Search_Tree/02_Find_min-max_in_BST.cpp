// We can find the min value \at the extreme left of the binary tree.

int minValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    
    while(root->left){
        root = root->left;
    }
    return root->data;
}


// Similarly we can find the max value at the extreme right of the binary search tree.


// Function to find the maxmimum element in the given BST.
int minValue(Node* root) {
    if(root == NULL){
        return -1;
    }
    
    while(root->right){
        root = root->right;
    }
    return root->data;
}
