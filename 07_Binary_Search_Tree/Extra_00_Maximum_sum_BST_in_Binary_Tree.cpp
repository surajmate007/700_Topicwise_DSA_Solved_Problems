// Brute force approach but giving TLE.

class Solution {
public:
    long long ans = 0;
    
    bool Validate(TreeNode* root, int lo, int hi, int& sum){
        if(root == NULL){
            return true;
        }
        
        if(root->val <= lo or root->val >= hi){
            return false;
        }
        
        sum += root->val;
        
        bool l = Validate(root->left, lo, root->val, sum);
        
        bool r = Validate(root->right, root->val, hi, sum);
        
        return l and r;
    }
    
    void caller(TreeNode* root){
        if(root == NULL){
            return;
        }
        
        int sum = 0;
        bool b = Validate(root, INT_MIN, INT_MAX, sum);
        
        if(b){
            ans = max(ans, (long long)sum);
        }
        
        caller(root->left);
        
        caller(root->right);
    }
    
    int maxSumBST(TreeNode* root) {
        ans = 0;
        
        caller(root);
        
        return (int)ans;
    }
};


// More optimised approach.

class NodeValue {
public : int maxNode, minNode, maxSize;

    NodeValue(int minNode, int maxNode, int maxSize){
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
    
};

class Solution {
public:
    int ans = 0;
    NodeValue helper(TreeNode* root){
        if(root == NULL) return NodeValue(INT_MAX, INT_MIN, 0);
        
        auto left = helper(root->left);
        auto right = helper(root->right);
            
        if (left.maxNode < root->val && root->val < right.minNode) {
            int curr_sum = left.maxSize + right.maxSize + root->val;
            ans = max(ans, curr_sum);
            return NodeValue(min(root->val, left.minNode), max(root->val, right.maxNode), curr_sum);
        }
        
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    
    int maxSumBST(TreeNode* root) {
        helper(root);
        return ans;
    }
};
