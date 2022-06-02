//  In order to change the original tree in its mirror tree, then we simply swap the left and right link of each node.
//  If the node is leaf node then do nothing.

// Function to convert to  mirror tree
treenode* mirrorTree(node* root){
    // Base Case
    if (root == NULL){
        return root;
    }
  
    node* temp = root->left;
    root->left = root->right;
    root->right = temp;
 
    if (root->left)
        mirrorTree(root->left);
    if (root->right)
        mirrorTree(root->right);
   
  return root;
}


// Approach: Write a recursive function that will take two nodes as the argument, one of the original tree and the other of the newly 
// created tree. Now, for every passed node of the original tree, create a corresponding node in the mirror tree and then recursively call
// the same method for the child nodes but passing the left child of the original tree node with the right child of the mirror tree node and
// the right child of the original tree node with the left child of the mirror tree node.



// Helper function that allocates a new node with the
// given data and NULL left and right pointers
node* createNode(int val)
{
    node* newNode = new node();
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// mirrorify function takes two trees, original tree and a mirror tree It recurses on both the trees, but when original tree recurses on left,
// mirror tree recurses on right and vice-versa.

void mirrorify(node* root, node** mirror){
    if (root == NULL){
        mirror = NULL;
        return;
    }
 
    // Create new mirror node from original tree node
    node* mirror = createNode(root->val);
    mirrorify(root->left, &((*mirror)->right));
    mirrorify(root->right, &((*mirror)->left));
}
