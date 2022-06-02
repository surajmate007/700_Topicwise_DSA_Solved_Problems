// easy recursive approach to find the diameter of a tree.

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter+1;
    }

  private:
    int height(Node* root, int& diameter){
        if(root == NULL){
            return 0;
        }
        
        int lh = height(root->left, diameter);
        int rh = height(root->right, diameter);
        
        diameter = max(diameter, lh+rh);
        return 1 + max(lh, rh);
    }
    
};
