// We are first computing the right height and then left height of the node and then finding the difference.
// iF THE DIFFERENCE ENCOUNTERED SO FAR IS GRATER THAN 1 THEN WE WILL RETURN -1.

class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    int check(Node* root){
        if(root == NULL){
            return 0;
        } 
        
        int lh = check(root->left);
        int rh = check(root->right);
        
        if(lh == -1 or rh == -1){
            return -1;
        }
        
        if(abs(rh-lh) > 1){
            return -1;
        }
        
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(Node *root){
        int ans = check(root);
        if(ans == -1){
            return false;
        }
        
        return true;
    }
};



// More easy nad intuitive code:


class Solution{
    public:
    //Function to check whether a binary tree is balanced or not.
    bool flag = true;
    
    int check(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int lh = check(root->left);
        int rh = check(root->right);
        
        if(abs(rh-lh) > 1){
            flag = false;
        }
        
        return max(lh, rh) + 1;
    }
    
    bool isBalanced(Node *root){
        check(root);
        return flag;
    }
};
