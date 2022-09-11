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



// Construct binary tree from postorder and inorder traversal:

class Solution {
public:
    
    int idx = 0; 
    unordered_map<int, int> mp;
    
    TreeNode* formTree(vector<int>& post, int lo, int hi){
        if(lo > hi){
            return NULL;
        }
        
        int p = mp[post[idx]];
        TreeNode* nd = new TreeNode(post[idx]);
        
        idx++;
        nd->right = formTree(post, p+1, hi);
        nd->left = formTree(post, lo, p-1);
        
        return nd;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        mp.clear(); idx = 0;
        int n = inorder.size();
        
        for(int i=0; i<n; i++){
            mp[inorder[i]] = i;
        }
        reverse(postorder.begin(), postorder.end());
        
        return formTree(postorder, 0, n-1);
    }
};
