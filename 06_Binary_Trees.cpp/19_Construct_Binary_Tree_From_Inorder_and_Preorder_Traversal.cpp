// we are simply using divide and conquer approach.
// understood from this video : https: //www.youtube.com/watch?v=aZNaLrVebKQ

// Coded by me.
// More optimal than previous no for loop.

class Solution {
public:
    unordered_map<int, int> mp;
    int idx = 0;
    
    TreeNode* formTree(vector<int>& pre, int lo, int hi){
        if(lo > hi){
            return NULL;
        }
        
        int p = mp[pre[idx]];
        TreeNode* nd = new TreeNode(pre[idx]);
        
        idx++;
        nd->left = formTree(pre, lo, p-1);
        nd->right = formTree(pre, p+1, hi);
        
        return nd;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        mp.clear(); idx = 0;
        int n = inorder.size();
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        
        return formTree(preorder, 0, n-1);
    }
};
