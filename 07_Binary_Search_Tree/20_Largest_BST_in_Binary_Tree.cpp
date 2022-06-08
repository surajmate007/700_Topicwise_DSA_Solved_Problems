// This is the brute force approach for this problem.
// TC = O(n2) 

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    bool validateBST(Node* root, int lo, int hi){
        if(root == NULL){
            return true;
        }
        
        if(root->data <= lo or root->data >= hi){
            return false;
        }
        
        bool l = validateBST(root->left, lo, root->data);
        bool r = validateBST(root->right, root->data, hi);
        
        return l and r;
    }
    
    int getLen(Node* root){
        if(root == NULL){
            return 0;
        }
        
        int l = getLen(root->left);
        int r = getLen(root->right);
        
        return l + r + 1;
    }
    
    void caller(Node* root, int& len){
        if(root == NULL){
    	    return;
    	}
    	
    	caller(root->left, len);
    	
    	bool isBST = validateBST(root, INT_MIN, INT_MAX);
    	if(isBST){
    	    len = max(len, getLen(root));
    	   // cout<<root->data<<" "<<len<<endl;
    	}
    	
    	caller(root->right, len);
    }
    
    int largestBst(Node *root){
        if(root == NULL){
            return 0;
        }
        
    	int ans = 0;
    	caller(root, ans);
    	
    	return ans;
    }
};






class NodeValue{
    public:
    int maxNd; int minNd; int maxSz;
    NodeValue(int maxNd, int minNd, int maxSz){
        this->maxNd = maxNd;
        this->minNd = minNd;
        this->maxSz = maxSz;
    }
};


//  This is themost optimised code having O(n) TC.

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    
    NodeValue helper(Node* root){
        //An empty tree is BST of size 0
        if(root == NULL){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        
        // get values from left and right subtree of current tree.
        auto left = helper(root->left);
        auto right = helper(root->right);
        
        // Current node is greater than greater in left and smaler than smaller in right
        if(left.maxNd < root->data and root->data < right.minNd){
            return NodeValue(min(root->data, left.minNd), max(root->data, right.maxNd), left.maxSz + right.maxSz + 1);
        }
        // otherwose return [-INF, INF] so that parent can't be valid BST.
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSz, right.maxSz));
    }
    
    int largestBst(Node *root){
        if(root == NULL){
            return 0;
        }
    
    	return helper(root).maxSz;
    }
};
