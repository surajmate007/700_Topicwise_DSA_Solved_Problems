// we are using modification of inorder traversal.

class Solution{
    public: 
    //Function to convert binary tree to doubly linked list and return it.
    Node *head, *prev;
   
   void helper(Node *node){
       if(!node) return;
       
       helper(node->left);
       
       if(!head){
           head = prev = node;
           node->left = nullptr;
       }
       
       else{
           prev->right = node;
           node->left = prev;
           prev = node;
       }
       
       helper(node->right);
   }
   
   Node * bToDLL(Node *root){
       head = prev = nullptr;
       helper(root);
       return (head);
   }
};
