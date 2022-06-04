// we are simply using pick or not pick approach.
// This is dynamic programming problem.

class Solution{
  public:
  unordered_map<Node*, int> dp;
  
  int getsum(Node* root){
      if(root == NULL){
          return 0;
      }
      
      if(dp[root]){
          return dp[root];
      }
      
      int include = root->data;
      if(root->left){
          include += getsum(root->left->left);
          include += getsum(root->left->right);
      }
      if(root->right){
          include += getsum(root->right->right);
          include += getsum(root->right->left);
      }
      
      int exclude = getsum(root->left) + getsum(root->right);
      
      dp[root] = max(include, exclude);
      return dp[root];
      
  }
    
    int getMaxSum(Node *root) {
        return getsum(root);
        
    }
};
