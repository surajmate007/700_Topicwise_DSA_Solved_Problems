// This is the simple solution.

int getSum(TreeNode<int>* root, int& ans){
    if(root == NULL){
        return 0;
    }
    
    int l = getSum(root->left, ans);
    int r = getSum(root->right, ans);
    
    int sum = l + r + root->data;
    ans = max(ans , sum);

    return sum;
}

int largestSubtreeSum(TreeNode<int> *root) {
	  if(root == NULL){
        return 0;
    }
    
    int ans = INT_MIN;
    
    getSum(root, ans);

    return ans;
}
