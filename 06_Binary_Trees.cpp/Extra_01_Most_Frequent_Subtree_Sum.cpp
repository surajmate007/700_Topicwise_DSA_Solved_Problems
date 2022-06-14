// Finding the sum of the subtrees and storing them into map with their frequency.
// Then loading the most frequent sum into the ans vector.

// Leetcode problem no : 508

class Solution {
public:
    unordered_map<int, int> mp;
    int hf = 0;
    
    int getAns(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        int l = getAns(root->left);
        int r = getAns(root->right);
        
        int sum = l + r + root->val;
        
        mp[sum]++;
        hf = max(hf, mp[sum]);
        
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        if(root == NULL){
            return ans;
        }
        
        mp.clear();
        hf = 0;
        
        getAns(root);
        
        for(auto e : mp){
            if(e.second == hf){
                ans.push_back(e.first);
            }
        }
        
        return ans;
    }
};
