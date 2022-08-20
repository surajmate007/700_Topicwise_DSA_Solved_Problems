class Solution {
public:
    
    int widthOfBinaryTree(TreeNode* root) {
        int ans = 0;
        if(root == NULL) return 0;
        queue<pair<TreeNode* , int>> q;
        q.push({root,0});
        while(!q.empty()){
            int min = q.front().second;
            int size = q.size();
            int last,first;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                int idx = q.front().second - min;
                q.pop();
                if(i == 0) first = idx;
                if(i == size - 1) last = idx;
                if(node->left){
                    q.push({node->left,(long long)2*idx + 1});
                }
                if(node->right){
                    q.push({node->right,(long long)2*idx + 2});
                }
                ans = max(ans, (last - first + 1));
            }
        }
        
        return ans;
    }
};
