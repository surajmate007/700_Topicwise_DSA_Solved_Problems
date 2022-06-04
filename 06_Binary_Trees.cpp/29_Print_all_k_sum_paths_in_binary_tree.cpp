// very intuitive solution. we are first storing all the paths into the vector and then traversing the vector from back and keep on 
// adding vector entries. If the sum becomes equal to target then we are incrementing the answer value.

class Solution {
public:
    int t = 0;
    vector<int> res;
    int mod = 1e9+7;
    
    void sol(TreeNode* root,int k){
        if(root==NULL){
            return ;
        }
        res.push_back(root->val);
        sol(root->left,k);
        sol(root->right,k);
        int f =0;
        for(int i=res.size()-1;i>=0;i--){
            f = (f + res[i]%mod)%mod;
            if(f==k){
                t++;
            }
        }
        res.pop_back();
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        sol(root,targetSum);
        return t;
    }
};
