// This is the brute force approach where we are first creating the inorder traversal of the tree and then poulating the successors
// of all thr adjacent nodes in the vector.

class Solution{
public:
    
    void fill(Node* root, vector<Node*>& vec){
        if(root == NULL){
            return;
        }
        
        fill(root->left, vec);
        vec.push_back(root);
        fill(root->right, vec);
    }
    
    
    void populateNext(Node *root){
        if(root == NULL){
            return;
        }
        vector<Node*> vec;
        fill(root, vec);
        int n = vec.size();
        for(int i=0; i<n-1; i++){
            vec[i]->next = vec[i+1];
        }
    }
};


// Best solution using inorder tarversal:

class Solution{
public:
    Node* prev = NULL;
    
    void populateNext(Node *root){
        if(root == NULL){
            return;
        }
        
        populateNext(root->left);
        
        if(prev == NULL){
            prev = root;
        }
        
        else{
            prev->next = root;
            prev = root;
        }
        
        populateNext(root->right);
    }
};
