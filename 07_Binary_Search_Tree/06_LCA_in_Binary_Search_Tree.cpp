// this is the same code from Binary trees.

Node* LCA(Node *root, int n1, int n2){
   if(root == NULL){
       return NULL;
   }
       
   if(root->data == n1 or root->data == n2){
       return root;
   }
   
   Node* l = LCA(root->left, n1, n2);
   Node* r = LCA(root->right, n1, n2);
   
   if(l and r){
       return root;
   }
   
   if(l){
       return l;
   }
   
   if(r){
       return r;
   }
   
}


// Code from reference github profile.

Node* LCA(Node *root, int n1, int n2){
    if(root == NULL){
        return NULL;
    }
    
    // If both n1 and n2 are smaller
    // than root, then LCA lies in left 
  
    if (root->data > n1 && root->data > n2)
        return LCA(root->left, n1, n2);

    // If both n1 and n2 are greater than 
    // root, then LCA lies in right 
  
    if (root->data < n1 && root->data < n2)
        return LCA(root->right, n1, n2);

    return root;  
   
}


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    iterative solution
    TC: O(H), H is the height of the tree
*/
struct node* lca(struct node* root, int n1, int n2){
    while (root != NULL){
        // If both n1 and n2 are smaller than root,
        // then LCA lies in left
      
        if (root->data > n1 && root->data > n2)
            root = root->left;

            // If both n1 and n2 are greater than root, 
            // then LCA lies in right
      
        else if (root->data < n1 && root->data < n2)
            root = root->right;

        else break;
    }
    return root;
}
