// Here the logic is simple:
// If the node for which we have to find these values exist in the tree and node has both left and right childs then we know
// Pred = one_left + extreme_right.   and      Succ = one_right + extreme_left.
// if left and right are not present then we will keep on updating the pred and succ values when we are traversing the tree.
// This second solution also helps to find the pred and suc of those values which are not even present in the tree.


void getPred(Node* root, Node*& pre){
    while(root->right){
        root = root->right;
    }
    pre = root;
}

void getSucc(Node* root, Node*& suc){
    while(root->left){
        root = root->left;
    }
    suc = root;
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
    if(root == NULL){
        return;
    }
    
    if(root->key == key){
        if(root->left){
            getPred(root->left, pre);
        }
        if(root->right){
            getSucc(root->right, suc);
        }
        return;
    }
    
    if(key < root->key){
        suc = root;
        return findPreSuc(root->left, pre, suc, key);
    }
    
    if(key > root->key){
        pre = root;
        return findPreSuc(root->right, pre, suc, key);
    }
    
    return;
}
