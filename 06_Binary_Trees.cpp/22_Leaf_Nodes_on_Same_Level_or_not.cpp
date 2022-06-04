// Here also the approach is simple.
// we are setting left and right to 0. If the left and right is not equal to zero then the values are returned from the leaf nodes.
// we have to check whether these returned values are same or not.

class Solution{
  public:
    bool flag = true;
    
    int checkLevel(Node* root){
        if(root->left == NULL and root->right == NULL){
            return 1;
        }
        
        int l = 0, r = 0;
        
        if(root->left){
            l = checkLevel(root->left);
        }
        
        if(root->right){
            r = checkLevel(root->right);
        }
        
        if(l!=0 and r!=0 and l!=r){
            flag = false;
        }
        
        return max(l,r) + 1;
    }
    
    bool check(Node *root){
        if(root == NULL){
            return flag;
        }
        
        int val = checkLevel(root);
        
        return flag;
    }
};
