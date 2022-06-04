// we are using unordered_map and stroing all the strings that can be made out of the tree traversal

class Solution {
  public:
  
    
    unordered_map<string, int>m;
    
    string formSubtree(Node*root){
       if(root==NULL){
           return "$";
       }
       
       string s="";
       if(root->right==NULL && root->left==NULL){
           s = to_string(root->data);
           return s;
       }
       
       s= s + to_string(root->data);
       s= s + formSubtree(root->left);
       s= s + formSubtree(root->right);
       m[s]++;
       return s;
   }
   
   int dupSub(Node *root) {
        // code here
        formSubtree(root);
        for(auto x : m){
            if(x.second>=2){
                return true;
            }
        }
        return false;
   }
};
