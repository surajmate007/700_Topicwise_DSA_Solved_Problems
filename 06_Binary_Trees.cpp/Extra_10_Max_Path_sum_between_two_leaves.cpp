// O(n^2) solution:

long long ans = -1;

long long getAns(TreeNode<int> *root){
    if(root == NULL){
        return 0;
    }
    
    long long l = getAns(root->left);
    long long r = getAns(root->right);
    
    return max(l, r) + root->val;
}

long long findSum(TreeNode<int>* root){
    if(root == NULL){
        return -1;
    }
    
    if(!root->left or !root->right){
        return -1;
    }
    
    long long leftans = getAns(root->left);
    long long rightans = getAns(root->right);
    
    return leftans + rightans + root->val;
}

void allNodes(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    
    allNodes(root->left);
    ans = max(ans, findSum(root));
    allNodes(root->right);
}

long long int findMaxSumPath(TreeNode<int> *root){
    ans = -1;
    allNodes(root);
    return ans;
}
