// Recursive code to find the height of a tree. Written by me.

class Solution{
    public:
    int height(struct Node* node){
        
        int ans = 1;
        if(node == NULL){
            return 0;
        }
        
        ans += max(height(node->left), height(node->right));
        
        return ans;
    }
};



// Some modifications in recursive code. 

class Solution{
    public:
    int height(struct Node* node){
        
        if(node == NULL){
            return 0;
        }
        
        return max(height(node->left), height(node->right)) + 1;
    }

};
