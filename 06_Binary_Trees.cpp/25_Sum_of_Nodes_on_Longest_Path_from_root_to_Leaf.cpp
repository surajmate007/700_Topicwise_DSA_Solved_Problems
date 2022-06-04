// This is the simple approach for this problem.
// we are using backtracking based solution where we are first moving to the leaf nodes and then returning the sum as well as the updated level.

class Solution{
public:

    vector<int> getSum(Node* root){
        if(root == NULL){
            return {0,0};
        }
        
        vector<int> l = getSum(root->left);
        vector<int> r = getSum(root->right);
        
        if(l[0] > r[0]){
            return {l[0]+1, l[1] + root->data};
        }
        else if(l[0] < r[0]){
            return {r[0]+1, r[1] + root->data};
        }
        else{
            return {l[0]+1, max(l[1], r[1]) + root->data};
        }
    }
    
    
    int sumOfLongRootToLeafPath(Node *root){
        vector<int> ans = getSum(root);
        return ans[1];
    }
};
