// This is brute force approach where we are not changing the nodes but we are only changing the values of the nodes.

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    vector<Node*> vec;
    vector<int> val;
    
    void inorder(Node* root){
        if(root == NULL){
            return;
        }
        
        inorder(root->left);
        vec.push_back(root);
        val.push_back(root->data);
        inorder(root->right);
    }
    
    
    Node *binaryTreeToBST (Node *root){
        if(root == NULL){
            return NULL;
        }
        vec.clear(); val.clear();
        inorder(root);
        sort(val.begin(), val.end());
        
        for(int i=0; i<vec.size(); i++){
            vec[i]->data = val[i];
        }
        
        return root;
    }
};



// Another similar solution.

class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    
    void helper(Node *root, vector<int> &v){
       if(!root)
           return;
       v.push_back(root->data);
       helper(root->left,v);
       helper(root->right,v);
   }
   
   
   void h(Node *&root, vector<int> &v, int &i){
       if(!root)
           return;
       h(root->left,v,i);
       root->data = v[i++];
       h(root->right,v,i);
   }
   
   
   Node *binaryTreeToBST (Node *root){
       //Your code goes here
       vector<int> v;
       helper(root,v);
       int i=0;
       sort(v.begin(),v.end());
       h(root,v,i);
       return root;
   }
   
};
