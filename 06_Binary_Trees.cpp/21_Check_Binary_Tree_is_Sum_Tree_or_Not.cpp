// The approach is simple we are first defining one global boolean variable and then settin git to false when the sum of any nod in between is not 
// equal to the required sum.

class Solution{
    public:
    
    bool flag = true;
    
    int isEqual(Node* root){
        
        if(root == NULL){
            return 0;
        }
        
        if(root->left == NULL and root->right == NULL){
            return root->data;
        }
        
        int l = isEqual(root->left);
        int r = isEqual(root->right);
        
        int sum = l + r;
        
        if(root->data != sum){
            flag = false;
        }
        
        return sum + root->data;
    }
    
    bool isSumTree(Node* root){
        
         if(root == NULL){
             return true;
         }
         
         int val = isEqual(root);

         return flag;
    }
    
};
