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


// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using recursion
    TC: O(log N)
*/
// C++ function to search a given key in a given BST
Node* search(Node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->key == key)
        return root;

        // Key is greater than root's key
    if (root->key < key)
        return search(root->right, key);

        // Key is smaller than root's key
    return search(root->left, key);
}




// ----------------------------------------------------------------------------------------------------------------------- //
/*
    insert a node in BST
    TC: O(log N)    // if its not skewed tree
        O(N)        // it skewed tree
*/
// Insert function definition.
Node* Insert(Node* root, int key)
{
    if (!root)
    {
        // Insert the first node, if root is NULL.
        return new Node(key);
    }

    // Insert data.
    if (key > root->data)
    {
        // Insert right node data, if the 'key'
        // to be inserted is greater than 'root' node data.

        // Process right nodes.
        root->right = Insert(root->right, key);
    }
    else
    {
        // Insert left node data, if the 'key'
        // to be inserted is greater than 'root' node data.

        // Process left nodes.
        root->left = Insert(root->left, key);
    }
    // Return 'root' node, after insertion.
    return root;
}





// ----------------------------------------------------------------------------------------------------------------------- //
/*
    using iteration
    TC: O(log N) not skewed
        O(N) for skewed
*/
void insert(Node* root, int key) {
    Node* node = new Node(key);
    if (root == null) {
        root = node;
        return;
    }


    Node prev = null;
    Node temp = root;
    while (temp != null) {
        if (temp.val > key) {
            prev = temp;
            temp = temp->left;
        }
        else if (temp.val < key) {
            prev = temp;
            temp = temp->right;
        }
    }

    if (prev->val > key) prev->left = node;
    else prev->right = node;
}
