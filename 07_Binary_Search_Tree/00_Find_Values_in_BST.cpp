// Simple code for searching the node
// It is brute force approach without using BST property.

bool flag;
void findval(Node* root, int x){
    if(root == NULL){
        return;
    }
    
    if(root->data == x){
        flag = true;
        return;
    }
    
    findval(root->left, x);
    findval(root->right, x);
    
    return;
}

bool search(Node* root, int x) {
    flag = false;
    findval(root, x);
    return flag;
}



// Uisng properties of BST.

// Function to search a node in BST.
bool flag;
void findval(Node* root, int x){
    if(root == NULL){
        return;
    }
    
    if(root->data == x){
        flag = true;
        return;
    }
    
    if(root->data > x){
        findval(root->left, x);
    }
    else{
        findval(root->right, x);
    }
    
    return;
}

bool search(Node* root, int x) {
    flag = false;
    findval(root, x);
    return flag;
}
